// 1431. Kids With the Greatest Number of Candies

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        int greatestNumber = INT_MIN;
        for(auto candy:candies) {
            if(candy>greatestNumber) {
                greatestNumber = candy;
            }
        }
        for(int i=0;i<candies.size();i++) {
            (candies[i]+extraCandies>=greatestNumber) ? result.push_back(true) : result.push_back(false);
        }
        return result;
    }
};