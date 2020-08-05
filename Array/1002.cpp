// 1002. Find Common Characters

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> result;
        map<char,int> m;
        
        for(char ch:A[0]) {
            m[ch]++;
        }
        
        for(int i=1;i<A.size();i++) {
            map<char,int>::iterator it;
            for(it=m.begin();it!=m.end();it++) {
                int rep = count(A[i].begin(),A[i].end(),it->first);
                if(rep) {
                    it->second = min(rep,it->second);
                }
                else {
                    it->second = 0;
                }
            }
        }
        map<char,int>::iterator k;
        for(k=m.begin();k!=m.end();k++) {
            if(k->second!=0) {
                int temp = k->second;
                while(temp) {
                    result.push_back(string(1,k->first));
                    temp--;
                }
            }
        }
        return result;
    }
};