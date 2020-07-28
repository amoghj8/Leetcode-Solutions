//1295. Find Numbers with Even Number of Digits

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int total=0;
        for(auto x : nums) {
            if(!(to_string(x).length()&1)) {
                total+=1;
            }
        }
        return total;
    }
};