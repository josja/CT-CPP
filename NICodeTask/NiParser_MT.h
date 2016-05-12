//
//  NiParser_MT.h
//  NICodeTask
//
//  Created by Joshua Krosenbrink on 30/04/16.
//  Copyright (c) 2016. All rights reserved.
//
//  The Multi Threaded NiParser Class counts 'Ni' and replaces them with 'NI'
//  Uses a template to prevent code duplication for chars and wchars support.
//  It also keeps all string operations in C to aid performance.

#ifndef __NICodeTask__NiParser_MT__
#define __NICodeTask__NiParser_MT__

template <class X>
X& singleton()
{
    static X x;
    x.init();
    return x;
}

class NiParser_MT
{
public:
    unsigned long    getNiCount(const char* text);           //< Get Ni count from ASCII string
    unsigned long    getNiCount(const wchar_t* text);        //< Get Ni count from Unicode string
    
    const char*      replaceNiWithNI(const char* text);      //< Replace Ni's in ASCII string
    const wchar_t*   replaceNiWithNI(const wchar_t* text);   //< Replace Ni's in Unicode string

    void init();
private:
    // Helper functions
    template<typename T> unsigned long   _countTwoCharNeedle(const T* text, unsigned long length, const T* needle);
    template<typename T> void            _replaceTwoCharNeedle(T* text, unsigned long length, const T* needle, const T* replacement);
};

#endif /* defined(__NICodeTask__NiParser_MT__) */
