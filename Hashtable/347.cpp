class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        vector<int> result;
        int maxCount = -1;
        for(auto num:nums) {
            um[num]++;
            maxCount = max(maxCount,um[num]);
        }
        vector<int> arr[maxCount];
        for(auto it=um.begin();it!=um.end();it++) {
            arr[it->second-1].push_back(it->first);
        }
        bool flag = true;
        for(int i=maxCount-1;flag;i--) {
            int j=arr[i].size()-1;
            while(k&&j>-1) {
                result.push_back(arr[i][j--]);
                k--;
                if(!k){
                    flag = false;
                    break;
                }
            }
        }
        return result;
    }
};
