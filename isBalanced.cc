/*
 * =====================================================================================
 *
 *       Filename:  levelOrderTraversal.cc
 *
 *    Description:  Given a binary tree, determine if it is height-balanced.For this 
 *    problem, a height-balanced binary tree is defined as a binary tree in which 
 *    the depth of the two subtrees of every node never differ by more than 1.
 *
 *        Created:  09/20/2014 05:36:08 PM
 *       Compiler:  g++ 4.7.0
 * =====================================================================================
 */


#include "binaryTree.h"
#include <iostream>
#include <cassert>
#include <cmath>


using namespace std;

class Solution{
public:    
    bool isBalanced(node* root){
        if(!root)   return true;
        
        if(fabs(getDepth(root->left) - getDepth(root->right)) > 1)
            return false;
        else
            return true;

        return isBalanced(root->left) && isBalanced(root->right);
    }

    unsigned int getDepth(node* root){
        if(!root){
            cout << "here" << endl;
            return 0;
        }

        cout << "test" << endl;

        cout << getDepth(root->left) << endl;
        cout << getDepth(root->right) << endl;

        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }
};

int main(){
    Solution sol;
    node *root = new node(1);
    node *node1 = new node(2);
    node *node2 = new node(3);
    node *node3 = new node(4);
    node *node4 = new node(5);
    root->left  = node1;
    root->right = node2;
    node1->right= node3;
    node3->left = node4;

    assert(sol.isBalanced(nullptr) == true && "failed with nullptr test");

    cout << node4->data << endl;
    cout << sol.getDepth(node4) << endl;
    
    assert(sol.isBalanced(node4) == true && "failed in single node test");
    
    assert(sol.isBalanced(node3) == true);

    assert(sol.isBalanced(node1) == false);
    assert(sol.isBalanced(node2) == true);
    assert(sol.isBalanced(root) == false);
    
    return 0;
}



