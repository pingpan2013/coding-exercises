/*
 * =====================================================================================
 *
 *       Filename:  longest_consective_subsequence_in_2d_matrix.cc
 *
 *    Description:  longest consective subsequence in 2d matrix
 *                   
                    // Google interview question for Ma Xiao
                    Reference: https://github.com/caogl/Algorithms_practice                    
 
                    example:
                    input matrix                2d matrix storing max value of current node
                    2       3       4       5                       4       3       2       1
                    4       5       10      11    -----------       9       8       3       2
                    20      6       9       12    -----------       1       7       4       1
                    6       7       8       40                      7       6       5       1
                    Answer: 4-5-6-7-8-9-10-11-12 : 9
 
 *        Created:  02/22/2015 22:36:23
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution{
public:
    int longestConsectivePath(vector<vector<int> &matrix){
        if(matrix.empty() || matrix[0].empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();
        
        // kind of like the vistied matrix, it stores the current max length info at 
        // the same time
        vector<vector<int>> pathInfo(m, vector<int>(n, -1));

        // Complexity: O(m*n)
        int maxLen = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++){
                maxLen = max(maxLen, helper(matrix, pathInfo, i, j));
            }
        
        return maxLen;

private:
    int helper(vector<vector<int>> &matrix, int i, int j, vector<vector<int> &info){
        // never visited
        if(info[i][j] == -1){
            // Initialization
            info[i][j] = 1;

            // up
            if(i != 0 && matrix[i-1][j] == matrix[i][j] + 1){
                info[i][j] = max(info[i][j], helper(matrix, i-1, j, info) + 1); 
            }
            
            // do similar things for 
            //
            // down ... 
            // left ...
            // right ...
        }

        return info[i][j];
    }
};
