
#pragma once

#include "requirements.hpp"
#include "function.hpp"
using namespace std;

typedef unsigned short unsign_short;
enum name_init {Wann=1, Ren, KURO, NotChinese};
namespace HeroesData {
    // Private member in namespace
    namespace {
        unsign_short nextIteration = 0;
        unsign_short timeout = 0;
    }
    
    int numberOfHeroes = 4;
    
    map<unsign_short, string> heroNames = {
        {Wann, "Wann"},
        {Ren, "Ren"},
        {KURO, "KURO"},
        {NotChinese, "Not Chinese"},
    };

    map<string, map<string, int>> heroes = {
        {"Wann", {
            {"Health", 80},    // Normalnya 100 | rata rata damage musuh nya 10
            {"Damage", 15},    // Normalnya 10  | rata rata darah musuh nya 110
            {"CritRate", 25},  // Antara 0% - 100% kemungkinan terjadinya critical
            {"CritDamage", 4}, // Itung itungannya damage = damage * critDamage (kalo dapet critical)
            {"Speed", 20},     // Antara 0% - 100% Semakin besar kemungkinan kita maka kena serangan musuh semakin kecil
            {"Heal", 12}       // Normalnya 10
        }},
        {"Ren", {
            {"Health", 100},
            {"Damage", 10},
            {"CritRate", 15},
            {"CritDamage", 5},
            {"Speed", 20},
            {"Heal", 10}
        }},
        {"KURO", {
            {"Health", 100},
            {"Damage", 10},
            {"CritRate", 15},
            {"CritDamage", 5},
            {"Speed", 20},
            {"Heal", 10}
        }},
        {"Not Chinese", {
            {"Health", 90},
            {"Damage", 7},
            {"CritRate", 36},
            {"CritDamage", 5},
            {"Speed", 55},
            {"Heal", 10}
        }}
    };

    bool specialPower(string name, map<string, int> &playerData, int &enemyHealth, int &enemyDamage, unsign_short currentIteration) {
        
        name = toLowerCase(name);
        
        if (nextIteration > currentIteration) {
            return false;
        }

        // Desc : Heal + increase CritRate
        if (name == "wann") {
            
            playerData["Health"] += 10;
            playerData["CritRate"] += 25;

            nextIteration = currentIteration + 4; // Cooldown - after 4 loop (+1 loop each option menu show up) player can use special power again
            timeout = currentIteration + 3;       // Timeout  - after 3 loop player lose their power
        }
        // Desc : 
        else if (name == "ren") {
            
            // Code

            nextIteration = currentIteration + 2;
        }
        // Desc : 
        else if (name == "kuro") {
            if (nextIteration > 0) {
                //reset
            }
            
            // Code

            nextIteration = currentIteration + 2;
        }
        // Desc : 
        else if (name == "not chinese") {
            if (nextIteration > 0) {
                //reset
            }
            
            // Code

            nextIteration = currentIteration + 2;
        }

        return true;
    }

    bool resetPower(string name, map<string, int> &playerData, int &enemyHealth, int &enemyDamage, unsign_short currentIteration) {
        if (timeout > currentIteration || timeout == 0) {
            return true;
        }
        name = toLowerCase(name);
        

        // Desc : Heal + increase CritRate
        if (name == "wann") {
            
            playerData["Health"] -= 10;
            playerData["CritRate"] -= 25;

        }
        // Desc : 
        else if (name == "ren") {
            
            // Code
        }
        // Desc : 
        else if (name == "kuro") {
            
            // Code
        }
        // Desc : 
        else if (name == "not chinese") {
            
            // Code
        }

        timeout == 0;
        return false;
    }

    int getPowerCooldown(unsign_short iteration) {
        return (timeout - iteration);
    }



    struct character{
        int Damage;
        int Health;
        int CritRate;
        int CritDamage;
        int Speed;
        int Heal;
    };

    character Wann = {15, 80, 20, 3, 20, 12};
    character Ren = {10, 100, 15, 5, 20, 10};
    character KURO = {10, 100, 15, 5, 20, 10};
    character NotChinese = {7, 85, 38, 5, 55, 10};
}
