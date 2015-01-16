/*
 * =====================================================================================
 *
 *       Filename:  spiral_matrix_ii.cc
 *
 *    Description:  spiral matrix II
 *
 *        Created:  01/15/2015 19:56:49
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n, 0));
        
        if(n <= 0)  return res;
        
        //int cycle = n/2;
        int cnt = 0;
        int len = n;
        
        for(int i = 0; i < n/2; i++){
            for(int j = i; j < i + len; j++){
                res[i][j] = ++cnt;
            } 
            

            for(int j = i+1; j < i+len; j++){
                res[j][i+len-1] = ++cnt;
            }
            
            for(int j = i+len-2; j >= i; j--){
                res[i+len-1][j] = ++cnt;
            }
            
            for(int j = i+len-2; j >= i; j--){
                res[j][i] = ++cnt;
            }
            
            len -= 2;
        }
        
        if(n % 2 == 1)
            res[n/2][n/2] = ++cnt;
        
        return res;
    }
};

int main(){
    Solution sln;

    auto a = sln.generateMatrix(4);

    for(auto i : a){
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    } 
    cout << endl;

    return 0;
}



