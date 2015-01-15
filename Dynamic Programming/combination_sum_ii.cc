/*
 * =====================================================================================
 *
 *       Filename:  combination_sum_ii.cc
 *
 *    Description:  Given a collection of candidate numbers (C) and a target number (T), 
                    find all unique combinations in C where the candidate numbers sums to T.

                    Each number in C may only be used once in the combination. 
 *
 *        Created:  01/15/2015 00:12:40
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int> > res;
        if(target <= 0) return res;
        
        sort(candidates.begin(), candidates.end());
        vector<int> one_sol;
        helper(res, one_sol, candidates, target, 0);
        
        return res;
    }
    
private:
    // the input candidates may contain duplicates, we should deal with this case otherwise there might be duplicate solutions
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
            
            helper(res, one_sol, candidates, target, i+1); 
            
            one_sol.pop_back();
            target += candidates[i];
            
            // no duplicates
            while(i < candidates.size() && candidates[i] == candidates[i+1]){
                i++;
            }
        }
    }
};
