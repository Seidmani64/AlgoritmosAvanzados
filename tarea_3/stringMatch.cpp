#include <iostream>
#include <vector>
#include <utility>
#include "boyerMoore.h"
using namespace std;

int main(){
    string text = "THIS IS A SIMPLE EXAMPLE. DO YOU LIKE THIS EXAMPLE?";
    string pattern = "EXAMPLE";
    cout<<"Before idx call"<<endl;
    vector<vector<int>> allIdx = getIndexes(pattern,text);
    cout<<"after idx call"<<endl;
    for(int i = 0; i < allIdx.size(); i++)
    {
        cout<<"The value of allIdx at: "<<i<<" is: ";
        for(int j = 0; j < allIdx[i].size(); j++)
            cout<<allIdx[i][j];
        cout<<endl;
    }
    return 0;
}