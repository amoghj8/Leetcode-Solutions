// 125. Valid Palindrome
#include <locale> 
class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> charVec;
        for(auto ch:s) {
            if(isalnum(ch)) {
                ch=toupper(ch);
                charVec.push_back(ch);
            }
        }
        
        for(int i=0,j=charVec.size()-1; i<j;i++,j--) {
            if(charVec[i]!=charVec[j]) {
                return false;
            }
        }
        return true;
                         
    }                    
};