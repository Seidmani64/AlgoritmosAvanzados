#include <iostream>
#include <vector>
#include <utility>
using namespace std;

//Function that returns a vector of pairs containing char and vector of ints
//The purpose of this structure is to store the indexes of each character of the pattern
//and to identify them easily by their character component
//Requires both the pattern and text as strings
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

//Function that returns the R of a character at a specific index, as an int
//Requires the current index k, character x,
//and the previously calculated vector of pairs containing chars and vector of ints indexes
//Rp(x) is the first instance of the index of the x being less than the current index k
int findRi(int k, char x, vector<pair<char,vector<int>>>& indexes)
{
    for(int i = 0; i < indexes.size(); i++)
    {
        if(x==indexes[i].first)
        {
            for(int j = 0; j < indexes[i].second.size(); k++)
            {
                if(indexes[i].second[j] < k)
                    return indexes[i].second[j];
            }
        }
    }
    return -1;
}

//Function that returns the amount of characters to jump as an int
//Requires current index k, pattern and text as strings, along with previously mentioned indexes vector
//Depending on the amount of indexes remaining,
//returns either -1 or the current index minus the R of the current index and its character in the text
int badCharacterRule(int k, string pattern, string text, vector<pair<char,vector<int>>>& indexes)
{
    int max = k+pattern.length()-1;
    int idx = pattern.length()-1;
        
        for(int i = k+pattern.length()-1; i >= k; i--)
        {
            if(i+pattern.length() > text.length())
                return -1;
            if(pattern[idx]!=text[i])
            {
                return idx-findRi(idx,text[i],indexes);
            }
            idx--;
        }
    
    return -1;
}
