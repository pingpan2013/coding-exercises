/*
 * =====================================================================================
 *
 *       Filename:  word_search.cc
 *
 *    Description:  Given a 2D board and a word, find if the word exists in the grid.

                    The word can be constructed from letters of sequentially adjacent 
                    cell, where "adjacent" cells are those horizontally or vertically 
                    neighboring. The same letter cell may not be used more than once.

                    For example,
                    Given board =

                    [       
                        ["ABCE"],
                        ["SFCS"],
                        ["ADEE"]
                    ]

                    word = "ABCCED", -> returns true,
                    word = "SEE", -> returns true,
                    word = "ABCB", -> returns false.
 *
 *
 *
 *        Created:  01/26/2015 00:15:06
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
*/

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(board.empty() || board[0].empty())   return word == "";
        
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0] && dfs(board, word, 0, i, j))
                    return true;
            }
        }
        
        return false;
    }
    
private:
    bool dfs(vector<vector<char> > &board, string &word, int cnt, int row, int col){
        if(cnt == word.size()-1){
            return true;
        }
        
        if(cnt >= word.size()) return false;
        
        // attention, the same letter cell may not be used more than once,
        // we use '*' to indicate that the cell has been visited
        char c = board[row][col];
        board[row][col] = '*';
        
        // 4 choices
        // up
        if(row >= 1 && board[row-1][col] == word[cnt+1]){
            if(dfs(board, word, cnt+1, row-1, col))  return true;
        }
        
        // down
        if(row+1 < board.size() && board[row+1][col] == word[cnt+1]){
            if(dfs(board, word, cnt+1, row+1, col)) return true;
        }
        
        // left
        if(col >= 1 && board[row][col-1] == word[cnt+1]){
            if(dfs(board, word, cnt+1, row, col-1)) return true;
        }
        
        // right
        if(col+1 < board[0].size() && board[row][col+1] == word[cnt+1]){
            if(dfs(board, word, cnt+1, row, col+1)) return true;
        }
        
        board[row][col] = c;
        return false;
    }
};




