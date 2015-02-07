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
     vector<vector<int> > combine(int n, int k) {
        assert(n >= 0 && k >= 0 && n >= k);
        vector<vector<int> > res;
        
        if(n == 0 || k == 0)    return res;
        
        vector<int> one_comb;
        dfs(res, one_comb, 1, n, k);
        
        dispalyResults(res);

        return res;
    }
    
private:
    void dfs(vector<vector<int> > &res, vector<int> &one_comb, int start, int n, int k){
        if(one_comb.size() == k){
            res.push_back(one_comb);
            return;
        }
        
        for(int i = start; i <= n; i++){
            one_comb.push_back(i);
            dfs(res, one_comb, start+1, n, k);
            one_comb.pop_back();
        }
    }

    void dispalyResults(vector<vector<int> > res){
        // Display results
        for(auto vec: res){
            for(auto i: vec)
                cout << i << " ";
            cout << endl;
        }
        cout << endl;
    }
};

int main(){
    Solution sol;
    vector<vector<int> > res = sol.combine(4, 2);
   
    vector<vector<int> > res_1 = sol.combine(1, 1);
    
    return 0;
}
