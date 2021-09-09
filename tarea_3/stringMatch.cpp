#include <iostream>
#include <vector>
#include <utility>
#include "boyerMoore.h"
using namespace std;

int main(){
    string text = "THIS IS A SIMPLE EXAMPLE. DO YOU LIKE THIS EXAMPLE?";
    string pattern = "EXAMPLE";
    vector<pair<char,vector<int>>> allIdx = getIndexes(pattern,text);
    boyerMoore(pattern,text);
    return 0;
}