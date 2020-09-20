// 992. Subarrays with K Different Integers

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return helper(A,K)-helper(A,K-1);
    }
private:
    int helper(vector<int>&A, int K) {
        int result=0;
        int j=0;
        unordered_map<int,int> um;
        for(int i=0;i<A.size();i++) {
            um[A[i]]++;
            while(um.size()>K) {
                um[A[j]]--;
                if(!um[A[j]]) {
                    um.erase(A[j]);
                }
                j++;
             }
            result+= (i-j+1);
        }
        return result;
    }
};