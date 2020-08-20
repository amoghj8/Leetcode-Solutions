// 28. Implement strStr()

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()>haystack.length())
            return -1;
        else if(!haystack.size() && !needle.size())
            return 0;
        else if(haystack.size() && !needle.size())
            return 0;
        
        for(int i=0;i<=haystack.length()-needle.length();i++) {
            string substring = haystack.substr(i,needle.length());
            if(substring == needle)
                return i;
        }
        
        return -1;
    }
};