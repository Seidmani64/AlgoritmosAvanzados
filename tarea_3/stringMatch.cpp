#include <iostream>
#include <vector>
#include <utility>
#include "boyerMoore.h"
using namespace std;

int main(){
    string text = "THIS IS A SIMPLE EXAMPLE. DO YOU LIKE THIS EXAMPLE?";
    string pattern = "EXAMPLE";
    vector<pair<char,vector<int>>> allIdx = getIndexes(pattern,text);
    for(int i = 0; i < allIdx.size(); i++)
    {
        cout<<"The indexes for: "<<allIdx[i].first<<" is: ";
        for(int j = 0; j < allIdx[i].second.size(); j++)
            cout<<allIdx[i].second[j]<<" ";
        cout<<endl;
    }
    return 0;
}