/*
 * =====================================================================================
 *
 *       Filename:  sort_colors.cc
 *
 *    Description:  sort colors in place
                    Given an array with n objects colored red, white or blue, sort them 
                    so that objects of the same color are adjacent, with the colors in 
                    the order red, white and blue.

                    Here, we will use the integers 0, 1, and 2 to represent the color 
                    red, white, and blue respectively. 
 *
 *        Created:  02/16/2015 11:02:28
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    void sortColors(int A[], int n) {
        if(n <= 1)  return;
        
        int i = 0;
        
        int red = 0;
        int blue = n-1;
        
        while(i <= blue){  // blue is keeping changing within the loop in case of infinite loop
            if(A[i] == 0){
                swap(A[i], A[red++]);   // we know that current A[red] is 1, so we move on i in the following
            }
            
            if(A[i] == 2){
                swap(A[i], A[blue--]);  // not sure what A[blue] is, so continue to check A[i] after swapping
                continue;
            }
            
            // if A[i] == 1 or A[i] == 0
            i++;  
        }
       
    }
};
