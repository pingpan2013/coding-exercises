/*
 * =====================================================================================
 *    Description:  implement some utility function for binary tree
 *
 *        Created:  09/20/2014 05:36:08 PM
 *       Compiler:  g++ 4.7.0
 * =====================================================================================
 */


#include "binaryTree.h"
#include <iostream>
#include <queue>

using namespace std;

void levelOrderTrav(node* t){
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

void preOrderTrav(node* t){
    if(!t) return;
    
    cout << t->data << " ";
    preOrderTrav(t->left);
    preOrderTrav(t->right);
}


