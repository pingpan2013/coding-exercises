/*
 * =====================================================================================
 *
 *       Filename:  search_in_rotated_sorted_arr.cc
 *
 *    Description:  Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *                  (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 *                  You are given a target value to search. If found in the array return 
 *                  its index, otherwise return -1.
 *
 *                  You may assume no duplicate exists in the array.
 *
 *        Created:  11/05/2014 13:25:12
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */
#include <iostream>
#include <cassert>

using namespace std;

class Solution{
public:
    int search(int A[], int n, int target){
        return helper(A, 0, n-1, target);
    }

private:
    // can use iteration or recursion
    int helper(int A[], int l, int h, int target){
        assert(l >= 0 && h >= 0 && l <= h && "wrong parameters!");
        int mid;
        
        while(l <= h){
            mid = (l + h)/2;
            if(A[mid] == target)
                return mid;
            // if left part is sorted 
            if(A[l] <= A[mid]){
                if(target >= A[l] && target < A[mid])
                    h = mid - 1;
                else
                    l = mid + 1;
            }
            else{
                if(target > A[mid] && target <= A[h])
                    l = mid + 1;
                else
                    h = mid - 1;
            }
        }

        return -1;
    }
};

int main(){
    Solution sol;
    int A[] = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    assert(sol.search(A, 9, 7) == 0 && "failed in test 1!");
    assert(sol.search(A, 9, 8) == 1 && "failed in test 2!");
    assert(sol.search(A, 9, 1) == 3 && "failed in test 3!");
    assert(sol.search(A, 9, 5) == 7 && "failed in test 4!");
    assert(sol.search(A, 9, 6) == 8 && "failed in test 5!");

    cout << "Past all the test cases!" << endl;
    return 0;
}
