/*
 * =====================================================================================
 *
 *       Filename:  max_subarray.cc
 *
 *    Description:  
 *
 *        Created:  11/21/2014 21:15:34
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */
#include <cmath>
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Using divide and conquer
        return helper(A, 0, n -1);
    }

private:
    int helper(int A[], int l, int r){
        if(l > r)
            return INT_MIN;
        
        if(l == r)
            return A[l];
        
        int mid = l + (r - l)/2; 
        int lmax = helper(A, l, mid);
        int rmax = helper(A, mid + 1, r);
        
        // combine
        int crossRMax = INT_MIN;
        int tempRSum = 0;
        for(int i = mid + 1; i <= r; i ++){
            tempRSum += A[i];
            if(tempRSum > crossRMax)
                crossRMax = tempRSum;
        }
       
        cout << "R max: " << crossRMax << endl;

        int crossLMax = INT_MIN;
        int tempLSum = 0;
        for(int i = mid; i >= 0; i --){
            tempLSum += A[i];
            if(tempLSum > crossLMax)
                crossLMax = tempLSum;
        }

        cout << "L max: " << crossLMax << endl;
        
        int crossMax = crossLMax + crossRMax;
        return max(max(lmax, rmax), crossMax);
    }
};


int main(){
    int A[] = {-2, 1};

    Solution sol;
    assert(sol.maxSubArray(A, 2) == 1 && "Failed in test 1!");

    cout << "Passed all tests!" << endl;

    return 0;
}



