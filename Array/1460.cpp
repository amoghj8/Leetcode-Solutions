// 1460. Make Two Arrays Equal by Reversing Sub-arrays

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int, int> m;
        for(int i=0;i<arr.size();i++) {
            m[arr[i]]++;
        }
        for(auto y:target) {
            map<int,int>::iterator it;
            it=m.find(y);
            if(it==m.end() || it->second==0) {
                return false;
            }
            it->second--;
            
        }
        return true;
    }
};