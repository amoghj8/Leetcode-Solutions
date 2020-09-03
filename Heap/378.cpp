// 378. Kth Smallest Element in a Sorted Matrix

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
         multiset <int> ms;
         for(int i=0;i<matrix.size();i++) {
             for(int j=0;j<matrix[0].size();j++) {
                 ms.insert(matrix[i][j]);
             }
         }
        for(int i=0;i<k-1;i++) {
            ms.erase(ms.begin());
        }
        return *ms.begin();
    }
};