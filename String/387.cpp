// 387. First Unique Character in a String

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> charVec(26,INT_MIN);
        
        for(int i=0;i<s.size();i++) {
            if(charVec[s[i]-'a']==INT_MIN) {
                charVec[s[i]-'a'] = 0;
            }
            else {
                charVec[s[i]-'a']++;
            }
        }
        
        for(int i=0;i<s.size();i++) {
            if(!charVec[s[i]-'a'])
                return i;
        }
        
        return -1;
    }
};