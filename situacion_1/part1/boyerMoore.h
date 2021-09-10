#include <iostream>
#include "badCharacterRule.h"
#include "goodSuffixRule.h"
using namespace std;

//Function that recieves pattern and text as a string and returns nothing
//Calls both badCharacterRule and goodSuffixRule methods to process which jump it can make without skipping potential matches
//Prints the index of the first character of the match whenever it finds it
int boyerMoore(string pattern, string text)
{
    vector<pair<char,vector<int>>> allIndexes = getIndexes(pattern,text);
    int k = 0;
    int s = 0;
    while(k <= text.length() - pattern.length() + 1)
    {
        if(pattern == text.substr(k,pattern.length()))
            return k;
        if(text.length() > k+pattern.length())
            s = max(goodSuffixRule(k,text,pattern),1);
        else
            s = 1;
        k += s;
    }
    return -1;
}
