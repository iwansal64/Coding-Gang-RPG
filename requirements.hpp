
#pragma once
#if __WIN32
    #include <Windows.h>
    #define sleep(X) Sleep(X)
    #define clearScreen "cls"
#else
    #include <unistd.h>
    #define sleep(X) usleep(X)
    #define clearScreen "clear"
#endif

#include <iostream>
#include <cstdlib>
#include <cmath> 
#include <string>
#include <array>
#include <map>