/*
 * =====================================================================================
 *
 *       Filename:  ifSameTree.cc
 *
 *    Description:  Given two binary trees, check if they are equal or not.
 *
 *        Created:  09/20/2014 04:28:27 PM
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include "tree.h"
#include <iostream>

using namespace std;

class Solution{
public:
    bool ifSameTree(node *t1, node *t2){
        if(!t1 && !t2)
            return true;
        else if(t1 && t2){
            if(t1->data != t2->data)
                return false;
            else if(!ifSameTree(t1->left, t2->left) || !ifSameTree(t1->right, t2->right))
                return false;
            else
                return true;
        }
        else
            return false;
    }
};

int main(){
    Solution sol;
    node *root1 = new node(1);
    node *node1 = new node(2);
    node *node2 = new node(3);
    node *node3 = new node(4);
    node *node4 = new node(5);
    root1->left  = node1;
    root1->right = node2;
    node1->right = node3;
    node3->left  = node4;
    
    node *root2 = new node(1);
    node *node5 = new node(2);
    node *node6 = new node(3);
    node *node7 = new node(4);
    node *node8 = new node(5);
    root2->left  = node5;
    root2->right = node6;
    node5->right = node7;
    node7->left  = node8;

    cout << sol.ifSameTree(root1, root2) << endl;
}
   
