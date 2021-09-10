#include <iostream>
#include <vector>
#include <utility>
#include "boyerMoore.h"
#include "txtToString.h"
using namespace std;


int main(){
    vector<string> text1 = txtToString("transmission1.txt");
    vector<string> text2 = txtToString("transmission2.txt");
    string pattern1 = getPattern("mcode1.txt");
    string pattern2 = getPattern("mcode2.txt");
    string pattern3 = getPattern("mcode3.txt");
    string patternTest;
    int column = -1;
    int line = -1;

    //TEST PATTERN1 TEXT 1
    for(int i = 0; i < text1.size(); i++)
    {
        column = boyerMoore(pattern1,text1[i]);
        line = i;
        if(column > 0)
            i = text1.size();
    }
    if(column > 0)
        cout<<"true "<<line+1<<" "<<column+1<<endl;
    else
        cout<<"false"<<endl;
    
    //TEST PATTERN2 TEXT1
    column = -1;
    line = -1;
    for(int i = 0; i < text1.size(); i++)
    {
        column = boyerMoore(pattern2,text1[i]);
        line = i;
        if(column > 0)
            i = text1.size();
    }
    if(column > 0)
        cout<<"true "<<line+1<<" "<<column+1<<endl;
    else
        cout<<"false"<<endl;

    //TEST PATTERN3 TEXT1
    column = -1;
    line = -1;
    for(int i = 0; i < text1.size(); i++)
    {
        column = boyerMoore(pattern3,text1[i]);
        line = i;
        if(column > 0)
            i = text1.size();
    }
    if(column > 0)
        cout<<"true "<<line+1<<" "<<column+1<<endl;
    else
        cout<<"false"<<endl;

    //TEST PATTERN1 TEXT2
    column = -1;
    line = -1;
    for(int i = 0; i < text2.size(); i++)
    {
        column = boyerMoore(pattern1,text2[i]);
        line = i;
        if(column > 0)
            i = text2.size();
    }
    if(column > 0)
        cout<<"true "<<line+1<<" "<<column+1<<endl;
    else
        cout<<"false"<<endl;

    //TEST PATTERN2 TEXT2
    column = -1;
    line = -1;
    for(int i = 0; i < text2.size(); i++)
    {
        column = boyerMoore(pattern1,text2[i]);
        line = i;
        if(column > 0)
            i = text2.size();
    }
    if(column > 0)
        cout<<"true "<<line+1<<" "<<column+1<<endl;
    else
        cout<<"false"<<endl;
    
    //TEST PATTERN3 TEXT2
    column = -1;
    line = -1;
    for(int i = 0; i < text2.size(); i++)
    {
        column = boyerMoore(pattern3,text2[i]);
        line = i;
        if(column > 0)
            i = text2.size();
    }
    if(column > 0)
        cout<<"true "<<line+1<<" "<<column+1<<endl;
    else
        cout<<"false"<<endl;
    
    return 0;
}