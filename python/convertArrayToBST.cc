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
#include "binaryTree.h"

using namespace std;

class Solution{
public:
    
    node* convert(int A[], int l, int r){
        if(l > r)
            return nullptr;
        
        int mid = (l + r) / 2;
        node* n = new node(A[mid]);
        n->left = convert(A, l, mid - 1);
        n->right = convert(A, mid + 1, r);
        return n;
    }
    
    node* convertArrToBST(int A[], int n){
        return convert(A, 0, n-1); 
    }
};

int main(){
    int A[] = {1, 2, 3, 4, 5, 6};
    Solution sol;
    node* root = sol.convertArrToBST(A, 6);
    levelOrderTrav(root);
}





