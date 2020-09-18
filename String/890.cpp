// 890. Find and Replace Pattern

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<int> v(26,0);
        unordered_map<int,int> um;
        vector<string> result;
        for(int i=0;i<pattern.size();i++) {
            v[pattern[i]-'a']++;
        }
        for(int i=0;i<26;i++) {
            um[v[i]]++;
        }
        for(int i=0;i<words.size();i++) {
            if(words[i].size()!=pattern.size())
                continue;
            vector<int> vec(26,0);
            string word = words[i];
            for(int j=0;j<word.size();j++) {
                vec[word[j]-'a']++;
            }
            unordered_map<int,int> x ;
            for(int k=0;k<vec.size();k++) {
                x[vec[k]]++;
            }
            if(um==x) {
               bool flag = verify(pattern,word);
                if(flag)
                    result.push_back(word); 
            }
                
        }
        return result;
    }
private:
    bool verify(string &pattern, string &word) {
            unordered_map<char,char> um;
            for(int i=0;i<pattern.size();i++) {
                auto it = um.find(pattern[i]);
                if(it==um.end()) {
                    um[pattern[i]] = word[i];
                    continue;
                }
                else if(it->second!=word[i])
                    return false;
                
            }
        return true;
    }
    
};