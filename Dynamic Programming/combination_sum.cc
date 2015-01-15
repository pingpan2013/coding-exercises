/*
 * =====================================================================================
 *
 *       Filename:  combination_sum.cc
 *
 *    Description:  Given a set of candidate numbers (C) and a target number (T), find 
                    all unique combinations in C where the candidate numbers sums to T.

                    The same repeated number may be chosen from C unlimited number of times. 
 *
 *        Created:  01/15/2015 00:10:40
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > res;
        if(target <= 0) return res;
        
        sort(candidates.begin(), candidates.end());
        vector<int> one_sol;
        helper(res, one_sol, candidates, target, 0);
        
        return res;
    }
    
private:
    void helper(vector<vector<int> > &res, vector<int> &one_sol, vector<int> candidates, int target, int lvl){
        if(target == 0){
            res.push_back(one_sol);
            return;
        }
        
        if(target < 0){
            return;
        }
        
        for(int i = lvl; i < candidates.size(); i++){
            target -= candidates[i];
            one_sol.push_back(candidates[i]);
            
            helper(res, one_sol, candidates, target, i); // its lvl not (lvl+1) since one element can be used many times
            
            one_sol.pop_back();
            target += candidates[i];
        }
    }
};
