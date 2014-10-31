/*
 * =====================================================================================
 *       Filename:  binaryTree.h
 *
 *    Description:  Define the node of a tree
 *
 *        Created:  09/19/2014 01:00:10 AM
 *       Compiler:  g++ 4.7.0
 * =====================================================================================
 */
#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include <iostream>
#include <queue>
#include <cassert>

using namespace std;

//====================================================================
// data structure node for bt
//====================================================================
struct node{
    node(int _data): data(_data), left(nullptr), right(nullptr){
    };

    char data;
    node* left;
    node* right;
};

//====================================================================
// Several utility functions for bt or bst
//====================================================================
node* create_bst(char* a, int start, int end){
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

#endif

