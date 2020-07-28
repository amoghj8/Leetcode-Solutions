//1470. Shuffle the Array

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result(2*n,0);
        for(int i=0,j=0;j<n;i+=2,j+=1) {
            result[i] = nums[j];
        }
        for(int i=n,j=1;i<2*n;i+=1, j+=2) {
            result[j] = nums[i];
        }
        return result;
    }
};