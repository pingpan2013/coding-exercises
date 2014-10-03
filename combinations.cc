/*
 * =====================================================================================
 *    Description:  Given two integers n and k, find out all the combinations
 *                  of k numbers out of 1...n
 *       Compiler:  g++ 4.7.0
 * =====================================================================================
 */


#include "binaryTree.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:    
    void allCombinations(int n, int k) {
        vector<vector<int> > all_result;
        vector<int> result;
        int level = 1;
        
        // use k to indicate the current # of the nums in the result
        helper(all_result, result, n, k, level);
    }

private:
    void helper(vector<vector<int> > all_result, vector<int> result,
                int n, unsigned k, int level){
        // one comb is present
        if(result.size() == k){
            all_result.push_back(result);

            for(auto i: result)
                cout << i << " ";
            cout << endl;

            return;
        }
        
        for(int i = level; i <= n; i ++)
        {   
            result.push_back(i);
            helper(all_result, result, n, k, ++level);
            result.pop_back();
        }
        return;
    }
};

int main(){
    Solution sol;
    vector<vector<int> > results;
    vector<int> result;

    sol.allCombinations(5, 3);
    return 1;
}



