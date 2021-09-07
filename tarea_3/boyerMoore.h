#include <iostream>
#include "badCharacterRule.h"
#include "goodSuffixRule.h"
using namespace std;

int boyerMoore(string text, string word)
{
    int k = 1;
    int s = 0;
    while(k < text.length() - word.length() + 1)
    {
        s = max(badCharacterRule(),goodSuffixRule(),1);
        k+=s;
    }
    return s;
}