// 994. Rotting Oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int rows = grid.size();
        int cols = grid[0].size();
        int result=0;
        int freshFruits = 0;
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(grid[i][j]==2) {
                    q.push(make_pair(i,j));
                }
                else if(grid[i][j]==1)
                    freshFruits++;
            }
        }
    
    
        vector<vector<int>> dirs {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()) {
            int size = q.size();
            
            while(size--) {
                 pair<int,int> top = q.front();
                 q.pop();
                    for(auto dir:dirs) {


                        int x = top.first+dir[0];
                        int y = top.second+dir[1];

                        if(x>=0 && x<rows && y>=0 && y<cols && grid[x][y]==1) {
                            grid[x][y] = 2;
                            q.push(make_pair(x,y));
                            freshFruits--;
                        }

                    }
            
                }
            result++;
        }
        
        if(freshFruits)
            return -1;
        else if(!result)
            return 0;
        return result-1;
        
    }
};