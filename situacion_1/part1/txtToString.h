#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

vector<string> txtToString(string fileName)
{
    vector<string> result;
    ifstream file (fileName);
    if (!file) {
        cout << "unable to open file";
        return result;
    }
    string sent;
    while (getline (file, sent))
    {
    result.push_back(sent);
    }
    return result;
}

string getPattern(string fileName)
{
    string result;
    ifstream file (fileName);
    if (!file) {
        cout << "unable to open file";
        return "";
    }
    string sent;
    while (getline (file, sent))
    {
    result += sent;
    }
    return result;
}