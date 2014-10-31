/*
 * =====================================================================================
 *
 *       Filename:  combinations.cc
 *
 *    Description:  Given two integers n and k, return all possible combinations
 *
 *        Created:  10/31/2014 11:25:52
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution{
public:
    vector<vector<int> > combine(int n, int k){
        assert(n >= k && n >= 1 && k >= 1 && "Wrong Parameters!") ;

        vector<vector<int> > all_res;
        vector<int> cur_res;

        helper(all_res, cur_res, n, k, 1);
        dispalyResults(all_res);
        return all_res;
    }

private:
    void helper(vector<vector<int> > &all_res, vector<int> &cur_res, int n, int k, int index){
        // Exit of the recursion
        if(cur_res.size() == k){
            all_res.push_back(cur_res);
            return;
        }
        
        // Fix the index as the first element of the current combination
        // index [1, 2, .., n]
        for(int i = index; i <= n; i ++){
            cur_res.push_back(i);
            helper(all_res, cur_res, n, k, ++index);
            cur_res.pop_back();
        }
    }

    void dispalyResults(vector<vector<int> > res){
        // Display results
        for(auto vec: res){
            for(auto i: vec)
                cout << i << " ";
            cout << endl;
        }
    }
};

int main(){
    Solution sol;
    vector<vector<int> > res = sol.combine(4, 2);
    assert(!res.empty() && "Empty result");
    
    vector<vector<int> > res_1 = sol.combine(1, 1);
    assert(!res_1.empty() && "Empty result");
    
    return 0;
}
