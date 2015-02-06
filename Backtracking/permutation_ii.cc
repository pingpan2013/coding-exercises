/*
 * =====================================================================================
 *
 *       Filename:  permutation_ii.cc
 *
 *    Description:  permutation with duplicate numbers
 *
 *        Created:  02/05/2015 23:51:45
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;
        if(num.empty()) 
            return res;
        
        // sort(num.begin(), num.end());
        dfs(res, num, 0);
        return res;
    }
    
private:
    bool noSwap(int l, int i, vector<int> &num){
        for(int j = l; j < i; j++){
            if(num[j] == num[i])
                return true;
        }
        
        return false;
    }

    void dfs(vector<vector<int> > &res, vector<int> &num, int level){
        if(level == num.size()){
            res.push_back(num);
            return;
        }
        
        for(int i = level; i < num.size(); i++){
            // deal with duplicates
            if(noSwap(level, i, num))   continue;
           
            swap(num[i], num[level]);
            dfs(res, num, level+1);
            swap(num[i], num[level]);
        }
    }
};


