/*
 * =====================================================================================
 *
 *       Filename:  set_matrix.zeros.cc
 *
 *    Description:  set matrix 0s in place
 *
 *        Created:  02/16/2015 00:38:17
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        if(m == 0)  return;
        
        int n = matrix[0].size();
        if(n == 0)  return;
        
        // first row
        int first_row = -1;
        for(int i = 0; i < n; i++){
            if(matrix[0][i] == 0) first_row = 0;
        }
        
        // first col
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0)   matrix[0][0] = 0;
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        
        // set rows to 0
        for(int i = 1; i < m; i++){
            if(matrix[i][0] == 0){
                fill(matrix[i].begin(), matrix[i].end(), 0);
            }
        }
        
        // set columns to 0
        for(int i = 0; i < n; i++){
            if(matrix[0][i] != 0) continue;
            
            for(int j = 0; j < m; j++){
                matrix[j][i] = 0;
            }
        }
        
        // set first row
        if(first_row == 0){
            fill(matrix[0].begin(), matrix[0].end(), 0);
        }
        
        return;    
    }
};
