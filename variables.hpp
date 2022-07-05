#include "requirements.hpp"

namespace HeroesData {
    std::map<int, std::string> heroNames = {
        {0, "Wann"},
        {1, "Ren"},
        {2, "KURO"},
        {3, "Not Chinese"},
    };

    std::map<std::string, std::map<std::string, int>> heroes = {
        {"Wann", {
            {"Health", 80},    // Normalnya 100 | mungkin nanti damage musuh nya rata rata 10
            {"Damage", 15},    // Normalnya 10  | mungkin nanti darah musuh nya rata rata 100
            {"CritRate", 20},  // Antara 0% - 100% kemungkinan terjadinya critical
            {"CritDamage", 3}, // Itung itungannya damage = damage * critDamage (kalo dapet critical)
            {"Speed", 20}      // Antara 0% - 100% Semakin besar kemungkinan kita kena serangan musuh semakin kecil
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
            {"Health", 100},
            {"Damage", 10},
            {"CritRate", 15},
            {"CritDamage", 5},
            {"Speed", 20}
        }}
    };
}
