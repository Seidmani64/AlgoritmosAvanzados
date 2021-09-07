#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<pair<char,vector<int>>> getIndexes(string pattern, string text)
{
    vector<pair<char,vector<int>>> allIndexes;
    vector<int> letterIndexes;
    char currentChar = ' ';
    while(pattern.size() > 0)
    {
        letterIndexes.clear();
        currentChar = pattern.at(pattern.size()-1);
        for(int i = pattern.size()-1; i >= 0; i--)
        {
                if(pattern.at(i)==currentChar)
                {
                    letterIndexes.push_back(i);
                    if(pattern.size() == 1)
                        pattern.erase(0);
                    else
                        pattern.erase(i,i);
                }
        }
        allIndexes.push_back(make_pair(currentChar,letterIndexes));
    }

    return allIndexes;
}

int badCharacterRule(string pattern, string text, vector<vector<int>> indexes)
{
    
    return 0;
}