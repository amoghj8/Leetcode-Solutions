// 713. Subarray Product Less Than K

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int j=0;
        int product = 1;
        int result = 0;
        for(int i=0;i<nums.size();i++) {
            product*=nums[i];
            while(j<=i && product>=k) {
                product/=nums[j++];
            }
            result+= i-j+1;
        }
        return result;
    }
};