// 1380. Lucky Numbers in a Matrix

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> transpose(col, vector<int>(row));
        set<int> minEleR;
        
        for(int i=0;i<row;i++) {
                minEleR.insert(*min_element(matrix[i].begin(), matrix[i].end()));
        }
        
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                transpose[j][i] = matrix[i][j];
            }
        }
        
        for(int i=0;i<col;i++) {
            set<int>::iterator it;    
            it = minEleR.find(*max_element(transpose[i].begin(), transpose[i].end()));
            if(it!=minEleR.end()) {
                res.push_back(*it);
            }
        }
        
        return res;
    }
};