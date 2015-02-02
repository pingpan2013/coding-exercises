/*
 * =====================================================================================
 *
 *       Filename:  subset_ii.cc
 *
 *    Description:  subset ii, duplicated elements allowed
 *
 *        Created:  02/02/2015 00:25:52
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > res(1);
        if(S.empty())   return res;
        
        sort(S.begin(), S.end());
        
        vector<int> subset;
        dfs(res, subset, S, 0);
        
        return res;
    }
    
private:
    
    void dfs(vector<vector<int> > &res, vector<int> &subset, vector<int> &S, int lvl){
        if(lvl == S.size()){
            return;
        }
        
        /* How to extend this approach??
            
            dfs(res, subset, S, lvl+1);
            subset.push_back(S[lvl]);
            dfs(res, subset, S, lvl+cnt);
            subset.pop_back();
        */
        
        for(int i = lvl; i < S.size(); i ++){
            subset.push_back(S[i]);
            
            res.push_back(subset);
            dfs(res, subset, S, lvl+1);
            
            subset.pop_back();
            
            // remove duplicates
            while(i+1 < S.size() && S[i+1] == S[i]) i++;
        }
    }
};

int main(){
    vector<int> vec({1, 2, 2});
    Solution sln;

    sln.subsetsWithDup(vec);

    return 0;
}
