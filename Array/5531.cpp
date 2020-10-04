// 5531. Special Array With X Elements Greater Than or Equal X

class Solution {
public:
    int specialArray(vector<int>& nums) {
        
        for(int i=0;i<=nums.size();i++) {
            int count = 0;
            for(auto num:nums) {
                if(num>=i)
                    count++;
            }
            if(count==i)
                return i;
        }
        
        return -1;
    }
};