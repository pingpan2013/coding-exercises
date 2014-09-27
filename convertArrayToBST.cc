/*
 * =====================================================================================
 *
 *       Filename:  convertArrayToBST.cc
 *
 *    Description:  convert sorted array to bst
 *
 *        Created:  09/27/2014 01:10:15 PM
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */


#include <iostream>
#include "tree.h"

using namespace std;

class Solution{
public:
    
    void convert(int A[], int l, int r, node* n){
        if(l < r)
            return;

        int mid = (l + r) / 2;
        n->data = A[mid];
        cout << n->data << endl;
        convert(A, l, mid, n->left);
        convert(A, mid + 1, r, n->right);
    }
    
    void convertArrToBST(int A[], int n, node* res){
        convert(A, 0, n-1, res); 
    }
};

int main(){
    int A[] = {1, 2, 3, 4, 5, 6};
    node* root = new node(0);
    
    Solution sol;
    sol.convertArrToBST(A, 6, root);
    cout << root->data << endl;
}





