# 🛡️ Defensive Ships in Player Colonies — 4X Garrison & Economy Core

**Platform:** Spore: Galactic Adventures (`v1.0.9+`)  
**Requires:** Spore ModAPI Launcher Kit  
**Companion Mod:** [Space Diplomacy & Warfare Overhaul](/GreenPerfectAlt/Space-Diplomacy-And-Warfare-Overhaul_GreenPerfectAlt)

**Defensive Ships in Player Colonies** transforms passive Spore colonies into living, defended 4X bastions—and serves as the **master XML configuration hub** for our two-mod Space Stage overhaul ecosystem.

Your colonies automatically deploy defense fleets using your own Sporepedia ship, scale with T-Score, city count (**Unlimited-Colony** compatible), weapon rank, and planetary gadgets, charge realistic fleet upkeep, and react to citizen strikes and colonial mutinies.

---

## ⚠️ IMPORTANT: Two-Mod Ecosystem (Install Both!)

This mod is **Part 1** of a unified two-mod overhaul. While it works standalone for your own colonies, **install BOTH mods together** to unlock the complete 4X Space Stage experience:

1. 🛡️ **Defensive Ships in Player Colonies** *(This Mod — `v1.0.9+`)*
   * Manages **your** planetary defense fleets, orbital shipyards, fleet upkeep, citizen strikes, and player colony rebellions.
   * Contains the **Interactive ModAPI Installer** (`FleetConfig`, `RebellionConfig`, `UpkeepConfig`, `UnrestConfig`, `GadgetConfig`, `TradeConfig`) that controls balance across **both** mods with zero hardcoded values!
2. ⚔️ **[Space Diplomacy & Warfare Overhaul](/GreenPerfectAlt/Space-Diplomacy-And-Warfare-Overhaul_GreenPerfectAlt)** *(Companion Mod — `v1.1.3+`)*
   * Reads your installer presets from this mod and applies all mechanics to **AI Empires**!
   * Unlocks **3D Galactic Trade Convoys** (two-way player convoys & multi-species spaceports), **Convoy Plundering**, **AI Treasury & Upkeep**, **Orbital Uber-Turret Dreadnoughts**, **Embassy Cruisers**, **The Great Zealot Schism**, and **Background Galactic Revolutions** (breakaway republics & SOS distress signals).

---

## ✨ Core Features (Player Colonies)

### 1. Dynamic Automated Defense Fleets
* **Your Own Sporepedia Ships:** Every colonized planet automatically deploys autonomous defender UFOs matching your empire's ship model.
* **Smart Scaling & Soft-Cap:** Fleet size scales with planet T-Score (`T0` Outpost → `T3` Metropolis / Homeworld), total cities (supports **Unlimited-Colony** mods!), your Empire size, and Weaponry rank, smoothed by a square-root soft-cap to protect FPS.
* **Philosophy Hull Plating:**
  * **Military (`Warrior`, `Zealot`, `Knight`):** `1.35x` Heavy Armor.
  * **Scientific / Nature / Trade (`Scientist`, `Trader`, `Ecologist`, `Shaman`):** `1.10x` Reinforced Hulls.
  * **Civilian (`Diplomat`, `Bard`, `Wanderer`):** `0.85x` Light Hulls.

### 2. Shipyard Respawn & Planetary Logistics
* Destroyed defenders aren't conjured out of thin air—planets rebuild lost ships over time via orbital shipyards.
* **Respawn Speed** accelerates with higher T-Scores, extra cities, **Spice Storage** depots, and active trade routes, while slowing down if citizens go on strike.

### 3. Fleet Maintenance (Upkeep) & Treasury Impact
* Maintaining a massive armada costs Sporebucks (`Upkeep`), scaled dynamically against your empire's wealth and territory.
* **Bankruptcy Risk:** Letting your treasury run dry while overextending across distant stars lowers garrison morale and can spark colonial mutinies!

### 4. City Unhappiness, Factory Strikes & Colonial Rebellions
* **Real City Inspection:** Overloading colonies with factories without enough entertainment buildings causes unhappy citizens and **Factory Strikes**, slowing down shipyard production and raising unrest.
* **Garrison Mutinies:** If a neglected frontier colony suffers severe strikes, heavy combat losses, or empire bankruptcy, part of your defense fleet can turn traitor (`0xFFFFFFFF` Rebel faction) and bombard your cities!
* **Non-Lethal Riot Control:** Calm down rebellious defenders instantly without destroying your own ships by firing **Mind Erase**, **Happiness Rays**, **Fireworks**, or **Soothing Song**!

