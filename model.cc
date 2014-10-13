/*
 * =====================================================================================
 *
 *       Filename:  levelOrderTraversal.cc
 *
 *    Description:  Binary tree level order traversal,
 *
 *        Created:  09/20/2014 05:36:08 PM
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */


#include "binaryTree.h"
#include <iostream>

using namespace std;

class Solution{
public:    

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

}



