/*
 * =====================================================================================
 *
 *       Filename:  combination_sum.cc
 *
 *    Description:  combination sum
                    Given a set of candidate numbers (C) and a target number (T), find 
                    all unique combinations in C where the candidate numbers sums to T.

                    The same repeated number may be chosen from C unlimited number of times.

                    Note:

                    All numbers (including target) will be positive integers.
                    Elements in a combination (a1, a2, … , ak) must be in non-descending order. 
                        (ie, a1 ≤ a2 ≤ … ≤ ak).
                    The solution set must not contain duplicate combinations.

                    For example, given candidate set 2,3,6,7 and target 7,
                    A solution set is:
                    [7]
                    [2, 2, 3] 
 *
 *        Created:  02/14/2015 17:25:22
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        int n = candidates.size();
        
        if(n == 0)  return result;
        
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, result, temp, 0, target);
        return result;
    }

private:
    void dfs(vector<int> &candidates, vector<vector<int> > &result, vector<int> &temp, int level, int target){
        if(target < 0 || level > candidates.size())  return;
        
        if(target == 0){
            result.push_back(temp);
            return;
        }
        
        for(int i = level; i < candidates.size(); i++){
            if(target - candidates[i] >= 0){
                temp.push_back(candidates[i]);
                dfs(candidates, result, temp, i, target-candidates[i]);
                temp.pop_back();
            }
        }
    }
};


