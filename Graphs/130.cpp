// 130. Surrounded Regions

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int maxRow = board.size();
        
        if(!maxRow)
            return;
        int maxCol = board[0].size();
        
        if(!maxCol)
            return; 
        
        for(int i=0;i<maxRow;i++) {
            if(board[i][0]=='O')
                dfs(board,i,0);
            if(board[i][maxCol-1]=='O')
                dfs(board,i,maxCol-1);
        }
        
        for(int j=0;j<maxCol;j++) {
            if(board[0][j]=='O')
                dfs(board,0,j);
            if(board[maxRow-1][j]=='O')
                dfs(board,maxRow-1,j);
        }
        
        for(int i=0;i<maxRow;i++) {
            for(int j=0;j<maxCol;j++) {
                
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='#')
                    board[i][j]='O';
            }
        }
    }
private:
    void dfs(vector<vector<char>>&board,int i,int j) {
        int row = board.size();
        int col = board[0].size();
        
        if(i<0 || i>=row || j<0 || j>=col || board[i][j]!='O')
            return;
        
        board[i][j] = '#';
        
        dfs(board,i-1,j);
        dfs(board,i+1,j);
        dfs(board,i,j-1);
        dfs(board,i,j+1);

    }
};