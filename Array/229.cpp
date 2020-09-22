// 229. Majority Element II

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(!nums.size())
            return {};
        
        int req = nums.size()/3;
        vector<int> result;
        int candidate1=-1,candidate2=-1;
        int count1=0, count2=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==candidate1)
                count1++;
            else if(nums[i]==candidate2)
                count2++;
            else if(!count1) {
                candidate1 = nums[i];
                count1++;
            }
            else if(!count2) {
                candidate2 = nums[i];
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }
        isMajority(nums,candidate1, req, result);
        isMajority(nums,candidate2, req, result);
        return result;
    }
private:
    void isMajority(vector<int>&nums, int &ele, int &req, vector<int>&result) {
        int count=0;
        for(int i=0;i<nums.size();i++) {
            if(ele==nums[i])
                count++;
        }
        if(count>req)
                result.push_back(ele);
    }
};