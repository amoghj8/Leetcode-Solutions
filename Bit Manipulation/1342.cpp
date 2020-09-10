// 1342. Number of Steps to Reduce a Number to Zero

class Solution {
public:
    int numberOfSteps (int num) {
        if(!num)
            return 0;
        vector<int> nums(num+1);
        nums[0] = 0;
        nums[1] = 1;
        
        for(int i=2;i<nums.size();i++) {
            if(i&1) {
                nums[i] = nums[i-1]+1;
            }
            else {
                nums[i] = nums[i/2]+1;
            }
        }
        return nums[num];
    }
};