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

using namespace std;

struct node{
    node(int _data){
        data = _data;
    };

    int data;
    node* left;
    node* right;
};

class Solution{
public:
    void inOrderTraverse_rec(node* root){
        if(!root)
            return;

        inOrderTraverse_rec(root->left);
        cout << root->data << " ";
        inOrderTraverse_rec(root->right);
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
    
    sol.inOrderTraverse_rec(root);
}



