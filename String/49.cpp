// 49. Group Anagrams
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        vector<vector<string>> result;
        for(auto word: strs) {
            string w = word;
            sort(w.begin(),w.end());
            m[w].push_back(word);
        }
        map<string,vector<string>>::iterator it;
        for(it=m.begin();it!=m.end();it++) {
            result.push_back(it->second);
        }
        return result;
    }
};