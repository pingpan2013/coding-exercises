/*
 * =====================================================================================
 *    Description:  Search sorted 2D Matrix
 *
 *        Created:  09/20/2014 05:36:08 PM
 *       Compiler:  g++ 4.7.0
 * =====================================================================================
 */


#include <iostream>

using namespace std;

class Solution{
public:    
    // Time complexity should be O(max(m, n))
    bool search2DMatrix(int a[][4], int m, int n, int target){
        int i = 0;
        int j = n-1;

        while( i < m && j >= 0 ){
            if(a[i][j] == target) {
                cout << "(" << i << ", " << j << ")" << endl;
                return true;
            }
               
            if(target < a[i][j])
                j--;
            else
                i++;
        }
        cout << "Not Exist!" << endl;
        return false;
    }
};

int main(){
    int mat[4][4] = {{10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                   };
    Solution sol;
    sol.search2DMatrix(mat, 4, 4, 29); 
    sol.search2DMatrix(mat, 4, 4, 28); 
    sol.search2DMatrix(mat, 4, 4, 32); 

    return 0;
}



