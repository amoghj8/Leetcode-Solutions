// 1248. Count Number of Nice Subarrays

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return odd(nums,k)-odd(nums,k-1);
    }
private:
    int odd(vector<int>&nums,int k) {
        int count=0;
        int j=0;
        int result=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]&1)
               count++;
            while(count>k) {
               if(nums[j]&1) {
                    count--;
               }
                j++;
            }
            result+=(i-j+1);
        }
        return result;
    }
};