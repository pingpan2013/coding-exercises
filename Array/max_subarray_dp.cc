/*
 * =====================================================================================
 *
 *       Filename:  max_subarray_dp.cc
 *
 *    Description:  use DP to resolve max subarray problem
 *
 *        Created:  12/22/2014 20:31:50
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

class Solution{
    // Method 2:    
    // Added on Dec 22th
    // Use DP, time complexity O(n), space O(n)
    int maxSubArray__(int A[], int n){
        vector<int> curMax(n, A[0]);   // local max
        vector<int> allMax(n, A[0]);   // global max

        for(int i = 1; i < n; i ++){
            curMax[i] = max(A[i], A[i] + curMax[i-1]);  // key point, get the max value that includes current A[i]
            allMax[i] = max(curMax[i], allMax[i-1]);
        }

        return allMax[n-1];
    }

    // Method 3:
    // optmize method 2 a little bit to reduce the space complexity to O(1)
    int maxSubArray___(int A[], int n){
        int localMax = A[0];
        int globalMax = A[0];
        
        for(int i = 1; i < n; i ++){
            localMax = max(A[i], localMax + A[i]);
            globalMax =max(localMax, globalMax);
        }
        
        return globalMax;
    }
}
