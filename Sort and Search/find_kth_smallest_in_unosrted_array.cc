/*
 * =====================================================================================
 *
 *    Description:  find kth smallest element in unsorted array 
 *
 *        Created:  02/01/2015 17:18:03
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution{
public:
    // method 1: use max heap, O((n-k)logk)
    // method 2: nlogn
    // method 3: quicksort based algorithm, worst case O(n^2) average O(n)
    int findKthSmallest(vector<int> vec, int k){
        assert(k <= vec.size() && k > 0);
        
        return helper(vec, 0, vec.size()-1, k);
    }    

private:
    int helper(vector<int> &vec, int l, int r, int k){
        if(k <= 0 || k > r-l+1) return INT_MAX;

        int pos = partition(vec, l, r);

        if(pos - l + 1 == k)    return vec[pos];
        else if(pos - l + 1 < k)    return helper(vec, pos, r, k-pos+l-1);
        else return helper(vec, l, pos-1, k);
    }    

    int partition(vector<int> &arr, int l, int r) {
        int pivot = arr[r];
        int i = l;
        int j = r-1;

        while(i < j){
            while(arr[i] < pivot) i++;
            while(arr[j] > pivot) j--;

            if(i <= j){
                swap(arr[i++], arr[j--]);
            }
        }

        swap(arr[r], arr[i]);
        return i;
    }
};


int main(){
    vector<int> vec({12, 3, 5, 7, 4, 19, 26}); 
    
    Solution sln;
    assert(sln.findKthSmallest(vec, 3) == 5 &&  "failed in test 1");
    assert(sln.findKthSmallest(vec, 1) == 3 &&  "failed in test 2");
    assert(sln.findKthSmallest(vec, 7) == 26 && "failed in test 3");
    
    cout << "Passed all test cases!" << endl;
    return 0;
}


