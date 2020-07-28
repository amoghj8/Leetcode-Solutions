// 1512. Number of Good Pairs

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int, vector<int>> goodPairs;
        int result;
        for(int i=0;i<nums.size();i++) {
            goodPairs[nums[i]].push_back(i);
        }
        for(auto goodPair: goodPairs) {
            result += (goodPair.second.size())*(goodPair.second.size()-1)/2;
        }
        return result;
    }
};