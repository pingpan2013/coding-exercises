/*
 * =====================================================================================
 *           Desc:  Find the k-th smallest element of two unioned arrays,
 *                  the size of the two arrays are m and n respectively
 *        Created:  09/20/2014 05:36:08 PM
 *       Compiler:  g++ 4.7.0
 * =====================================================================================
 */


#include "binaryTree.h"
#include <iostream>
#include <cassert>
#include <climits>

using namespace std;

class Solution{
public:    
    // Method 1: the trvial way is to merge the two arrays 
    // and access the kth element directly. Time complexity O(m+n)
    // Need extra space

    // Method 2: Note to go one step further, consider the k+1 element
    // Time complixty, O(k)
    int findKthElement(int A[], int B[], int m, int n, int k){
        int i = 0;
        int j = 0;
        int flag = 0;
        
        if(k == 0)  return min(A[0], B[0]);
        if(k == 1)  return max(A[0], B[0]);
        assert(k < m + n);

        while(i + j + 2 <= k){
            if(A[i] < B[j]){
                i ++;
                flag = 1;
            }
            else{
                j ++;
                flag = 2;
            }
        }

        if(flag == 1){
            if(A[i] < B[j]) return A[i];
            else return B[j];
        }
        else{
            if(B[j] < A[i]) return B[j];
            else return A[i];
        }
    }
    
    // Method 3: Complexity O(log(m+n))
    // Use binary search
    int findKthElement_RE(int A[],int m, int B[], int n, int k){
        assert(m >= 0 && n >= 0 && k >= 0 && m+n >= k); 
        // Get partion bit
        int i = (int)(m/(m+n)*(k-1));
        int j = k - 1 -i;
        int Ai_1 = (i == 0) ? INT_MIN : A[i-1];
        int Bj_1 = (j == 0) ? INT_MIN : B[j-1];
        int Ai = (i == m) ? INT_MAX : A[i];
        int Bj = (j == n) ? INT_MAX : B[j];

        if(Ai < Bj && Ai > Bj_1)
            return Ai;
        if(Bj < Ai && Bj > Ai_1)
            return Bj;

        if(Ai < Bj)
            return findKthElement_RE(A+i+1, m-i-1, B, j, k-i-1);
        if(Bj < Ai)
            return findKthElement_RE(A, i, B+j+1, n-j-1, k-j-1);
    }
};

int main(){
    Solution sol;
    int a[] = {1, 5, 7, 8, 9};
    int b[] = {2, 3, 6, 6, 10};
    cout << sol.findKthElement(a, b, 5, 5, 2) << endl;;
    cout << sol.findKthElement_RE(a, 5, b, 5, 2) << endl;;
    return 0;
}



