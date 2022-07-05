using namespace std;

#pragma once

#include "requirements.hpp"
#include "variables.hpp"


template<typename datatype, int size>
void printArray(array<datatype, size> arr, string seperator=", ", string end="\n") {
    indexType index = 0;
    for (datatype i : arr) {
        cout << i;
        if (index != (arr.size() - 1)) {
            cout << seperator;
        }
        index++;
    }
    cout << end;
}