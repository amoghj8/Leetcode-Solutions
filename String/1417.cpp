// 1417. Reformat The String

class Solution {
public:
    string reformat(string s) {
        int alphaCount = 0;
        int numCount = 0;
        vector<char> al;
        
        for(auto ch:s) {
            if(isalpha(ch)) {
                alphaCount++;
                al.push_back(ch);
            }
            else {
                numCount++;
                al.insert(al.begin(),ch);
            }
        } 
        if(abs(alphaCount-numCount)>1)
            return "";
        int i=0,j=s.size()-1;
        string result;
        if(numCount>alphaCount) {
            while(i<j) {
            result+= string(1,al[i++]) + string(1,al[j--]);
            }
        }
        else {
            while(i<j) {
            result+= string(1,al[j--]) + string(1,al[i++]);
            }
        }
        if(i==j) {
            result+=al[i];  
        }
        return result;
    }
};