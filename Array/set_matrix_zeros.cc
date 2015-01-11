/*
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. 
 * Do it in place.
*/

class Solution {
public:
    // since it must be in place,
    // we first use the first row and column to store the status of each column and row
    // then change the submatrix and finally change the first row and column
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.empty())  return;
        if(matrix[0].empty())   return;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // indict if the first column needs to be set to 0
        // use first_r to indict the status of the first row
        int first_c = -1;
        int first_r = -1;
        
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0)   first_c = 0;
        }
        
        for(int i = 0; i < n; i++){
            if(matrix[0][i] == 0)   first_r = 0;
        }
        
        for(int i = 1; i < m; i ++)
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        
        // set 0s
        for(int i = 1; i < m; i ++){
            if(matrix[i][0] == 0){
                for(int j = 1; j < n; j++)
                    matrix[i][j] = 0;
            }
        }
        
        for(int j = 1; j < n; j ++){
            if(matrix[0][j] == 0){
                for(int i = 1; i < m; i++)
                    matrix[i][j] = 0;
            }
        }
        
        // handle the first row and column
        if(first_r == 0){
            for(int i = 0; i < n; i++)
                matrix[0][i] = 0;
        }
        
        if(first_c == 0){
            for(int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }
        
        return;
    }
};





