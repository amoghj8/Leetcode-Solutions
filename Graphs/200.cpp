// 200. Number of Islands

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        if(!grid.size())
            return 0;
        vector<vector<bool>> visited (grid.size(), vector<bool>(grid[0].size(), false));
        int result = 0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(!visited[i][j]) {
                   dfs(grid,i,j,visited);
                    if(grid[i][j]=='1')
                        result+=1;
                }
            }
        }
        return result;
    }
    
private:
    void dfs(vector<vector<char>>&grid, int i, int j,vector<vector<bool>>&visited) {
        int row = grid.size();
        int col = grid[0].size();
        
        if(i<0 || i>=row || j<0 || j>=col || grid[i][j]=='0')
            return;
        
        if(visited[i][j])
            return;
        visited[i][j] = true;
        
        dfs(grid,i+1,j,visited);
        dfs(grid,i-1,j,visited);
        dfs(grid,i,j-1,visited);
        dfs(grid,i,j+1,visited);
    }
};