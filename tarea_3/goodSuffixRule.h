#include <iostream>
#include <vector>
using namespace std;

vector<int> shift;
vector<int> border;

void caseA(string pattern)
{
    int i = pattern.length();
    int j = i+1;

    while(i>0)
    {
        while(j<=pattern.length() && pattern[i-1] != pattern[j-1])
        {
            if (shift[j]==0)
                shift[j] = j-i;
            j = border[j];
        }
    }
    i--;
    j--;
    border[i] = j;
}

void caseB(string pattern)
{
    int i, j;
    j = border[0];
    for(i=0; i<=pattern.length(); i++)
    {
        if(shift[i]==0)
            shift[i] = j;
  
        if (i==j)
            j = border[j];
    }
}

int goodSuffixRule(string text, string pattern)
{
    border.resize(pattern.length()+1);
    shift.resize(pattern.length()+1);
    int s = 0;
    int j = 0;

    if (j<0)
        s += shift[0];
    else
        s += shift[j+1];
    return s;
}