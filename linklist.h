/*
 * =====================================================================================
 *       Filename:  tree.h
 *
 *    Description:  Define the node of a tree
 *
 *        Created:  09/19/2014 01:00:10 AM
 *       Compiler:  g++ 4.7.0
 * =====================================================================================
 */


struct node{
    int data;
    node* next;
    node(int _data): data(_data), next(nullptr){}
};


