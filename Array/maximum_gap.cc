/*
 * =====================================================================================
 *
 *       Filename:  maximum_gap.cc
 *
 *    Description:  Given an unsorted array, find the maximum difference between the 
 *                  successive elements in its sorted form.
 *
 *                  Try to solve it in linear time/space.
 *
 *                  Return 0 if the array contains less than 2 elements.
 *
 *                  You may assume all elements in the array are non-negative integers 
 *                  and fit in the 32-bit signed integer range.
 *
 *        Created:  12/22/2014 16:59:36
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
    public:
        //TODO:
        // use bucket sort to reduce both the time and space complexity to O(n)
        int maximumGap(vector<int> &num) {
            if(num.size() < 2)
                return 0;
        
            sort(num.begin(), num.end());

            int maxGap = 0;
            for(int i = 1; i < num.size(); i++){
                if(num[i] - num[i-1] > maxGap){
                    maxGap = num[i] - num[i-1];
                }
            }
            
            return maxGap;
        }
};


int main(){
    int arr[] = {1, 2, 3, 4, 6, 9, 20, 21};
    vector<int> vec(arr, arr + 8);

    Solution sol;
    
    assert(sol.maximumGap(vec) == 11 && "Failed in test 1!");

    return 0;
}





