// 1162. As Far from Land as Possible

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        queue<pair<int,int>> q;
         
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(grid[i][j])
                    q.push(make_pair(i,j));
            }
        }
        
        vector<pair<int,int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        int result = 0;
        
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto p = q.front();
                q.pop();
                for(auto dir:dirs) {
                    int x = p.first+dir.first;
                    int y = p.second+dir.second;
                    if(x>=0 && x<rows && y>=0 && y<cols && !grid[x][y]) {
                        q.push(make_pair(x,y));
                        grid[x][y]=1;
                    }
                } 
            }
            result++;
        }
        
        return result==1?-1:result-1;
        
    }
};