/*
 * =====================================================================================
 *
 *       Filename:  pascals_triangle.cc
 *
 *    Description:  pascal's triangle
                    Given an index k, return the kth row of the Pascal's triangle.

                    For example, given k = 3,
                    Return [1,3,3,1].

                    Note:
                    Could you optimize your algorithm to use only O(k) extra space?

 *        Created:  02/05/2015 00:10:27
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */


class Solution {
public:
    // O(k) space
    vector<int> getRow(int rowIndex) {
        vector<int> res;
         
        for(int i = 0; i <= rowIndex; i++){
            res.resize(i+1, 1);
            
            for(int j = i-1; j >= 1; j--){
                res[j] = res[j] + res[j-1];
            }
        }
        
        return res;
    }
};


