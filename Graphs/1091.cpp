// 1091. Shortest Path in Binary Matrix

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if(grid[0][0] || grid[rows-1][cols-1])
            return -1;
       
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(grid[i][j])
                    grid[i][j]=INT_MIN;
                else{
                    grid[i][j]=INT_MAX;
                }
            }
        }
        
        vector<vector<int>> dirs {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 0;
        
        while(!q.empty()) {
            int curr_X = q.front().first;
            int curr_Y = q.front().second;
            q.pop();
            if(curr_X==rows-1 && curr_Y==cols-1)
                break;
            for(auto dir:dirs) {
                int x = curr_X+dir[0];
                int y = curr_Y+dir[1];
                if(x<0 || x>=rows || y<0 || y>=cols || grid[x][y]==INT_MIN) {
                    continue;
                }
                if(grid[x][y]<=grid[curr_X][curr_Y]+1)
                    continue;
                q.push(make_pair(x,y));
                grid[x][y] = grid[curr_X][curr_Y]+1;
                
            }
            
        }
        
        if(grid[rows-1][cols-1]==INT_MAX)
            return -1;
        return grid[rows-1][cols-1]+1;
        
    }
};