// 1464. Maximum Product of Two Elements in an Array


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int firstLargest = nums[0];
        int secondLargest = INT_MIN;
        for(int i=1;i<nums.size();i++) {
            if(nums[i]>firstLargest) {
                secondLargest = firstLargest;
                firstLargest = nums[i];
            }
            else if((firstLargest>nums[i]) && (nums[i]>secondLargest)) {
                secondLargest = nums[i];
            }
            else if(firstLargest==nums[i]) {
                firstLargest = secondLargest =nums[i];
            }
        }
        return (firstLargest-1)*(secondLargest-1);
    }
};