//
//  main.cpp
//  NICodeTask
//
//  Created by Josja Krosenbrink on 30/04/16.
//  Copyright (c) 2016 20Hz. All rights reserved.
//

#include <iostream>
#include "NiParser.h"

int main(int argc, const char * argv[]) {
    const char      *szTestString1 =  "Ni nI NI nI Ni";
    const wchar_t   *szTestString2 = L"Ni nI NI nI Ni";
    
    // Get count of 'Ni' occurences
    unsigned long count = NiParser::getNiCount(szTestString1);
    
    // Replace all 'Ni' occurences with 'NI'
    const char* replaced = NiParser::replaceNiWithNI(szTestString1);

    // Report back
    printf("Found %lu occurrences of Ni. New string: %s\n", count, replaced);
    return 0;
}
