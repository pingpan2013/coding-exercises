/*
 * =====================================================================================
 *    Description: Given a sorted array of integers, find the starting and ending 
 *    position of a given target  value. Your algorithm's runtime complexity must 
 *    be in the order of O(log n).If the target is not found in the array, return [-1, -1].
 *
 *    For example,
 *    Given [5, 7, 7, 8, 8, 10] and target value 8,
 *    return [3, 4].
 * =====================================================================================
 *
 */

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> searchRange(int A[], int n, int target){
        vector<int> res = search(A, 0, n-1, target);
        return res;
    }

private:
    vector<int> search(int *A, int l, int h, int target){
        int mid;
        int n = h + 1;
        vector<int> res;

        while(l <= h){
            mid = (l + h) / 2;
            if(A[mid] == target){
                int l1 = mid;
                int h1 = mid;
                while(l1 >= 1 && A[l1] == A[l1 - 1]){
                    l1 --;
                }
                res.push_back(l1);
                
                while(h1 <= n - 2 && A[h1] == A[h1 + 1]){
                    h1 ++;
                }
                res.push_back(h1);
                return res;
            }
            else if(A[mid] < target)
                l = mid + 1;
            else
                h = mid - 1;
        }
        
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
};

int main(){
    Solution sol;
    int A[] = {5, 7, 7, 8, 8, 10};
    vector<int> res = sol.searchRange(A, 6, 7);
    assert(res[0] == 1 && res[1] == 2 && "failed in this general test!");
    
    res.clear();
    res = sol.searchRange(A, 6, 5);
    assert(res[0] == 0 && res[1] == 0 && "failed in the corner test!");

    res.clear();
    res = sol.searchRange(A, 6, 10);
    assert(res[0] == 5 && res[1] == 5 && "failed in the corner test!");
    
    // testcase from leetcode
    res.clear();
    int B[] = {2, 2};
    res = sol.searchRange(B, 2, 2);
    assert(res[0] == 0 && res[1] == 1 && "failed in the corner test!");

    cout << "Passed all the tests!" << endl;
    return 0;
}
