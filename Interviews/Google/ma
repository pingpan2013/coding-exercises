/*
 * =====================================================================================
 *
 *       Filename:  find_all_factors.cc
 *
 *    Description:  Print all factors of the product of a given list of distinct primes.
 *                  
 *                  Example:
 *                  Input: 2 3 7
 *                  Output: 1 2 3 6 7 14 21 42
 *
 *        Created:  02/23/2015 10:21:15
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int> &arr, vector<int> &ret, int cur, int level){
    if(level == arr.size()){
        return;
    }

    for(int i = level; i < arr.size(); i ++){
        ret.push_back(cur*arr[i]);
        
        dfs(arr, ret, cur*arr[level], i+1);
    }
}

vector<int> find_all_factors(vector<int> &arr){
    vector<int> result;
    result.push_back(1);

    dfs(arr, result, 1, 0);
    return result;
}

int main(){
    vector<int> arr({2, 3, 7});
    vector<int> res = find_all_factors(arr);

    for(auto itr : res)
        cout << itr << " ";
    cout << endl;

    return 0;
}
