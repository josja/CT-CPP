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
    const T* end = text + (length-1); //< calculate highest possible pointer for needle of length 2
    while (text<end) {
        if (*text == *(needle) && *(text+1) == *(needle+1)) { //< compare two sequential chars
            count++;
        }
        text++;
    }
    return count;
}

const char* NiParser::replaceNiWithNI(const char* text) {
    unsigned short length = strlen(text);
    char * output = new char[length];
    strcpy(output, text);
    replaceTwoCharNeedle(output, length, "Ni", "NI");
    return output;
}

const wchar_t* NiParser::replaceNiWithNI(const wchar_t* text) {
    unsigned short length = wcslen(text);
    wchar_t * output = new wchar_t[length];
    wcscpy(output, text);
    replaceTwoCharNeedle(output, length, L"Ni", L"NI");
    return output;
}

template<typename T>
void NiParser::replaceTwoCharNeedle(T* text, unsigned long length, const T* needle, const T* replacement) {
    const T* end = text + (length-1); //< calculate highest possible pointer for needle of length 2
    while (text<end) {
        if (*text == *(needle) && *(text+1) == *(needle+1)) {   //< compare two sequential chars
            //*(text) = *(replacement);                           //< set 'N' to 'N' (this is pure for completeness, comment out for optimization
            *(text+1) = *(replacement+1);                       //< set 'i' to 'I'
        }
        text++;
    }
}
