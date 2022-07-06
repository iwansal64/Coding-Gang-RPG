#include "requirements.hpp"
#include "variables.hpp"
#include "function.hpp"

using namespace std;




int main(){ 
  
    string WinnerName;
    string PlayerName;
    
    // Player Stats
    map<string, int> YourData = {
        {"Health", 100},
        {"Damage", 10},
        {"CritRate", 15},
        {"CritDamage", 5},
        {"Speed", 20},
        {"Heal", 20}
    };

    int *YourHealth = &YourData["Health"];
    int *YourDamage = &YourData["Damage"];
    int *YourCritDamage = &YourData["CritDamage"];
    int *YourCritRate = &YourData["CritRate"];
    int *YourSpeed = &YourData["Speed"];
    int *YourHeal = &YourData["Heal"];


    // Enemy Stats
    map<string, int> EnemyData = {
        {"Health", 100},
        {"Damage", 10}
    }

    int *EnemyHealth = &EnemyData["Health"];
    int *EnemyDamage = &EnemyData["Damage"];
    int BotChoice = 0;


///////////////////////////////////////////////////////////////////////
    cout << "What is your name : ";
    cin >> PlayerName;

    flagA:
    cout << "=====[ Coding Gang RPG ]=====" << endl << endl;
    cout << "Select character : " << endl;
    cout << R"(
      1 : Wann
      2 : KURO
      3 : Ren
      4 : NotChinese
     )";

    unsign_short* Option = new unsign_short(0);
    unsign_short* CharaOption = new unsign_short(0);

    cin >> *CharaOption;

    if (*CharaOption > HeroesData::numberOfHeroes ) { 
        cout << "can't be more than " << HeroesData::numberOfHeroes;
        goto flagA; 
    } 
    
    *YourData["Health"] = HeroesData::heroes[HeroesData::heroNames[*CharaOption]]["Health"];
    *YourData["Damage"] = HeroesData::heroes[HeroesData::heroNames[*CharaOption]]["Damage"];
    *YourData["CritRate"] = HeroesData::heroes[HeroesData::heroNames[*CharaOption]]["CritRate"];
    *YourData["CritDamage"] = HeroesData::heroes[HeroesData::heroNames[*CharaOption]]["CritDamage"];
    *YourData["Speed"] = HeroesData::heroes[HeroesData::heroNames[*CharaOption]]["Speed"];
    *YourData["Heal"] = HeroesData::heroes[HeroesData::heroNames[*CharaOption]]["Heal"];
    
    
    cout << "start game?" << endl;
    cout << "1 = Yes" << endl;
    cout << "2 = No" << endl;
    cin >> *Option;
    

    while(*Option != 1){

        cin >> *Option;

        if(*Option ==2){
            goto flagA;
        }
    }

    *EnemyDamage = (int) random(5, 15, true);
    *EnemyHealth = (int) random(90, 110);
        

    while(*YourHealth > 0 && *EnemyHealth > 0){
        cout << "=============================================" << endl;
        cout << "Option : " << endl;
        cout << "1.Attack" << endl;
        cout << "2.Heal yourself lol" << endl;
        cout << "3.Suicide" << endl;

        cout << "Choice : ";
        cin >> *Option;



        if(*Option == 1){
            cout << PlayerName << " " << "Choose ATTACK!" << endl;
            cout << "Your damage : " << *YourDamage << endl;
            *EnemyHealth -= *YourDamage;
            cout << "=======================================" << endl;
            cout << "Your Health    : ";
            BarPrint(*YourHealth);
            cout << "Enemy's Health : ";
            BarPrint(*EnemyHealth);
            cout << endl;

        }
        else if(*Option == 2){
            cout << PlayerName << " " << "Choose HEAL!" << endl;
            cout << "You heal : " << *YourHeal << " hp!" << endl;
            *YourHealth += *YourHeal;
            cout << "=======================================" << endl;
            cout << "Your Health    : ";
            BarPrint(*YourHealth);
            cout << "Enemy's Health : ";
            BarPrint(*EnemyHealth);
            cout << endl;
        }
        else if(*Option == 3){
            cout << PlayerName << " " << "Choose SUICIDE!" << endl;
            *YourHealth = 0;
            cout << "=======================================" << endl;
            cout << "Your Health    : ";
            BarPrint(*YourHealth);
            cout << "Enemy's Health : ";
            BarPrint(*EnemyHealth);
            cout << endl;
            
        }

        BotChoice = random(0, 2, true);
        if(BotChoice == 1){
            cout << "Bot" << " " << "Choose " << "ATTACK" << "!" << endl;
            cout << "Damage : " << *EnemyDamage << endl << endl;
            *YourHealth -= *EnemyDamage;
            cout << "=======================================" << endl;
            cout << "Your Health    : ";
            BarPrint(*YourHealth);
            cout << "Enemy's Health : ";
            BarPrint(*EnemyHealth);
            cout << endl;
        }
        else if(BotChoice == 2){
            cout << "Bot" << " " << "Choose " << "HEAL" << "!" << endl;
            *EnemyHealth += 1;
            cout << "=======================================" << endl;
            cout << "Your Health    : ";
            BarPrint(*YourHealth);
            cout << "Enemy's Health : ";
            BarPrint(*EnemyHealth);
            cout << endl;
        }

    
    }
    if(*YourHealth == 0){
        cout << endl << endl;
        cout << "You lose lol" << endl;
    }
    else if(*EnemyHealth == 0){
        cout << endl << endl;
        cout << "You win lol" << endl;
        WinnerName = PlayerName;


        goto flagA;
    }
    
}

