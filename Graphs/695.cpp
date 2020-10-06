// 695. Max Area of Island

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        if(!rows)
            return 0;
        int cols = grid[0].size();

        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        int result = 0;
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(grid[i][j] && !visited[i][j]) {
                    int count=0;
                    dfs(grid,i,j,visited,count,result);
                }
            }
        }
    
        return result;
    }
private:
    void dfs(vector<vector<int>>& grid, int i, int j,vector<vector<bool>> &visited,int &count, int &result) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if(i>=0 && i<rows && j>=0 && j<cols && grid[i][j] && !visited[i][j]) {
            count++;
            result = max(result, count);
            visited[i][j]= true;
            dfs(grid,i,j-1,visited,count, result);
            dfs(grid,i,j+1,visited,count, result);
            dfs(grid,i-1,j,visited,count, result);
            dfs(grid,i+1,j,visited,count, result);
        }
        
    }
};