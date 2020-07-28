// 1313. Decompress Run-Length Encoded List

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> result;
        for(int i=0;i<nums.size();i+=2) {
           int j=nums[i];
                while(j) {
                    result.push_back(nums[i+1]);
                    j--;
                }
        }
        return result;
    }
};