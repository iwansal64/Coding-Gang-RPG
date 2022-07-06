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
        {"Damage", 10},
        {"Heal", 10}
    };

    int EnemyHealth;
    int EnemyDamage;
    int EnemyHeal;
    int BotChoice = 0;


///////////////////////////////////////////////////////////////////////
    cout << "What is your name : ";
    cin >> PlayerName;

    flagA:
    system(clearScreen);
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
        cout << "can't be more than " << HeroesData::numberOfHeroes << endl;
        goto flagA;
    } 
    
    map<string, int>* dataTemp = new map<string, int>();
    *dataTemp = HeroesData::heroes[HeroesData::heroNames[*CharaOption]];

    YourData["Health"] = dataTemp->operator[]("Health");
    YourData["Damage"] = dataTemp->operator[]("Damage");
    YourData["CritRate"] = dataTemp->operator[]("CritRate");
    YourData["CritDamage"] = dataTemp->operator[]("CritDamage");
    YourData["Speed"] = dataTemp->operator[]("Speed");
    YourData["Heal"] = dataTemp->operator[]("Heal");

    delete dataTemp;

    cout << "------- Your Data -------" << endl;
    cout << "Name : " << HeroesData::heroNames[*CharaOption] << endl;
    showPlayerData(YourData);
    
    

    while(*Option != 1){
        
        cout << "start game?" << endl;
        cout << "1 = Yes" << endl;
        cout << "2 = No" << endl;
        cin >> *Option;
        
        if(*Option ==2){
            goto flagA;
        }
    }

    EnemyData["Damage"] = random(5, 15, true);
    EnemyData["Health"] = random(100, 120, true);
    EnemyData["Heal"] = floor(EnemyData["Health"] / 10);
    
    EnemyHealth = EnemyData["Health"];
    EnemyDamage = EnemyData["Damage"];
    EnemyHeal = EnemyData["Heal"];
    

    while(*YourHealth > 0 && EnemyHealth > 0){
        cout << "=============================================" << endl;
        cout << "Option : " << endl;
        cout << "1.Attack" << endl;
        cout << "2.Heal yourself lol" << endl;
        cout << "3.Suicide" << endl;

        cout << "Choice : ";
        cin >> *Option;


        system(clearScreen);
        if(*Option == 1){
            cout << PlayerName << " " << "Choose ATTACK!" << endl;
            cout << "Your damage : " << *YourDamage << endl;

            if (random(0, 100, true) < *YourCritRate) {
                cout << "CRITICAL! damage : " << *YourCritDamage << endl;
                EnemyHealth -= (*YourDamage * *YourCritDamage);
            }
            else {
                EnemyHealth -= *YourDamage;
            }
            
            cout << "=======================================" << endl;
            cout << "Your Health    : ";
            BarPrint(*YourHealth);
            cout << "Enemy's Health : ";
            BarPrint(EnemyHealth);
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
            BarPrint(EnemyHealth);
            cout << endl;
        }
        else if(*Option == 3){
            cout << PlayerName << " " << "Choose SUICIDE!" << endl;
            *YourHealth = 0;
            cout << "=======================================" << endl;
            cout << "Your Health    : ";
            BarPrint(*YourHealth);
            cout << "Enemy's Health : ";
            BarPrint(EnemyHealth);
            cout << endl;
            
        }

        sleep(500);

        if(EnemyHealth > 0) {
            BotChoice = random(0, 2, true);
            if(BotChoice == 1){
                cout << "Bot" << " " << "Choose " << "ATTACK" << "!" << endl;
                cout << "Damage : " << EnemyDamage << endl << endl;
                *YourHealth -= EnemyDamage;
                cout << "=======================================" << endl;
                cout << "Your Health    : ";
                BarPrint(*YourHealth);
                cout << "Enemy's Health : ";
                BarPrint(EnemyHealth);
                cout << endl;
            }
            else if(BotChoice == 2){
                cout << "Bot" << " " << "Choose " << "HEAL" << "!" << endl;
                EnemyHealth += EnemyHeal;
                cout << "=======================================" << endl;
                cout << "Your Health    : ";
                BarPrint(*YourHealth);
                cout << "Enemy's Health : ";
                BarPrint(EnemyHealth);
                cout << endl;
            }

            sleep(1500);
        }
    }
    sleep(1000);
    system(clearScreen);
    if(*YourHealth == 0){
        cout << "You lose lol" << endl;
        WinnerName = "Bot";
    }
    else if(EnemyHealth == 0){
        cout << "You win lol" << endl;
        WinnerName = PlayerName;
    }

    cout << "Data of enemy : " << endl;
    showEnemyData(EnemyData);
    sleep(2500);
    
    string *YOrN = new string(); // Sumpah jelek bet penamaan ny maap
    cout << "Mau lagi y/n? ";
    cin >> *YOrN;

    if (*YOrN == "y") {
        delete YOrN;
        goto flagA;
    }

}

