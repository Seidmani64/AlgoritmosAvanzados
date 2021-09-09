#include <iostream>
#include "badCharacterRule.h"
#include "goodSuffixRule.h"
using namespace std;

void boyerMoore(string pattern, string text)
{
    vector<pair<char,vector<int>>> allIndexes = getIndexes(pattern,text);
    int k = 0;
    int s = 0;
    while(k <= text.length() - pattern.length() + 1)
    {
        if(pattern == text.substr(k,pattern.length()))
            cout<<"Pattern at: "<<k<<endl;
        s = max(max(badCharacterRule(k,pattern,text,allIndexes),goodSuffixRule(k,text,pattern)),1);
        k += s;
    }
}