/*
 * =====================================================================================
 *       Filename:  maxDepth.cc
 *
 *    Description:  Find the maximum depth of a binary tree. Note that 
 *                  the max depth of an empty tree is 0.
 *
 *        Created:  09/19/2014 01:00:10 AM
 *       Compiler:  g++ 4.7.0
 * =====================================================================================
 */

#include <iostream>
#include "binrayTree.h"
using namespace std;

class Solution{
public:
    unsigned int maxDepth(node* root){
        if(!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main(){
    Solution sol;
    node *root = new node(1);
    cout << sol.maxDepth(root) << endl;
    
    node *node1 = new node(2);
    node *node2 = new node(3);
    node *node3 = new node(4);
    node *node4 = new node(5);

    root->left = node1;
    root->right = node2;
    node1->right = node3;
    node3->left = node4;

    cout << sol.maxDepth(root) << endl;
}



