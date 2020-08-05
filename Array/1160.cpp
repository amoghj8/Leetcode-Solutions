// 1160. Find Words That Can Be Formed by Characters


class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> count(26,0);
        int total=0;
        for(auto ch:chars) {
            ++count[ch-'a'];
        }
        
        for(auto word:words) {
            vector<int> c = count;
            bool flag = true;
            
            for(auto w:word) {
                if(--c[w-'a']<0) {
                    flag=false;
                    break;
                }
            }
            if(flag) {
               total+=word.size(); 
            }
            
        }
        
        return total;
        
    }
};