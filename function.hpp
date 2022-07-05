using namespace std;

#pragma once

#include "requirements.hpp"
#include "variables.hpp"


template<typename datatype, int size>
void printArray(array<datatype, size> arr, string seperator=", ", string end="\n") {
    unsign_short index = 0;
    for (datatype i : arr) {
        cout << i;
        if (index != (arr.size() - 1)) {
            cout << seperator;
        }
        index++;
    }
    cout << end;
}

float random(int min, int max, bool includeLast=false) {
    return (rand() % (max - min)) + min + (includeLast?1:0);
}

void BarPrint(int PrintObject){
    for(int i = 0;i < PrintObject;i++){
        cout << "+";
    }
    cout << endl; 
}