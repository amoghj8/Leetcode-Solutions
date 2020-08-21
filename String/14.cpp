// 14. Longest Common Prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size())
            return "";
        else if(strs.size()==1)
            return strs[0];
        else if(strs[0]=="")
            return "";
        
        string result = strs[0];
        string firstString  = strs[0];
        
        for(int i=firstString.size()-1;i>-1;i--) {
            
            bool charPresent = true;
            char charCheck = firstString.at(i);
            
            for(int j=1;j<strs.size();j++) {
                string temp =  strs[j];
                if(temp.size()<=i) {
                        charPresent=false;
                        break;  
                }
                else if(temp.at(i)!=charCheck) {
                        charPresent=false;
                        break;
                }
            }
            if(!charPresent)
                result = result.substr(0,i);
        }
        
        return result;
        
    }
};