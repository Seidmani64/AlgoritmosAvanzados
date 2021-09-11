#ifndef part2_hpp
#define part2_hpp
#include<vector>
#include<string>
#include<iostream>
#include "palindromes.hpp"


void part2(std::vector<std::string> textVector){
    std::vector<int> positions, maxLengths;
    for(int i = 0; i < textVector.size(); i++){
        int val[textVector.at(i).length()] = {0};
        FindLongestPalindrome(textVector.at(i), val);
        int maxLength = -1;
        int position = -1;
        for(int j = 0; j < textVector.at(i).length(); j++){
            if(val[j] > maxLength){
                maxLength = val[j];
                position = j-maxLength;
            }
        }
        if(position!=-1){
            positions.push_back(position);
            maxLengths.push_back(maxLength+maxLength+1);
        }
    }

    int maxSizeLine = -1;
    for(int i = 0; i<maxLengths.size(); i++){
        if(maxLengths.at(i) > maxSizeLine){
            maxSizeLine = i;
        }
    }
    
    std::cout << "Position: " << positions.at(maxSizeLine) << ". Line: " << maxSizeLine << ". Length: " << maxLengths.at(maxSizeLine) << std::endl;
}

#endif // !part2_hpp