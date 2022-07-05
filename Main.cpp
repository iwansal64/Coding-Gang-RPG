#include "requirements.hpp"
#include "variables.hpp"
#include "function.hpp"

using namespace std;




int main(){ 
  
    map<string, int>* YourData = new map<string, int>();
    YourData = {
        {"Health", 100},
        {"Damage", 10},
        {"CritRate", 15},
        {"CritDamage", 5},
        {"Speed", 20}
    }

    int YourHealth = *YourData["Health"];
    int YourDamage = *YourData["Damage"];
    int YourCritDamage = *YourData["CritDamage"];
    unsigned short YourCritRate = *YourData["CritRate"];
    unsigned short YourSpeed = *YourData["Speed"];


/////////////////////////////////////////////////////////////////////// 
    void BarPrint(int PrintObject){
        for(int i = 0;i < PrintObject;i++){
            cout << "+";
        }
        cout << endl; 
    }
///////////////////////////////////////////////////////////////////////
    flagA:
//////////////////////////////////////////////////////////////////////
    cout << "=====[ Coding Gang RPG ]=====" << endl << endl;

    cout << "Select character : " << endl;
    cout << R"(
      1 : Wann
      2 : KURO
      3 : Ren
      4 : NotChinese
     )";

    unsigned short* Option = new unsigned short(0);
    unsigned short* CharaOption = new unsigned short(0);

    cin >> *CharaOption;

    if (CharaOption > HeroesData::numberOfHeroes ) { 
        cout << "can't be more than " << HeroesData::numberOfHeroes;
        goto flagA; 
    } 
    
    YourData = HeroesData::heroes[HeroesData::heroNames[CharaOption]];
    
    cout << YourData["Health"] << endl;
    cout << YourHealth << endl;//cara outputnya gimana ?lupa gw //a.out?/a.out?
    exit(0);
 
    cout << "start game?" << endl;
    cout << "1 = Yes" << endl;
    cout << "2 = No" << endl;
    cin >> *Option;
    

    while(Option != 1){

        cin >> *Option;

        if(Option ==2){
            goto flagA;
        }
    }
        

    while(YourHealth > 0 && EnemyHealth > 0){
        cout << "=============================================" << endl;
        cout << "Option : " << endl;
        cout << "1.Attack" << endl;
        cout << "2.Heal yourself lol" << endl;
        cout << "3.Suicide" << endl;

        cout << "Choice : ";
        cin >> *Option;



        if(*Option == 1){
            cout << PlayerName << " " << "Choose " << "ATTACK" << "!" << endl;
            EnemyHealth -= 1;
            cout << "=======================================" << endl;
            cout << "Your Health    : ";
            BarPrint(YourHealth);
            cout << "Enemy's Health : ";
            BarPrint(EnemyHealth);

        }
        else if(*Option == 2){
                cout << PlayerName << " " << "Choose " << "HEAL" << "!" << endl;
            YourHealth += 1;
            cout << "=======================================" << endl;
            cout << "Your Health    : ";
            BarPrint(YourHealth);
            cout << "Enemy's Health : ";
            BarPrint(EnemyHealth);
        }
        else if(*Option == 3){
            cout << PlayerName << " " << "Choose " << "SUICIDE" << "!" << endl;
            YourHealth -= YourHealth;
            cout << "=======================================" << endl;
            cout << "Your Health    : ";
            BarPrint(YourHealth);
            cout << "Enemy's Health : ";
            BarPrint(EnemyHealth);
            
        }

        BotChoice = rand()% 3;
        if(BotChoice == 1){
            cout << "Bot" << " " << "Choose " << "ATTACK" << "!" << endl;
            YourHealth -= 1;
            cout << "=======================================" << endl;
            cout << "Your Health    : ";
            BarPrint(YourHealth);
            cout << "Enemy's Health : ";
            BarPrint(EnemyHealth);

        }
        else if(BotChoice == 2){
            cout << "Bot" << " " << "Choose " << "HEAL" << "!" << endl;
            EnemyHealth += 1;
            cout << "=======================================" << endl;
            cout << "Your Health    : ";
            BarPrint(YourHealth);
            cout << "Enemy's Health : ";
            BarPrint(EnemyHealth);
        }

    
    }
    if(YourHealth == 0){
        cout << endl << endl;
        cout << "You lose lol" << endl;
    }
    else if(EnemyHealth == 0){
        cout << endl << endl;
        cout << "You win lol" << endl;
        WinnerName = PlayerName;


        goto flagA;
    }
    
}

