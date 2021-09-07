#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> getIndexes(string pattern, string text)
{
    cout<<"Entered idx fun: "<<endl;
    vector<vector<int>> allIndexes;
    vector<int> letterIndexes;
    char currentChar = ' ';
    while(pattern.size() > 0)
    {
        cout<<"Entered while loop: "<<endl;
        letterIndexes.clear();
        currentChar = pattern.at(pattern.size()-1);
        for(int i = pattern.size()-1; i >= 0; i--)
        {
            cout<<"Entered for loop with pattern size of: "<<pattern.size()<<endl;
            if(pattern.size() == 1)
                if(pattern.at(i)==currentChar)
                {
                    cout<<"Pattern before erase: "<<pattern<<endl; 
                    letterIndexes.push_back(i);
                    pattern.erase(0);
                    cout<<"Pattern after erase: "<<pattern<<endl; 
                }
            else
                if(pattern.at(i)==currentChar)
                {
                    cout<<"Pattern before erase: "<<pattern<<endl; 
                    letterIndexes.push_back(i);
                    pattern.erase(i,i);
                    cout<<"Pattern after erase: "<<pattern<<endl; 
                }
        }
        allIndexes.push_back(letterIndexes);
    }

    return allIndexes;
}

int badCharacterRule(string pattern, string text, vector<vector<int>> indexes)
{
    
    return 0;
}