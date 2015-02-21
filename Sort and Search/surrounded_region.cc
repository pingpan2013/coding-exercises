/*
 * =====================================================================================
 *
 *       Filename:  surrounded_region.cc
 *
 *    Description:  surrounded region
 *
 *        Created:  02/20/2015 23:48:13
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    // intuitively, we should use DFS or BFS to solve this kind of problem
    void solve(vector<vector<char>> &board) {
        if(board.empty() || board[0].empty())   return;
        
        int row = board.size();
        int col = board[0].size();
        
        for(int i = 0; i < row; i++){
            if(board[i][0] == 'O'){
                board[i][0] = '#';
                dfs(board, i, 0, row, col);
            }
            
            if(board[i][col-1] == 'O'){
                board[i][col-1] = '#';
                dfs(board, i, col-1, row, col);
            }
        }
        
        for(int i = 0; i < col; i++){
            if(board[0][i] == 'O'){
                board[0][i] = '#';
                dfs(board, 0, i, row, col);
            }
            
            if(board[row-1][i] == 'O'){
                board[row-1][i] = '#';
                dfs(board, row-1, i, row, col);
            }
        }
        
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++){
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        
        return;
    }
    
private:
    void dfs(vector<vector<char>> &board, int i, int j, int row, int col){
        //if(i == row || j == col)    return;        
    
        // up, attention: i > 1 not i >= 1 since the first row has already been vistied, similiar with the following conditions
        if(i > 1 && board[i-1][j] == 'O'){
            board[i-1][j] = '#';
            dfs(board, i-1, j, row, col);
        }
        
        // down
        if(i < row-2 && board[i+1][j] == 'O' ){
            board[i+1][j] = '#';
            dfs(board, i+1, j, row, col);
        }
        
        // left
        if(j > 1 && board[i][j-1] == 'O'){
            board[i][j-1] = '#';
            dfs(board, i, j-1, row, col);
        }
        
        // right
        if(j < col-2 && board[i][j+1] == 'O'){
            board[i][j+1] = '#';
            dfs(board, i, j+1, row, col);
        }
    }
};


