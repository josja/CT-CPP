//
//  NiTextParser.h
//  NICodeTask
//
//  Created by Josja Krosenbrink on 30/04/16.
//  Copyright (c) 2016 20Hz. All rights reserved.
//
//  The NiParser Class counts 'Ni' and replaces them with 'NI'
//  Uses a template to prevent code duplication for chars and wchars support.

#ifndef __NICodeTask__NiTextParser__
#define __NICodeTask__NiTextParser__

class NiParser
{
public:
    // static functions
    static unsigned long    getNiCount(const char* text);
    static unsigned long    getNiCount(const wchar_t* text);

    static const char*      replaceNiWithNI(const char* text);
    static const wchar_t*   replaceNiWithNI(const wchar_t* text);
    
private:
    template<typename T> static unsigned long countTwoCharNeedle(const T* text, unsigned long length, const T* needle);
    template<typename T> static void replaceTwoCharNeedle(T* text, unsigned long length, const T* needle, const T* replacement);
};

#endif /* defined(__NICodeTask__NiTextParser__) */
