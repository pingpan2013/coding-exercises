/*
 * =====================================================================================
 *    Description:  Given a bt, check if it is a symmetric tree
 *                  Note: bonus points if you could solve it both recursively and 
 *                  iteratively
 *
 *        Created:  09/20/2014 05:36:08 PM
 *       Compiler:  g++ 4.7.0
 * =====================================================================================
 */


#include "tree.h"
#include <iostream>
#include <queue>

using namespace std;

class Solution{
public:
    // recursive solution
    bool isSymm(node* n1, node* n2){
        if(!n1) return (n2 == nullptr);
        if(!n2) return false;  // n1 != nullptr
        if(n1->data != n2->data) return false;
        
        return (sSymm(n1->left, n2->right) && 
                isSymm(n1->right, n2->left));
    }

    bool isSymmTree(node* root){
        if(!root)   return true;
        return isSymm(root->left, root->right);
    }

    // iterative solution
    bool isSymmTree_IT(node* root){
        // use level order traversal to traverse the left 
        // tree and right tree, check if they are the same
        // level by level
        if(!root)   return true;
        
        queue<node*> lTree;
        queue<node*> rTree;
        lTree.push(root->left);
        rTree.push(root->right);
        
        while(!lTree.empty() && !rTree.empty()){
            node* lTemp = lTree.front();
            lTree.pop();
            node* rTemp = rTree.front();
            rTree.pop();

            if((!lTemp && rTemp) || (lTemp && !rTemp) || (lTemp->data != rTemp->data))
                return false;
            lTree.push(lTemp->left);
            lTree.push(lTemp->right);
            rTree.push(rTemp->left);
            rTree.push(rTemp->right);
        }
        return true;
    }
};


