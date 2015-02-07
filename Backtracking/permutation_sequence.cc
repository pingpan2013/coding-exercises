/*
 * =====================================================================================
 *
 *       Filename:  permutation_sequence.cc
 *
 *    Description:  The set [1,2,3,…,n] contains a total of n! unique permutations.

                    By listing and labeling all of the permutations in order,
                    We get the following sequence (ie, for n = 3):

                    "123"
                    "132"
                    "213"
                    "231"
                    "312"
                    "321"
                    Given n and k, return the kth permutation sequence.

                    Note: Given n will be between 1 and 9 inclusive.
 *
 *        Created:  01/08/2015 11:25:19
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

class Solution {
public:
    // It will cause TLE if you try to get all permutations and return the kth permutation
    string getPermutation(int n, int k) {
        if(n <= 0 || k < 0) return "";
        
        string permutation;
        for(int i = 1; i <= n; i ++){
            permutation += i + '0';
        }

        string res;
        k = k - 1;
        for(int i = n; i >= 1; i --)
        {
            int d = k/factorial(i-1);
            res += permutation[d];
            permutation.erase(permutation.begin() + d);
            
            k = k % factorial(i-1);
        }
        
        return res;
    }
    
private:
    int factorial(int n){
        if(n == 1 || n == 0)
            return 1;
        
        return n * factorial(n-1);
    }
};


int main(){
    Solution sln;
    cout << sln.getPermutation(3, 1) << endl;
    cout << sln.getPermutation(3, 2) << endl;
    cout << sln.getPermutation(3, 3) << endl;
    cout << sln.getPermutation(3, 4) << endl;
    cout << sln.getPermutation(3, 5) << endl;
    cout << sln.getPermutation(3, 6) << endl;

    return 0;
}
