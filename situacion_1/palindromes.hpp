#ifndef palindromes_hpp
#define palindromes_hpp

#include <string>

int min(int a, int b){
    return (a < b) ? a : b;
}

void FindLongestPalindrome(std::string text, int* val){
    int C = 0;
    int R = 0;
    int N = text.length();
    for(int i = 0; i < N - 1; i++) {
        int mirror = 2 * C - i;
        if(i < R){
            val[i] = min(R - i, val[mirror]);
        }

        int a = text[i + (1 + val[i])];
        int b = text[i - (1 + val[i])];
        while(a == b){
            val[i]++;
            a = text[i + (1 + val[i])];
            b = text[i - (1 + val[i])];
        }
        if((i + val[i]) > R){
            C = i;
            R = i + val[i];
        }
    }
}

#endif
