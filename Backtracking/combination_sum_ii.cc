/*
 * =====================================================================================
 *
 *       Filename:  combination_sum_ii.cc
 *
 *    Description:  allow duplicates in the array and each element can only be used once
 *
 *        Created:  02/14/2015 18:01:26
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
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
                dfs(candidates, result, temp, i+1, target-candidates[i]);
                temp.pop_back();
            }
            
            // deal with duplicates
            while(i+1 < candidates.size() && candidates[i+1] == candidates[i]){
                i++;
            }
        }
    }
};
