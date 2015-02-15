/*
 * =====================================================================================
 *
 *       Filename:  jump_game.cc
 *
 *    Description:  jump game
 *
 *        Created:  02/15/2015 16:22:42
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    bool canJump(int A[], int n) {
        if(n <= 1)  return true;
        
        int i = 0;
        while(i < n){
            // if A[i] == 0, stop here forever
            if(A[i] == 0)   return false;
            
            // max_jump is the maximum range in position A[i]
            int max_jump = A[i] + i;
            for(int k = i; k < max_jump; k++){
                if(A[k] + k >= n-1) return true;
                
                max_jump = max(max_jump, A[k] + k);
            }
            
            i = max_jump;
        }
        
        return false;
    }
};
