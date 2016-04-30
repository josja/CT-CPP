//
//  main.cpp
//  NICodeTask
//
//  Created by Joshua Krosenbrink on 30/04/16.
//  Copyright (c) 2016. All rights reserved.
//

#include <iostream>
#include "NiParser.h"

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
