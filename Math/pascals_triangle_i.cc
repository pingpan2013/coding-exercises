/*
 * =====================================================================================
 *
 *       Filename:  pascals_triangle_i.cc
 *
 *    Description:  generate pascal's triangle given num n
 *
 *        Created:  02/19/2015 11:56:24
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        if(numRows <= 0)    return res;
        
        res.resize(numRows);
        
        for(int i = 0; i < numRows; i ++){
            res[i].resize(i+1);
            
            res[i][0] = 1;
            res[i][res[i].size() - 1] = 1;
            
            for(int j = 1; j < res[i].size() - 1; j++){
                res[i][j] = res[i-1][j] + res[i-1][j-1];
            }
        }
        
        return res;
    }
};


