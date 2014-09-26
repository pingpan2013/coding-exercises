/*
 * =====================================================================================
 *
 *       Filename:  levelOrderTraversal.cc
 *
 *    Description:  Change a tree so that the roles of the left and right
 *                  pointers are swapped at every node
 *
 *        Created:  09/20/2014 05:36:08 PM
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */


#include "tree.h"
#include <iostream>

using namespace std;

class Solution{
    public:
        void mirrorBT(node* root){
            if(!root)  return;

            swap(root->left, root->right);
            mirrorBT(root->left);
            mirrorBT(root->right);
            return;
        }

        void inOrderTraversal(node* root){
            if(!root)   return;
            inOrderTraversal(root->left);
            cout << root->data << " ";
            inOrderTraversal(root->right);
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
    
    sol.inOrderTraversal(root);
    cout << endl;
    sol.mirrorBT(root);
    sol.inOrderTraversal(root);
    cout << endl;

    return 0;
}



