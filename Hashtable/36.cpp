// 36. Valid Sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<string, int> m;
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                if(board[i][j]=='.')
                    continue;
                string s = string(1,board[i][j]);
                if(m.find(s+"row"+to_string(i))!=m.end())
                    return false;
                else if(m.find(s+"col"+to_string(j))!=m.end())
                    return false;
                else if(m.find(s+"box"+to_string(i/3)+to_string(j/3))!=m.end())
                    return false;
                else {
                    m[s+"row"+to_string(i)]++;
                    m[s+"col"+to_string(j)]++;
                    m[s+"box"+to_string(i/3)+to_string(j/3)]++;
                }
            }
        }
        return true;
    }
};