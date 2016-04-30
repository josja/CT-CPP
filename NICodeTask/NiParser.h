//
//  NiTextParser.h
//  NICodeTask
//
//  Created by Joshua Krosenbrink on 30/04/16.
//  Copyright (c) 2016. All rights reserved.
//
//  The NiParser Class counts 'Ni' and replaces them with 'NI'
//  Uses a template to prevent code duplication for chars and wchars support.
//  It also keeps all string operations in C to aid performance.

#ifndef __NICodeTask__NiTextParser__
#define __NICodeTask__NiTextParser__

class NiParser
{
public:
    static unsigned long    getNiCount(const char* text);           //< Get Ni count from ASCII string
    static unsigned long    getNiCount(const wchar_t* text);        //< Get Ni count from Unicode string

    static const char*      replaceNiWithNI(const char* text);      //< Replace Ni's in ASCII string
    static const wchar_t*   replaceNiWithNI(const wchar_t* text);   //< Replace Ni's in Unicode string
    
private:
    // Helper functions
    template<typename T> static unsigned long   _countTwoCharNeedle(const T* text, unsigned long length, const T* needle);
    template<typename T> static void            _replaceTwoCharNeedle(T* text, unsigned long length, const T* needle, const T* replacement);
};

#endif /* defined(__NICodeTask__NiTextParser__) */
