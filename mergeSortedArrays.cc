/*
 * =====================================================================================
 *           Desc:  Given two sorted arrays A and B, merge B into A as one sorted array.
 *                  Assume that A has enough sapce to hold additional elements from B.
 *        Created:  09/20/2014 05:36:08 PM
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */


#include <iostream>

using namespace std;

class Solution{
public:    
    void mergeTwoArrays(int A[], int m, int B[], int n){
        int i = 0;
        int j = 0;

        while(i < m && j < n){
            if(A[i] <= B[j])
                i++;
            
            else if(A[i] > B[j]){
                cout << A[i] << B[j] << endl;
                // push items in A[] back by one element
                for(int k = m+i-1; k > i; k--)
                    A[k] = A[k-1];
                A[i] = B[j];
                j++;
                // Remember to increase i by 1 because the array was pushed back by 1 element
                i++;
            }
        }

        // display result array A[]
        for(int i = 0; i < m+n; i ++)
            cout << A[i] << " ";
        cout << endl;
    }
};

int main(){
    int A[] = {1, 3, 6, 9};
    int B[] = {2, 3, 4, 8};
    Solution sol;
    sol.mergeTwoArrays(A, 4, B, 4);
    return 0;
}



