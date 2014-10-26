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

struct node{
    node(int _data): data(_data), left(nullptr), right(nullptr){
    };

    int data;
    node* left;
    node* right;
};

extern void levelOrderTrav(node* node);
extern void preOrderTrav(node* node);

#endif
