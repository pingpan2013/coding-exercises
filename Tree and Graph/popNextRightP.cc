/*
 * =====================================================================================
 *
 *    Description:  Populate next right porinter in each Node
 *                  1. use constant space
 *                  2. assume it is a perfect tree
 *        Created:  09/20/2014 05:36:08 PM
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */


#include "tree.h"
#include <iostream>
#include <queue>

using namespace std;

class Solution{
public:
    // Resursion: recursion needs extra space
    // log(n) extra space for stack frames
    void connect(node* root){
        if(!root)
            return;

        node* lNode = root->left;
        node* rNode = root->right;
        
        // since it is a perfect tree
        // if lNode is not null, then rNode is not null too
        if(lNode){
            lNode->next = rNode;
            rNode->next = (root->next) ? root->next->left : nullptr;
        }

        connect(lNode);
        connect(rNode);
    }
    
    // Iterative solution: first connect all the nodes in the current level
    // then go down to the next level
    void connect2(node* root){
        if(!root)  return;
        // use root->left to go down the tree
        while(root->left){
            // use the cur pointer to loop through the current level
            node* cur = root;
            while(cur){
                cur->left->right = cur->right;
                head->right->next = (head->next) ? head->next->left : nullptr;
                cur = cur->next;
            }
            root = root->left;
        }
    }

    // DFS: level order search would need a queue to store the nodes
    // Thus its space is not constant
};


