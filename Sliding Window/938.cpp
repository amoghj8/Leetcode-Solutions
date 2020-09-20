// 930. Binary Subarrays With Sum

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        return atMost(A,S)-atMost(A,S-1);
    }
private:
    int atMost(vector<int> &A, int S) {
        if(S<0)
            return 0;
        int j=0;
        int result = 0;
        int sum=0;
        for(int i=0;i<A.size();i++) {
            sum+=A[i];
            while(sum>S) {
                sum-=A[j++];
            }
            result = result+i-j+1;
        }
        return result;
    }
};