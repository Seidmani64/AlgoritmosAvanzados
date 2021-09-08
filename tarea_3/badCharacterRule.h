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

int findRi(int i, char x, vector<pair<char,vector<int>>>& list)
{
    for(int j = 0; j < list.size(); j++)
    {
        if(x==list[j].first)
        {
            for(int k = 0; k < list[j].second.size(); k++)
            {
                if(list[j].second[k] < i)
                    return list[j].second[k];
            }
        }
    }
    return -1;
}

int badCharacterRule(int k, string pattern, string text, vector<pair<char,vector<int>>>& indexes)
{
    int max = k+pattern.length()-1;
    int idx = pattern.length()-1;
    for(int i = k+pattern.length()-1; i >= k; i--)
    {
        if(pattern[idx]!=text[i])
        {
            return idx-findRi(idx,text[i],indexes);
        }
        idx--;
    }
    return -1;
}

/*
int badCharacterRule(int i, char Tk, vector<pair<char,vector<int>>> indexes)
{
    return i-findRi(i,Tk,indexes);
}
*/