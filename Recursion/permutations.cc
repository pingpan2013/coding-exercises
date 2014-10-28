/*
 * =====================================================================================
 *    Description:  return all permutations
 *
 *        Created:  09/20/2014 05:36:08 PM
 *       Compiler:  g++ 4.7.0
 * =====================================================================================
 */


#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:    
    void perm(vector<int> &A, int l, int h, vector<vector<int> > &res){
        if(l == h){
            res.push_back(A);
            for(auto item: A)
                cout << item << " ";
            cout << endl;
            return;
        }
        
        // fix A[l], permutate A[l+1 ... h]
        // it stops when l+1 == h
        for(int i = l; i <= h; i ++){
            swap(A[i], A[l]);
            perm(A, l+1, h, res);
            swap(A[i], A[l]);
        }
    }

    vector<vector<int> > permutation(vector<int> A, int n){
        vector<vector<int> > res;
        perm(A, 0, n-1, res);    
        return res;
    }
};

int main(){
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    Solution sol;
    sol.permutation(vec, 3);
}



