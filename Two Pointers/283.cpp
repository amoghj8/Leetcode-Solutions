// 283. Move Zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i=0,j=nums.size()-1;i<=j;i++) {
            if(nums[i]) {
                continue;
            }
            else {
                nums.erase(nums.begin()+i);
                i--;
                j--;
                nums.push_back(0);
            }
        }
    }
};