// 643. Maximum Average Subarray I

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double result = INT_MIN;
        int i=0,j=0;
        double sum=0;
        int count = 0;
        while(j<nums.size()) {
            if(count==k) {
                result = max(result, sum/k);
                sum-=nums[i++];
                sum+=nums[j++];
                count--;
            }
            else {
                sum+=nums[j++];
            }
            count ++;
        }
        result = max(result, sum/k);
        return result;
    }
};