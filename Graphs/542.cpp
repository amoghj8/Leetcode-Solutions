// 542. 01 Matrix

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(!matrix[i][j]) {
                    q.push(make_pair(i,j));
                    continue;
                }
                matrix[i][j] = INT_MAX;
            }
        }
        
        vector<vector<int>> dir {{1,0},{-1,0},{0,1},{0,-1}};
        
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            for(auto moves:dir) {
                int x = p.first+moves[0];
                int y = p.second+moves[1];
                
                if(x<0 || x>=rows || y<0 || y>=cols || matrix[x][y]<=matrix[p.first][p.second]+1)
                    continue;
                
                q.push(make_pair(x,y));
                
                matrix[x][y] = matrix[p.first][p.second]+1;
                
            }
            
        }
        
        return matrix;
        
    }
    
    
};