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
#include <cassert>

using namespace std;

node* create_bst(int* a, int start, int end){
    assert(start >= 0 && end >= 0 && "Index out of ranges!");
    if(start > end) return nullptr;
    
    int mid = (start + end) / 2;
    node* n = new node(a[mid]);

    n->left = create_bst(a, start, mid - 1);  // attention: should be mid-1
    n->right = create_bst(a, mid + 1, end);

    return n;
}


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


