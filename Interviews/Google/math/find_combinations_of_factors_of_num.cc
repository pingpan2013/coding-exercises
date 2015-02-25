/*
 * =====================================================================================
 *
 *       Filename:  find_factors_of_num.cc
 *
 *    Description:  find all unique combinations of factors(except 1) of a given num
 *
 *        Created:  02/23/2015 23:32:09
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>

using namespace std;

// k is the current factor
void dfs(vector<vector<int>> &ret, vector<int> &comb, int n){
    int last = comb.empty() ? 2 : comb.back();
 
    if(n == 1){
        ret.push_back(comb);
        return;
    }

    for(int i = last; i <= n; i ++){
        if(n % i == 0){
            comb.push_back(i);
            dfs(ret, comb, n/i);
            comb.pop_back();
        }
    }
}

vector<vector<int>> findCombinationsOfFactors(int n){
    vector<vector<int>> ret;
    if(n <= 1)  return ret;

    vector<int> comb;
    dfs(ret, comb, n);
    ret.pop_back();  // n itself

    return ret;
}

int main(){
    vector<vector<int>> ret = findCombinationsOfFactors(28);

    for(auto itr : ret){
        for(auto it : itr){
            cout << it << " ";
        }
        cout << endl;
    }
    
    return 0;
}
