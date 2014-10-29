/*
 * =====================================================================================
 *    Description:  Given an array and a value, remove all instances of
 *                  that value in place and return the new length
 *
 *        Created:  09/27/2014 10:55:26 AM
 *       Compiler:  g++ 4.7.0
 * =====================================================================================
 */

#include <iostream>

using namespace std;

class Solution{
    public:
        // use two pointers
        unsigned removeElement(int A[],int n, int target){
            unsigned length = 0;
            for(size_t i = 0; i < n; i ++){
                if(A[i] == target)
                    continue;
                // it doesnt matter what leaves beyond the new length
                A[length] = A[i];
                length ++;
            }
            return length;
        }
}



