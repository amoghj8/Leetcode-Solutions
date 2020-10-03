// 1020. Number of Enclaves

class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        
        int rows = A.size();
        int cols = A[0].size();
        
        for(int i=0;i<rows;i++) {
            if(A[i][0])
                dfsToOne(A,i,0);
            if(A[i][cols-1])
                dfsToOne(A,i,cols-1);
        }
                
        for(int j=0;j<cols;j++) {
            if(A[0][j])
                dfsToOne(A,0,j);
            if(A[rows-1][j])
                dfsToOne(A,rows-1,j);
        }
        
        vector<vector<bool>> visited(rows, vector<bool>(cols,false));
        int result = 0;
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(!visited[i][j] && A[i][j]) {
                    dfs(A,visited,i,j,result);
                }
            }
        }
        
        return result;
    }
    
    void dfsToOne(vector<vector<int>>& A, int i, int j) {
        
        int rows = A.size();
        int cols = A[0].size();
        
        if(i<0 || i>=rows || j<0 || j>=cols || !A[i][j])
            return;
        
        A[i][j]=0;
        
        dfsToOne(A,i-1,j);
        dfsToOne(A,i+1,j);
        dfsToOne(A,i,j-1);
        dfsToOne(A,i,j+1);
    }
    
    void dfs(vector<vector<int>>& A,vector<vector<bool>>& visited, int i, int j, int &result) {
        int rows = A.size();
        int cols = A[0].size();
        
        if(i<0 || i>=rows || j<0 || j>=cols || !A[i][j])
            return;
        
        if(visited[i][j])
            return;
        
        visited[i][j]=true;
        
        result+=1;
        
        dfs(A,visited,i-1,j,result);
        dfs(A,visited,i+1,j,result);
        dfs(A,visited,i,j+1,result);
        dfs(A,visited,i,j-1,result);
        
    }
    
};