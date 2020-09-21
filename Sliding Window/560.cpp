// 560. Subarray Sum Equals K

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int preSum=0;
        int result=0;
        unordered_map<int,int> um{{0,1}};
        for(int i=0;i<nums.size();i++) {
            preSum+=nums[i];
            if(um.find(preSum-k)!=um.end()) {
                result+= um[preSum-k];
            }
            um[preSum]++;
        }
        return result;
    }
};