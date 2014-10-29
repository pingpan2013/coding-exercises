/*
 * =====================================================================================
 *
 *       Filename:  levelOrderTraversal.cc
 *
 *    Description:  Binary tree level order traversal,
 *                  Output a new line at the end of each level
 *
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
    void levelOrderTraversal(node* t){
        if(!t)  return;
        queue<node*> trace;
        trace.push(t);

        while(!trace.empty()){
            node* current = trace.front();
            cout << current->data << " ";
            
            if(current->left)   trace.push(current->left);
            if(current->right)  trace.push(current->right);
            trace.pop();
        }

        cout << endl;
    }

    void levelOrderTraversal_(node* root){
        if(!root) return;
        queue<node*> curLevel;
        queue<node*> nextLevel;
        curLevel.push(root);

        while(!curLevel.empty()){
            node* cur = curLevel.front();
            cout << cur->data << " ";
            if(cur->left)    nextLevel.push(cur->left);
            if(cur->right)   nextLevel.push(cur->right);
            curLevel.pop();
        
            if(curLevel.empty()){
                cout << endl;
                swap(curLevel, nextLevel);
            }
        }
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
    
    sol.levelOrderTraversal(root);
    sol.levelOrderTraversal_(root);
}



