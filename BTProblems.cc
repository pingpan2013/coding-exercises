/*
 * =====================================================================================
 *
 *       Filename:  levelOrderTraversal.cc
 *
 *    Description:  A couple of binary tree problems
 *
 *        Created:  09/20/2014 05:36:08 PM
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */


#include "tree.h"
#include <iostream>
#include <vector>

using namespace std;

class BinaryTree{
public:
    unsigned size(node* root){
        if(!root)   return 0;
        return (size(root->left) + size(root->right) + 1);
    }
    
    /* 
     * If there is a path from the root down to a leaf such
     * that adding up all the values along the path equals 
     * the given sum
     */
    bool hasPathSum(node* root, int sum){
         if(!root)   return (sum == 0);

         return (hasPathSum(root->left, sum - root->data) ||
                    hasPathSum(root->right, sum - root->data));
    }
    
    /* 
     * Given a BT, print out all of its root to leaf paths
     * one per line. Used one help function
     */
    void printNodeVec(vector<node*> path){
        for(auto i: path)
            cout << i->data << " ";
        cout << endl;
    }
    
    void printPathsRe(node* cur, vector<node*> path){
        if(!cur) return;

        path.push_back(cur);
        if(!cur->left && !cur->right)
            printNodeVec(path);
        else{
            printPathsRe(cur->left, path);
            printPathsRe(cur->right, path);
        }
        return;
    }
    
    void printPaths(node* root){
        vector<node*> path;
        printPathsRe(root, path);
        return;
    }

};

int main(){
    BinaryTree bt;
    node *root = new node(1);
    node *node1 = new node(2);
    node *node2 = new node(3);
    node *node3 = new node(4);
    node *node4 = new node(5);
    node *node5 = new node(6);
    node *node6 = new node(7);
    root->left  = node1;
    root->right = node2;
    node1->right= node3;
    node3->left = node4;
    node2->left = node5;
    node2->right = node6;


    cout << bt.size(root) << endl;
    cout << bt.hasPathSum(root, 12) << endl;
    cout << bt.hasPathSum(root, 15) << endl;
    bt.printPaths(root);
}



