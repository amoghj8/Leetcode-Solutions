// 1003. Check If Word Is Valid After Substitutions

class Solution {
public:
    bool isValid(string s) {
        string toFind = "abc";
        while(s.size()) {
            auto it  = s.find(toFind);
            if(it==string::npos) {
                return false;        
            }
            s.erase(it, toFind.length());
        }
        return true;
    }
};