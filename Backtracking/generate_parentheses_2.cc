/*
 * =====================================================================================
 *
 *       Filename:  generate_parentheses_2.cc
 *
 *    Description:  generate parentheses
 *
 *        Created:  01/19/2015 22:54:07
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

const static string parentheses("()");

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n == 0)  return res;
        
        string sol;
        dfs(res, sol, 0, 0, n);
        
        return res;
    }
    
private:
    void dfs(vector<string> &res, string &sol, int l, int r, int n){
        if(l == n && r == n){
            res.push_back(sol);
            return;
        }
        
        if(l < r || l > n || r > n)   return;
        
        for(int i = 0; i < 2; i ++){
            sol.push_back(parentheses[i]);

            if(i == 0)
                dfs(res, sol, l+1, r, n);  // Attention: cannot be i++ here, could be ++i
            else if(i == 1)
                dfs(res, sol, l, r+1, n);  // Attention
            
            sol.pop_back();
        }
    }
};


int main(){
    Solution sln;
    vector<string> res = sln.generateParenthesis(3);

    for(auto itr : res)
        cout << itr << endl;

    return 0;
}


