//
//  NiTextParser.cpp
//  NICodeTask
//
//  Created by Josja Krosenbrink on 30/04/16.
//  Copyright (c) 2016 20Hz. All rights reserved.
//

#include <cstring>
#include <cwchar>
#include "NiParser.h"

unsigned long NiParser::getNiCount(const char* text) {
    return countTwoCharNeedle(text, strlen(text), "Ni");
}

unsigned long NiParser::getNiCount(const wchar_t* text) {
    return countTwoCharNeedle(text, wcslen(text), L"Ni");
}

template<typename T>
unsigned long NiParser::countTwoCharNeedle(const T* text, unsigned long length, const T* needle) {
    unsigned long count = 0;
    const T* end = text + (length-1); //< calculate last possible pointer for needle of length 2
    while (text<end) {
        if (*text == *(needle) && *(text+1) == *(needle+1)) { //< compare string buffers
            count++;
        }
        text++;
    }
    return count;
}


unsigned long NiParser::replaceNiWithNI(const char* text) {
    return 0;
}
