#include <iostream>
#include <vector>
using namespace std;

string findLongestSuffix(int k, string text, string pattern)
{
    string suffix = "";
    for(int i = 0; i<pattern.length(); i++)
    {
        if(pattern[i]==text[k+i])
        {
            suffix+=pattern[i];
        }
        else
            i = pattern.length();
    }
    
    return suffix;
}

string findAlpha(int k, string text, string pattern)
{
    string alpha = {text[k+pattern.length()-1]};
    int max = -1;
    int min = k;
    for(int i = pattern.length()-1; i+k >= k; i--)
    {
        if(pattern[i]==text[i+k])
        {
            if(max == -1)
                max = i;
            min = i;
        }
    }
    if(max > -1)
        alpha = pattern.substr(min,max);
    return alpha;

}

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

int goodSuffixRule(int k, string text, string pattern)
{
    int s = 0;
    string alpha = findAlpha(k,text,pattern);
    int alphaIdx = alphaPresent(alpha,pattern);
    if(alphaIdx > -1)
    {
        s = alphaIdx;
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