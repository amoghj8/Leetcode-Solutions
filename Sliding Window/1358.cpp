// 1358. Number of Substrings Containing All Three Characters

class Solution {
public:
    int numberOfSubstrings(string s) {
        int j=0;
        int result = 0;
        unordered_map<char,int> um;
        for(int i=0;i<s.size();i++) {
            um[s[i]]++;
            while(um.size()>2) {
                um[s[j]]--;
                if(!um[s[j]])
                    um.erase(s[j]);
                j++;
            }
            result+=i-j+1;
        }
        long long int length = s.size();
        long long int  total = (length*(length+1))/2;
        return (int) (total - (long long int)result);
    }
};