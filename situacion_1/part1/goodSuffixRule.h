#include <iostream>
#include <vector>
using namespace std;

int alphaIdx = -1;

//Finds the string alpha, the largest suffix that is equal in both pattern and text at the end
//Requires current index k, string and pattern as strings
//Starts from the current max point of the text and goes back, checking for equality
//If the last character of text is not equal to the last character of pattern,
//the last character of the text is returned as alpha by default
string findAlpha(int k, string text, string pattern)
{
    string alpha = "";
    if(k+pattern.length()>text.length())
        alpha = {text[text.length()-1]};
    else
    {
        alpha = {text[k+pattern.length()-1]};
    }
    int size = 0;
    int min = k;
    for(int i = pattern.length()-1; i+k >= k; i--)
    {
        if(pattern[i]==text[k+i])
        {
            size++;
            min = i;
        }
        else if(size == 0)
            i = -1;
    }
    if(size > 0)
    {
        alpha = pattern.substr(min,size);
        alphaIdx = min;
    }
    else
        alphaIdx = k+pattern.length()-1;
    return alpha;

}

//Uses the largest suffix alpha found previously, along with the pattern as strings
//Returns a bool value of whether it found a beta (prefix matching part of suffix) or not
//Checks for parts of alpha, starting with the entire thing and then less and less until it 
//either finds a match or alpha is reduced to 0
bool findBeta(string alpha, string pattern)
{
    bool found = false;
    int j = 0;
    for(int i = alpha.length(); i > 0; i--)
    {
        if(pattern.substr(0,i)==alpha.substr(j,alpha.length()))
            found = true;
        j++;
    }
    return found;
}

//Function that returns the index of alpha in the pattern, or -1 if it isn't found
//Requieres alpha and the pattern as strings
//Checks across the entire pattern for any matches of alpha
int alphaPresent(string alpha, string pattern)
{
    int idx = -1;
    int length = alpha.length();
    for(int i = 0; i < pattern.length()-alpha.length()+1; i++)
    {
        if(pattern.substr(i,alpha.length())==alpha)
            idx = i;
    }
    return idx;
}

//Function that returns the amount of characters to jump as an int
//Requires the current index k, the original text and pattern as strings
//Utilizes all the previous functions in order of priority (case 1, 2 and 3)
int goodSuffixRule(int k, string text, string pattern)
{
    int s = 0;
    string alpha = findAlpha(k,text,pattern);
    int alphaIdxPattern = alphaPresent(alpha,pattern);
    if(alphaIdxPattern > -1)
    {
        s = alphaIdx - k - alphaIdxPattern;
    }
    else if(findBeta(alpha,pattern))
    {
        s = 0;
    }
    else
    {
        s = pattern.length();
    }
    return s;
}