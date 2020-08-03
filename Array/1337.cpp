// 1337. The K Weakest Rows in a Matrix

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> ones;
        for(int i=0;i<mat.size();i++) {
            int col_val = 0;
            for_each(mat[i].begin(),mat[i].end(),[&](int i) {
                col_val+=i;
            });
            ones.push_back(make_pair(i,col_val));
        }
        sort(ones.begin(),ones.end(),[](pair<int,int>a, pair<int,int>b) {
            if(a.second!=b.second) {
                return a.second<b.second;
            }
            else {
                return a.first<b.first;
            }
        });
        vector<int> result;
        for(int i=0;i<k;i++) {
            result.push_back(ones[i].first);
        }
        return result;
    }
};