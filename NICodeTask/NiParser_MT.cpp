//
//  NiParser_MT.cpp
//  NICodeTask
//
//  Created by Joshua Krosenbrink on 30/04/16.
//  Copyright (c) 2016. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cwchar>
#include "NiParser_MT.h"
#include <thread>

static const int num_threads = 10;

void NiParser_MT::init() {
    printf("hello");
}

// getNiCount(const char* text)
// Returns the count of Ni's in ASCII string
//
unsigned long NiParser_MT::getNiCount(const char* text) {
    
    if (strlen(text) < 2) //< Don't do anything if the text can't contain "Ni"
        return 0;
    
    // Invoke generalized helper
    return _countTwoCharNeedle(text, strlen(text), "Ni");
}


// getNiCount(const wchar_t* text)
// Returns the count of Ni's in Unicode string
//
unsigned long NiParser_MT::getNiCount(const wchar_t* text) {
    
    if (wcslen(text) < 2) //< Don't do anything if the text can't contain "Ni"
        return 0;
    
    // Invoke generalized helper
    return _countTwoCharNeedle(text, wcslen(text), L"Ni");
}


// replaceNiWithNI(const char* text)
// Replaces  Ni's in ASCII string and returns the result
//
const char* NiParser_MT::replaceNiWithNI(const char* text) {
    
    if (strlen(text) < 2) //< Don't do anything if the text can't contain "Ni"
        return text;
    
    unsigned short length = strlen(text);   //< Get ASCII text length
    char * output = new char[length];       //< Create an ASCII output buffer with same length that we can alter
    strcpy(output, text);                   //< Copy original text into output buffer
    
    // Process and change output buffer using generalized helper
    _replaceTwoCharNeedle(output, length, "Ni", "NI");
    return output;
}


// replaceNiWithNI(const wchar_t* text)
// Replaces Ni's in Unicode string and returns the result
//
const wchar_t* NiParser_MT::replaceNiWithNI(const wchar_t* text) {
    
    if (wcslen(text) < 2) //< Don't do anything if the text can't contain "Ni"
        return text;
    
    unsigned short length = wcslen(text);   //< Get Unicode text length
    wchar_t * output = new wchar_t[length]; //< Create an Unicode output buffer with same length that we can alter
    wcscpy(output, text);                   //< Copy original text into output buffer
    
    // Process and change output buffer using generalized helper
    _replaceTwoCharNeedle(output, length, L"Ni", L"NI");
    return output;
}


/////// Helper functions, generalized and optimized

// _countTwoCharNeedle(const T* text, unsigned long length, const T* needle)
// Returns the count of occurences of the needle, for optimization reasons it only compares the first two chars
//
template<typename T>
unsigned long NiParser_MT::_countTwoCharNeedle(const T* text, unsigned long length, const T* needle) {
    
    std::cout << "Launched by thread " << text << std::endl;
    
    unsigned long count = 0; // Keep track of count
    
    const T* end = text + (length-1); //< Calculate highest possible matching pointer for needle of length 2 ("Ni")
    while (text<end) {
        if (*text == *(needle) && *(text+1) == *(needle+1)) {   //< Match two sequential chars with needle
            count++;
        }
        text++; //< Move to next char
    }
    
    return count;
}


// replaceTwoCharNeedle(T* text, unsigned long length, const T* needle, const T* replacement)
// Replaces the occurences of the first two chars of the needle with the first two chars of the replacement
//
template<typename T>
void NiParser_MT::_replaceTwoCharNeedle(T* text, unsigned long length, const T* needle, const T* replacement) {
    
    const T* end = text + (length-1); //< Calculate highest possible matching pointer for needle of length 2 ("Ni")
    while (text<end) {
        if (*text == *(needle) && *(text+1) == *(needle+1)) {   //< Match two sequential chars with needle
            //*(text) = *(replacement);                         //< Set 'N' to 'N', commented out for optimization
            *(text+1) = *(replacement+1);                       //< Set 'i' to 'I'
        }
        text++; //< Move to next char
    }
}
