// 922. Sort Array By Parity II

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        
        unordered_map<int,vector<int>> um;
        for(auto num:A) {
            if(num&1) {
                um[1].push_back(num);
            }
            else {
                um[0].push_back(num);
            }
        }
        for(int i=0;i<A.size();i++) {
            if(!(i&1)) {
                A[i] = um[0].front();
                um[0].erase(um[0].begin());
            }
            else {
                 A[i] = um[1].front();
                um[1].erase(um[1].begin());
            }
        }
        return A;
        
    }
};