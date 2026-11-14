// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "cPlayerDefensiveShipsManager.h"
#include <Spore\Simulator\SubSystem\ToolManager.h>

using namespace Simulator;

void Initialize()
{
	cPlayerDefensiveShipsManager* playerDefensiveShipsManager = new cPlayerDefensiveShipsManager();
	cSimulatorSystem::Get()->AddStrategy(playerDefensiveShipsManager, cPlayerDefensiveShipsManager::NOUN_ID);
	ModAPI::AddSimulatorStrategy(playerDefensiveShipsManager, cPlayerDefensiveShipsManager::NOUN_ID);
}

void Dispose()
{
	// This method is called when the game is closing
}

member_detour(GeneratePlanetHighLOD__detour, cSimPlanetHighLOD, void(cPlanet* planet)) {
	void detoured(cPlanet* planet) {
		original_function(this, planet);
		if (!IsSpaceGame() || planet == nullptr || planet->mpPlanetRecord == nullptr || cPlayerDefensiveShipsManager::Get() == nullptr) {
			return;
		}

		uint32_t playerEmpID = GetPlayerEmpireID();
		bool isPlayerPlanet = (planet->GetEmpire() != nullptr && planet->GetEmpire() == GetPlayerEmpire()) ||
		                      (planet->mpPlanetRecord->GetStarRecord() != nullptr && playerEmpID != 0 &&
		                       planet->mpPlanetRecord->GetStarRecord()->mEmpireID == playerEmpID);

		if (isPlayerPlanet) {
			cPlayerDefensiveShipsManager::Get()->ManagePlanetDefenders(planet->mpPlanetRecord.get());
		}
	}
};

// Перехват выстрела активными приборами корабля (Стиратель памяти, Фейерверк, Луч счастья, Песнь Барда)
member_detour(ToolStrategyOnHit__detour, cToolStrategy, bool(cSpaceToolData*, const Math::Vector3&, SpaceToolHit, int)) {
	bool detoured(cSpaceToolData* pTool, const Math::Vector3& position, SpaceToolHit hitType, int unk) {
		bool result = original_function(this, pTool, position, hitType, unk);
		if (IsSpaceGame() && pTool != nullptr && cPlayerDefensiveShipsManager::Get() != nullptr) {
			cPlayerDefensiveShipsManager::Get()->OnPlayerToolUsed(pTool);
		}
		return result;
	}
};

member_detour(ToolStrategyWhileFiring__detour, cToolStrategy, bool(cSpaceToolData*, const Math::Vector3&, int)) {
	bool detoured(cSpaceToolData* pTool, const Math::Vector3& aimPoint, int unk) {
		bool result = original_function(this, pTool, aimPoint, unk);
		if (IsSpaceGame() && pTool != nullptr && cPlayerDefensiveShipsManager::Get() != nullptr) {
			cPlayerDefensiveShipsManager::Get()->OnPlayerToolUsed(pTool);
		}
		return result;
	}
};

void AttachDetours()
{
	GeneratePlanetHighLOD__detour::attach(Address(ModAPI::ChooseAddress(0x00ffa340, 0x00ff96b0)));
	ToolStrategyOnHit__detour::attach(GetAddress(cToolStrategy, OnHit));
	ToolStrategyWhileFiring__detour::attach(GetAddress(cToolStrategy, WhileFiring));
}


// Generally, you don't need to touch any code here
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		ModAPI::AddPostInitFunction(Initialize);
		ModAPI::AddDisposeFunction(Dispose);

		PrepareDetours(hModule);
		AttachDetours();
		CommitDetours();
		break;

	case DLL_PROCESS_DETACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}
