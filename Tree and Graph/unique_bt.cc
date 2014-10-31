/*
 * =====================================================================================
 * Filename: maxDepth.cc
 *
 * Description: Given n, how many structually unique BSTs that store values 1....n
 *
 * Created: 09/19/2014 01:00:10 AM
 * Compiler: g++ 4.7.0
 * =====================================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    unsigned numOfUniqueBST(int n){
        if(n < 0) return 0;

        vector<int> result(n+1, 0);
        result[0] = 1;
        for(int i = 1; i <= n; i ++)
        for(int j = 0; j < i; j++)
        result[i] += result[j] * result[i-j-1];

        cout << result[n] << endl;
        return result[n];
    }

    unsigned numOfUniqueBST_RE(int n){
        if(n <= 1)
        return 1;

        unsigned cnt = 0;
        unsigned lCnt, rCnt = 0;

        for(int i = 1; i <= n; i ++){
            lCnt = numOfUniqueBST_RE(i-1);
            rCnt = numOfUniqueBST_RE(n-i);
            cnt += lCnt*rCnt;
        }

        return cnt;
    }
};

int main(){
    Solution sol;
    cout << "# of BST:" << endl;
    sol.numOfUniqueBST(0);
    sol.numOfUniqueBST(1);
    sol.numOfUniqueBST(2);
    sol.numOfUniqueBST(3);
    sol.numOfUniqueBST(4);

    cout << "# of BST:" << endl;
    cout << sol.numOfUniqueBST_RE(0) << endl;
    cout << sol.numOfUniqueBST_RE(1) << endl;
    cout << sol.numOfUniqueBST_RE(2) << endl;
    cout << sol.numOfUniqueBST_RE(3) << endl;
    cout << sol.numOfUniqueBST_RE(4) << endl;
}





