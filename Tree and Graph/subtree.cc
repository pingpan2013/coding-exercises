/*
 * =====================================================================================
 *
 *       Filename:  subtree.cc
 *
 *    Description:  Determine if a tree is a subtree of another tree
 *
 *        Created:  10/29/2014 14:28:31
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include "binarytree.h"

using namespace std;

class Solution{
public:
    bool isSubtree(node* n1, node* n2){
        if(!n2) return true;
        if(!n1) return false;

        if(n1->data == n2->data){
            if(matchTree(n1, n2))   return true;
        }

        return (isSubtree(n1->left, n2) || isSubtree(n1->right, n2));
    }

private:
    bool matchTree(node* n1, node* n2){
        if(!n1 && !n2)  return true;
        if(!n1 || !n2)  return false; 
        // Before check the data we have to gurantee that its not nullptr
        if(n1->data != n2->data) return false;
        return (matchTree(n1->left, n2->left) && matchTree(n1->right, n2->right));
    }
};

int main(){
    int a1[] = {0, 1, 2, 3, 4, 5, 6};
    int a2[] = {0, 1, 2};
    
    node* n1 = create_bst(a1, 0, 6);
    node* n2 = create_bst(a2, 0, 2);
    
    Solution sol;
    if(sol.isSubtree(n1, n2))
        cout << "Is subtree!" << endl;
    else
        cout << "Not subtree!" << endl;
    
    return 0;
}

