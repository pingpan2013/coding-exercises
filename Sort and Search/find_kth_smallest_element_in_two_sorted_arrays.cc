/*
 * =====================================================================================
 *
 *       Filename:  find_kth_smallest_element_in_two_sorted_arrays.cc
 *
 *    Description:  find kth smallest element in two sorted arrays
 *
 *        Created:  01/17/2015 16:31:24
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    // http://blog.csdn.net/zxzxy1988/article/details/8587244
    
    // Transfer this problem to the problem that asks for the kth smallest element in two sorted arrays
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int len = m + n;
        
        // odd
        if(len & 0x1){
            return findKthSmallest(A, m, B, n, len/2+1);
        }
        else{
            int a = findKthSmallest(A, m, B, n, len/2); 
            int b = findKthSmallest(A, m, B, n, len/2 + 1);
            return  (double)(a+b)/2;
        }
    }
    
private:
    int findKthSmallest(int a[], int m, int b[], int n, int k){
        assert(m >= 0 && n >= 0 && k <= m+n && "wrong parameter");
        
        // assume a[] is the array with less elements
        if(m > n) return findKthSmallest(b, n, a, m, k);
        
        if(m == 0)  return b[k-1];
        if(k == 1)  return min(a[0], b[0]);
        
        int pa = min(m, k/2);
        int pb = k - pa;
        
        if(a[pa - 1] == b[pb - 1]){
            return a[pa - 1];
        }
        if(a[pa - 1] < b[pb - 1]){
            return findKthSmallest(a+pa, m-pa, b, n, k-pa);
        }
        else if(a[pa - 1] > b[pb - 1]){
            return findKthSmallest(a, m, b+pb, n-pb, k-pb);
        }

        return -1;
    }
};

int main(){
    int a[] = {};
    int b[] = {2, 3};

    Solution sln;
    cout << sln.findMedianSortedArrays(a, 0, b, 2) << endl;

    return 0;
}
