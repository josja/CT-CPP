//
//  main.cpp
//  NICodeTask
//
//  Created by Josja Krosenbrink on 30/04/16.
//  Copyright (c) 2016 20Hz. All rights reserved.
//

#include <iostream>
#include "NiParser.h"

#include <time.h>

int main(int argc, const char * argv[]) {
    double time_consumeda = 0;
    double time_consumedb = 0;
    
    const char *szTestString1 = "Ni nI NI nI Ni";
    const wchar_t *szTestString1w = L"Ni nI NI nI Ni";
    
    const wchar_t *szTestString2 = L"Ni nI NI nI Ni";
    
    // Invoke getNiCount(...) of class MyClass
    
    // Invoke replaceNiWithNI(...) of class MyClass
    
    // Display on screen: "Found X occurrences of Ni. New string: Y"
    
    clock_t start, end;
    unsigned long avgcounta = 0;
    unsigned long avgcountb = 0;
    for (int i=0; i<1000000; i++) {
        start = clock();
            avgcounta = NiParser::getNiCount(szTestString1);
        end = clock();
        time_consumeda += (double)(end - start) / CLOCKS_PER_SEC;
    }
    
    for (int i=0; i<1000000; i++) {
        start = clock();
            avgcountb = NiParser::getNiCount(szTestString1w);
        end = clock();
        time_consumedb += (double)(end - start) / CLOCKS_PER_SEC;
    }
    
    std::cout << '\n';
    std::cout << avgcounta;
    std::cout << '\n';
    std::cout << time_consumeda/1000000.0;
    std::cout << '\n';
    std::cout << avgcountb;
    std::cout << '\n';
    std::cout << time_consumedb/1000000.0;
    std::cout << '\n';

    
    return 0;
}
