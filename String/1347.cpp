// 1347. Minimum Number of Steps to Make Two Strings Anagram

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> firstMap,secondMap;
        for(int i=0;i<s.size();i++) {
            firstMap[s[i]]++;
            secondMap[t[i]]++;
        }
        int comCount=0;
        for(auto it=firstMap.begin();it!=firstMap.end();it++) {
            if(secondMap.find(it->first)!=secondMap.end()) {
                comCount += min(it->second, secondMap[it->first]);
            }
        }        
        return s.size()-comCount;
    }
};