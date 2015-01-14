/*
 * =====================================================================================
 *
 *       Filename:  word_search.cc
 *
 *    Description:  word search
 *
 *        Created:  01/13/2015 23:16:58
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(word.size() == 0)   return true;
        if(board.empty() || board[0].empty())  return false;
        
        // find the location of the first char in word
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    if(helper(board, word, 0, i, j))
                        return true;
                }
            }
                
        return false;
    }
    
private:
    bool helper(vector<vector<char> > &board, string &word, int cnt, int row, int col){
        // Attention: should be size()-1 instead of size() as usual since the first 
        // char was already matched when cnt = 0
        //
        // Tip: use a small testcase to determine the quantity
        if(cnt == word.size()-1)  return true;
        
        // already visited
        char c = board[row][col];
        board[row][col] = '*';        
        
        if(row > 0 && board[row-1][col] == word[cnt+1]){
            if(helper(board, word, cnt+1, row-1, col))  return true;
        }
        
        if(row < board.size()-1 && board[row+1][col] == word[cnt+1]){
            if(helper(board, word, cnt+1, row+1, col))  return true;
        }
        
        if(col > 0 && board[row][col-1] == word[cnt+1]){
            if(helper(board, word, cnt+1, row, col-1))  return true;
        }
        
        if(col < board[0].size()-1 && board[row][col+1] == word[cnt+1]){
            if(helper(board, word, cnt+1, row, col+1))  return true;
        }
        
        board[row][col] = c;
        
        return false;
    }
};



