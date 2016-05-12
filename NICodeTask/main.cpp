//
//  main.cpp
//  NICodeTask
//
//  Created by Joshua Krosenbrink on 30/04/16.
//  Copyright (c) 2016. All rights reserved.
//

#include <iostream>
#include "NiParser.h"
#include "NiParser_MT.h"

#include <time.h>

void profile() {
    NiParser_MT NiParserMT = singleton<NiParser_MT>();
    
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
        avgcountb = NiParserMT.getNiCount(szTestString1);
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
    
}


int main(int argc, const char * argv[]) {
    const char      *szTestString1 =  "Ni nI NI nI Ni";
    const wchar_t   *szTestString2 = L"Ni nI NI nI Ni";
    
    //---------- ASCII -------
    
    // Get count of 'Ni' occurences
    unsigned long count = NiParser::getNiCount(szTestString1);
    
    // Replace all 'Ni' occurences with 'NI'
    const char* ascii = NiParser::replaceNiWithNI(szTestString1);

    // Report back
    printf("Using ASCII\n");
    printf("Found %lu occurrences of Ni. New string: %s\n\n", count, ascii);
    
    //---------- UNICODE -------
    
    // Get count of 'Ni' occurences
    count = NiParser::getNiCount(szTestString2);
    
    // Replace all 'Ni' occurences with 'NI'
    const wchar_t* unicode = NiParser::replaceNiWithNI(szTestString2);

    // Report back
    printf("Using UNICODE\n");
    printf("Found %lu occurrences of Ni. New string: %ls\n\n", count, unicode);
    
    return 0;
}


