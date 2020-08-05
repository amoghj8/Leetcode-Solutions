//1200. Minimum Absolute Difference

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int diff = INT_MAX;
        vector<vector<int>> res;
        for(int i=1;i<arr.size();i++) {
            diff = min(abs(arr[i]-arr[i-1]), diff);
        }
        
        for(int i=0;i<arr.size()-1;i++) {
            if(abs(arr[i]-arr[i+1])==diff) {
                res.push_back({arr[i],arr[i+1]});
            }
        }
        
        return res;
    }
};