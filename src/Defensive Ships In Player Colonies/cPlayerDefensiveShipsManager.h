#pragma once

#include <Spore\Simulator\Serialization.h>
#include <Spore\BasicIncludes.h>
#include <Spore\Simulator\cCity.h>
#include <EASTL\vector.h>
#include <EASTL\map.h>

#define cPlayerDefensiveShipsManagerPtr intrusive_ptr<cPlayerDefensiveShipsManager>
namespace Simulator {
	class XmlSerializer;
}


class cPlayerDefensiveShipsManager 
	: public Simulator::cStrategy
	, public App::IMessageListener
{
public:
	static const uint32_t TYPE = 0xF5A81B20;
	static const uint32_t NOUN_ID = TYPE;
	cPlayerDefensiveShipsManager();
	~cPlayerDefensiveShipsManager();

	int AddRef() override;
	int Release() override;
	void Initialize() override;
	void Dispose() override;
	const char* GetName() const override;
	bool Write(Simulator::ISerializerStream* stream) override;
	bool Read(Simulator::ISerializerStream* stream) override;
	bool WriteToXML(Simulator::XmlSerializer* xml) override;
	void Update(int deltaTime, int deltaGameTime) override;
	void OnModeEntered(uint32_t previousModeID, uint32_t newModeID) override;
	bool HandleMessage(uint32_t messageID, void* msg) override;

	static Simulator::Attribute ATTRIBUTES[];

	static cPlayerDefensiveShipsManager* Get();

	int GetDynamicSoftCap(Simulator::cEmpire* empire);
	int GetDynamicMaxTreasury(Simulator::cEmpire* empire);
	int CalculateEmpireFleetUpkeep(Simulator::cEmpire* empire);
	float GetSpiceBasePrice(Simulator::cPlanetRecord* planet);
	int CalculateShipBuildCost(Simulator::cEmpire* empire);

	int GetMaxDefenders(Simulator::cPlanetRecord* planet);
	int GetPeacePatrolCount(Simulator::cPlanetRecord* planet);
	int GetColonyCount(Simulator::cPlanetRecord* planet);
	int GetTurretCount(Simulator::cPlanetRecord* planet);
	float GetPlanetaryCityUnrestFactor(Simulator::cPlanetRecord* planet);
	int GetSpawnBatch(Simulator::cPlanetRecord* planet);
	int GetDynamicReinforceTime(Simulator::cPlanetRecord* planet);
	float CalculateShipHealth(Simulator::cPlanetRecord* planet, Simulator::cEmpire* empire);
	bool IsPlanetUnderAttack(Simulator::cPlanetRecord* planet);
	bool ShouldTriggerRebellion(Simulator::cPlanetRecord* planet, Simulator::cEmpire* empire, bool isPeacetimeCheck = false);

	Simulator::cGameDataUFO* SpawnDefensiveShip(Simulator::cPlanetRecord* planet, Simulator::cEmpire* empire, bool canRebel = false, bool isPeacetimeCheck = false);
	
	void ManagePlanetDefenders(Simulator::cPlanetRecord* planet);
	void DecreaseDefendersOnPlanet(Simulator::cPlanetRecord* planet);
	void AddDefenderToPlanet(Simulator::cPlanetRecord* planetToReinforce, int countToAdd);
	int GetDefendersOnPlanet(Simulator::cPlanetRecord* planet);

private:
	bool IsPlanetQueuedForReinforcement(Simulator::cPlanetRecord* planet) const;

	static cPlayerDefensiveShipsManager* instance;

	int elapsedTime;
	int reinforceTime;
	int lastUpkeepTime;
	int lastPeacetimeCheckTime;
	int playerColonyDefenders;
	int playerHomeworldDefenders;
	int playerOutpostDefenders;
	int softCapThreshold;
	int reserveToMobilize;

	// Динамические множители из XML / .prop конфигов установщика (без хардкода)
	float configFleetMultiplier;      // FleetConfig.prop (0x07A1BC01)
	float configRebellionMultiplier;  // RebellionConfig.prop (0x07A1BC02)
	float configUpkeepMultiplier;     // UpkeepConfig.prop (0x07A1BC03): 0.0x = выкл, 0.5x, 1.0x, 2.0x
	float configCityUnrestMultiplier; // UnrestConfig.prop (0x07A1BC04): влияние бастующих городов и заводов
	int upkeepIntervalMs;             // UpkeepConfig.prop (0x07A1BC05): интервал жалования флоту (по умолч. 180000 мс)

	cPlanetRecordPtr lastActivePlanet;

	struct planetReinforcementStruct {
		cPlanetRecordPtr planet;
		int timeToReinforce;
	};

	eastl::vector<planetReinforcementStruct> planetsToReinforce;
	eastl::map<cPlanetRecordPtr, int> planetDefenderShips;
	eastl::map<cPlanetRecordPtr, int> planetColonyCounts;
	eastl::map<cPlanetRecordPtr, int> planetTurretCounts;
	eastl::map<cPlanetRecordPtr, int> planetRebelCooldowns;
};
