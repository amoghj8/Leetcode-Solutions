// 1254. Number of Closed Islands

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        for(int i=0;i<rows;i++) {
            if(!grid[i][0])
                dfsToOne(grid,i,0);
            if(!grid[i][cols-1])
                dfsToOne(grid,i,cols-1);
        }
        
        for(int j=0;j<cols;j++) {
            if(!grid[0][j])
                dfsToOne(grid,0,j);
            if(!grid[rows-1][j])
                dfsToOne(grid,rows-1,j);
        }
        int result = 0;
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(!grid[i][j]) {
                    dfs(grid,i,j);
                    result+=1;
                }
            }
        }
        return result;
    }
    
private:
    
    void dfsToOne(vector<vector<int>>& grid,int i, int j) {
        int rows = grid.size();
        int cols = grid[0].size();
        if(i>=0 && i<rows && j>=0 && j<cols && !grid[i][j]) {
            grid[i][j] = 1;
            dfsToOne(grid,i-1,j);
            dfsToOne(grid,i+1,j);
            dfsToOne(grid,i,j-1);
            dfsToOne(grid,i,j+1);
        }
    }
    
    void dfs(vector<vector<int>>& grid,int i, int j) {
        int rows = grid.size();
        int cols = grid[0].size();
        if(i>=0 && i<rows && j>=0 && j<cols && !grid[i][j]) {
            grid[i][j] = 1;
            dfs(grid,i-1,j);
            dfs(grid,i+1,j);
            dfs(grid,i,j-1);
            dfs(grid,i,j+1);
        }
    }
};