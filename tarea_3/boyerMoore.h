#include <iostream>
#include "badCharacterRule.h"
#include "goodSuffixRule.h"
using namespace std;

int boyerMoore(string pattern, string text)
{
    int k = 1;
    int s = 0;
    while(k < text.length() - pattern.length() + 1)
    {
        //s = max(badCharacterRule(pattern,text,getIndexes(pattern,text)),goodSuffixRule(),1);
        k+=s;
    }
    return s;
}