// 80. Remove Duplicates from Sorted Array II

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<3)
            return nums.size();
        int count=1;
        for(int i=1;i<nums.size();i++) {
            if(nums[i]==nums[i-1] && count==2) {
                nums.erase(nums.begin()+i);
                i--;
            }
            else if(nums[i]==nums[i-1])
                count++;
            else {
                count=1;
            }
        }
        return nums.size();
    }
};