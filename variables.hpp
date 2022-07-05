
#pragma once

#include "requirements.hpp"
using namespace std;

typedef unsigned short indexType;
namespace HeroesData {
    int numberOfHeroes = 3;
    
    map<unsigned short, string> heroNames = {
        {0, "Wann"},
        {1, "Ren"},
        {2, "KURO"},
        {3, "Not Chinese"},
    };

    map<string, map<string, int>> heroes = {
        {"Wann", {
            {"Health", 80},    // Normalnya 100 | mungkin nanti damage musuh nya rata rata 10
            {"Damage", 15},    // Normalnya 10  | mungkin nanti darah musuh nya rata rata 100
            {"CritRate", 20},  // Antara 0% - 100% kemungkinan terjadinya critical
            {"CritDamage", 3}, // Itung itungannya damage = damage * critDamage (kalo dapet critical)
            {"Speed", 20}      // Antara 0% - 100% Semakin besar kemungkinan kita maka kena serangan musuh semakin kecil
        }}, // Kalo mau nambahin stats boleh aja yg penting itu bagus gak di jalanin di cli
        {"Ren", {
            {"Health", 100},
            {"Damage", 10},
            {"CritRate", 15},
            {"CritDamage", 5},
            {"Speed", 20}
        }},
        {"KURO", {
            {"Health", 100},
            {"Damage", 10},
            {"CritRate", 15},
            {"CritDamage", 5},
            {"Speed", 20}
        }},
        {"Not Chinese", {
            {"Health", 90},
            {"Damage", 7},
            {"CritRate", 36},
            {"CritDamage", 5},
            {"Speed", 55}
        }}
    };



    struct character{
        int Damage;
        int Health;
        int CritRate;
        int CritDamage;
    }

    character Wann;
    Wann.Health     = 80;
    Wann.Damage     = 15;
    Wann.CritRate   = 20;
    Wann.CritDamage = 3;
    Wann.Speed      = 20;
    
    character Ren;
    Ren.Health     = 100;
    Ren.Damage     = 10;
    Ren.CritRate   = 15;
    Ren.CritDamage = 5;
    Ren.Speed      = 20;
    
    character KURO;
    KURO.Health     = 100;
    KURO.Damage     = 10;
    KURO.CritRate   = 15;
    KURO.CritDamage = 5;
    KURO.Speed      = 20;
    
    character NotChinese;
    NotChinese.Health     = 85;
    NotChinese.Damage     = 7;
    NotChinese.CritRate   = 38;
    NotChinese.CritDamage = 5;
    NotChinese.Speed      = 55;
    




}
