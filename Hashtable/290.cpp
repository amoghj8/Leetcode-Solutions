// 290. Word Pattern

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if(!str.size() && pattern.size())
            return false;
        else if(!pattern.size() && str.size())
            return false;
        
        set<char> ptSet;
        set<string> strSet;
        vector<string> vecString;
        
        if(charSet(pattern,ptSet)!=stringSet(str,strSet,vecString))
            return false;
        if(pattern.size()!=vecString.size())
            return false;
        
        unordered_map<char,string> charStringMap;
        unordered_map<string,char> stringCharMap;        
        
        istringstream ss(str);
        int i=0;
        do {
            string word;
            ss >> word;
            if(charStringMap.find(pattern.at(i))==charStringMap.end()) {
                if(stringCharMap.find(word)!=stringCharMap.end())
                    return false;
                stringCharMap[word] = pattern.at(i);
                charStringMap[pattern.at(i)] = word;
                i++;
            }
            else if(charStringMap.find(pattern.at(i))!=charStringMap.end()) {
                if(stringCharMap.find(word)==stringCharMap.end())
                    return false;
                else if(stringCharMap[word]!=pattern.at(i))
                    return false;
                i++;
            }
            
        }while(i<pattern.length() && ss);
        
        return true;
    }
private:
    int charSet(string s, set<char>&st) {
        for(int i=0;i<s.size();i++) {
            st.insert(s.at(i));
        }
        return st.size();
    }
    
    int stringSet(string s, set<string> &st,vector<string> &vec) {
        istringstream ss(s);
        do{
            string word;
            ss >> word;
            if(word!="") {
                st.insert(word);
                vec.push_back(word);
            }
        }while(ss);
        return st.size();
    }
};