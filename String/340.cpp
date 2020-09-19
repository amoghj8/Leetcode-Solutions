// Longest Substring with At Most K Distinct Characters
if(!s.size())
            return 0;
        string temp;
        int result = 0;
        int j = 0;
        for(int i=0;i<s.size();i++) {
            temp.append(string(1,s[i]));
            unordered_map<char,int> m;
            for(auto ch:temp) {
                m[ch]++;
            }
            if(m.size()<=k) {
                result = max(result,(int)temp.size());
            }
            else {
                while(m.size()>k) {
                    m[temp[j]]--;
                    if(!m[temp[j]]) {
                        m.erase(temp[j]);
                    }
                    temp.erase(j,1);
                }
            }
        }
        return result;