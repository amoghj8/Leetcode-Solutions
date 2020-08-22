// 3. Longest Substring Without Repeating Characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<2)
            return s.size();
        unordered_map<string,int> m;
        string prefix = string(1,s[0]);
        m[prefix] = 1;
        for(int i=1;i<s.size();i++) {
            int index;
            if((index = prefix.find(string(1,s[i])))!=string::npos) {
                prefix = prefix.substr(index+1, i-index-1);
                prefix+= string(1,s[i]);
                m[prefix] = prefix.size();
            }
            else {
                prefix += string(1,s[i]);
                m[prefix] = prefix.size();
            }
        }
        unordered_map<string,int>:: iterator it;
        int maxLength = 0;
        for(it=m.begin();it!=m.end();it++) {
            maxLength = max(maxLength, it->second);
        }
        return maxLength;
    }
};