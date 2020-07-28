// 1365. How Many Numbers Are Smaller Than the Current Number

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> result;
        for(int i=0;i<nums.size();i++) {
            int lessCount = 0;
            for(int j=0;j<nums.size();j++) {
                if(nums[i]>nums[j]) {
                    lessCount++;
                }
            }
            result.push_back(lessCount);
        }
        return result;
    }
};