### 5. Full Planetary Gadget & Tool Synergy
Every vanilla colonization building and ship tool now has deep tactical purpose:

| Planetary Gadget / Tool | Tactical & Economic Effect |
| :--- | :--- |
| **Spice Storage** | **`+25%` Max Garrison Fleet Size**, faster shipyard repairs, and **`1.35x` larger Trade Convoys**. |
| **Uber Turret** | Boosts defender hull armor (**`+25%` HP**) and fortifies planetary order. *(Spawns Boss Dreadnoughts for AI in Companion Mod!)* |
| **Loyalty Booster** | Suppresses rebellion chance by **`90%`** and prevents shipyard strike slowdowns. **Warning:** If destroyed in battle, half the garrison immediately mutinies! |
| **Happiness Booster** | Eliminates citizen unhappiness penalties (`0%` city strike unrest). |
| **Bio-Protector / Stabilizer** | Reduces industrial unrest by **`30%`** and grants bonus bio-hull armor to **Ecologists** & **Shamans**. |
| **Embassy** *(Companion Mod)* | Stabilizes peacetime allies (`-50%` unrest), deploys Diplomatic Cruisers, and boosts enemy defection (`+25%`) if war breaks out! |

---

## ⚙️ Interactive ModAPI Installer Options

When installing `DefensiveShipsInPlayerColonies.sporemod` via the **Spore ModAPI Easy Installer**, you can customize **6 independent modules** (`Disabled / 0.5x / 1.0x Standard / 1.5x Hardcore`):

> 💡 **Note:** Changing any preset by reinstalling this mod automatically updates the rules for **Space Diplomacy & Warfare Overhaul** as well—100% save-game safe!

1. **Fleet Scale (`FleetConfig`):** Controls total defender ship counts on your colonies (`0.5x` FPS-friendly to `1.5x` Massive Armadas).
2. **Colonial Rebellions (`RebellionConfig`):** Sets mutiny chance, **Zealot Schism** cascade duration (`120s–360s`), background **Galactic Revolution** cooldowns, and minimum superpower size (`5–8+` stars) for breakaway republics (or `Disabled` for 100% loyal fleets).
3. **Fleet Upkeep (`UpkeepConfig`):** Controls periodic Sporebuck maintenance costs for player and AI fleets (`Disabled` for free fleets, up to `1.5x` strict economy).
4. **City Unrest (`UnrestConfig`):** Controls how strongly unhappy citizens and excess factories slow down shipyards and provoke strikes.
5. **Gadget & Tool Synergy (`GadgetConfig`):** Scales all bonuses from Spice Storage, Uber Turrets, Loyalty/Happiness Boosters, Bio-Protectors, and Embassies.
6. **Galactic Trade & Convoys (`TradeConfig`):** Controls 3D trade convoy fleet density, spice arbitrage income, diplomatic war deterrence, and rare-spice tanker armor scaling *(used by Companion Mod)*.

---

## 📥 Installation & Requirements

1. Requires **Spore: Galactic Adventures** (Steam, GOG, or EA App) and the **Spore ModAPI Launcher Kit**.
2. Download the latest **`DefensiveShipsInPlayerColonies.sporemod`** from the **[Releases](../../releases)** page of this repository.
3. Download the latest **`Space-Diplomacy-And-Warfare-Overhaul.sporemod`** from the **[Companion Mod Releases](/GreenPerfectAlt/Space-Diplomacy-And-Warfare-Overhaul_GreenPerfectAlt/releases)**.
4. Open **Spore ModAPI Easy Installer**, install both `.sporemod` files, choose your preferred presets, and launch the game via **Spore ModAPI Launcher**!

---

## 🤝 Credits & Compatibility
* Fully compatible with existing save games, **Unlimited-Colony** mods, and custom modded spice types (prices are read dynamically from game properties with zero hardcoding).
* Developed & expanded by **GreenPerfectAlt** using the Spore ModAPI framework.


## Image
![Defensive Ships](images/DefensiveShips.png)
