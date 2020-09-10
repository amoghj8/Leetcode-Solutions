// 917. Reverse Only Letters

class Solution {
public:
    string reverseOnlyLetters(string S) {
        
        for(int i=0,j=S.size()-1;i<j;) {
            if(isalpha(S[i])&&isalpha(S[j])) {
                swap(S[i++],S[j--]);
            }
            else if(!isalpha(S[i])) {
                i++;
                continue;
            }
            else {
                j--;
                continue;
            }
        }
        return S;
    }
};