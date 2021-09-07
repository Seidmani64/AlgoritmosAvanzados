#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<pair<char,vector<int>>> getIndexes(string pattern, string text)
{
    vector<pair<char,vector<int>>> allIndexes;
    vector<int> letterIndexes;
    char currentChar = ' ';
    for(int i = pattern.size()-1; i>=0;i--)
    {
        letterIndexes.clear();
        currentChar = pattern.at(i);
        for(int j = pattern.size()-1; j >= 0; j--)
            if(pattern.at(j)==currentChar)
                letterIndexes.push_back(j);
        allIndexes.push_back(make_pair(currentChar,letterIndexes));
    }

    return allIndexes;
}

int badCharacterRule(string pattern, string text, vector<vector<int>> indexes)
{
    
    return 0;
}