// 532. K-diff Pairs in an Array

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        
        int j=0;
        int temp=0;
        set<pair<int,int>> s;
        for(int i=1;i<nums.size();i++) {
            temp=nums[i];
            
            while(i<nums.size() && j<=i && temp-nums[j]<k) {
                i++;
                if(i<nums.size())
                    temp = nums[i];
            }
            
            while(j<=i && temp-nums[j]>k) {
                j++;
            }
            if(i!=j && temp-nums[j]==k) {
                s.insert(make_pair(nums[j],nums[i]));
                continue;
            }
            else 
                continue;
        }
        return s.size();
    }
};