/*
 * =====================================================================================
 *
 *       Filename:  single_number_ii.cc
 *
 *    Description:  single number ii using bit manipulation
 *
 *        Created:  02/21/2015 11:49:25
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    // basic idea, count the number of 1s for all intergets bit by bit and
    // then to check if it can be divided by 3, if so, this bit of the result should be 0
    // otherwise it should 1
    int singleNumber(int A[], int n) {
        int r = 0;
        
        for(int i = 0; i < 32; i++){
            int b = 1 << i;
            int cnt = 0;
            
            for(int i = 0; i < n; i++){
                if(A[i] & b){
                    cnt++;
                }
            }
            
            if(cnt%3){
                r |= b;
            }
        }
        
        return r;
    }
};


