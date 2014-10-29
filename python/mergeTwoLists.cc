/*
 * =====================================================================================
 *    Description:  Given two sorted lists, merge them
 *        Created:  09/26/2014 09:42:44 PM
 *       Compiler:  g++ 4.7.0
 * =====================================================================================
 */

#include <iostream>
#include "linklist.h"

using namespace std;

class Solution{
public:
    void printList(node* cur){
        node* n = cur;
        while(n){
            cout << n->data << " ";
            n = n->next;
        }
        cout << endl;
    }

    node* mergeTwoLists(node* l1, node* l2){
        if(!l1 || !l2)  return nullptr;
        node* newList = new node;
        newList->data = 0;
        node* l = newList;
        node* h1 = l1;
        node* h2 = l2;

        while(h1 && h2){
            if(h1->data > h2->data){
                l->next = h2;
                h2 = h2->next;
            }
            else{
                l->next = h1;
                h1 = h1->next;
            }
            l = l->next;
        }
        if(h1)  l->next = h1;
        if(h2)  l->next = h2;

        return newList->next;
    }
};

int main(){
    node* root1 = new node;
    node* root2 = new node;
    node* node1 = new node;
    node* node2 = new node;
    node* node3 = new node;
    node* node4 = new node;
    node* node5 = new node;
    node* node6 = new node;
    root1->data = 0;
    root2->data = 1;
    node1->data = 2;
    node2->data = 6;
    node3->data = 9;
    node4->data = 3;
    node5->data = 5;
    node6->data = 10;
    root1->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = nullptr;    
    root2->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = nullptr;
    
    Solution sol;
    sol.printList(root1);
    sol.printList(root2);
    node* result = sol.mergeTwoLists(root1, root2);
    sol.printList(result);
    return 0;
}







