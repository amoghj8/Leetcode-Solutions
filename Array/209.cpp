// 209. Minimum Size Subarray Sum

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum=0;
        int j=0;
        int result = INT_MAX;
        for(int i=0;i<nums.size();i++) {
            sum+=nums[i];
            if(sum>=s) {
                while(sum>=s) {
                    result = min(result,i-j+1);
                    sum-=nums[j++];
                }
            }
        }
        if(result!=INT_MAX)
            return result;
        return 0;
    }
};
