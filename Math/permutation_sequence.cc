/*
 * =====================================================================================
 *
 *       Filename:  permutation_sequence.cc
 *
 *    Description:  permutation sequence
 *
 *        Created:  02/15/2015 18:17:05
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        
        if(n == 0)  return result;
        
        string permutation;
        for(int i = 1; i <= n; i++){
            permutation.push_back(i + '0');
        }
        
        k = k-1;  // attention here: 0 based index
        for(int i = n; i >= 1; i--){
            int temp = factorial(i-1);
            int d = k/temp;
            
            result += permutation[d];
            permutation.erase(permutation.begin() + d);
            
            k = k%temp;
        }
        
        return result;
    }
    
private:
    int factorial(int n){
        if(n <= 1)  return 1;
        
        int result = 1;
        for(int i = 2; i <= n; i++){
            result *= i;
        }
        
        return result;
    }
};

