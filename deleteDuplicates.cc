/*
 * =====================================================================================
 *    Description:  Given a sorted linked list, delete all duplicates such that
 *                  each element appear only once.
 *
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
    
    void deleteDuplicates(node* root){
        if(!root || !root->next)
            return;
        node* cur = root;
        while(cur){
            cout << cur->data << endl;
            node* temp = cur;
            // Attention: Need to check if temp->next is nullptr
            while(temp->next && temp->data == temp->next->data)
                temp = temp->next;
            cur->next = temp->next;
            cur = cur->next;
        }
        printList(root);
    }
};

int main(){
    node* root  = new node;
    node* node1 = new node;
    node* node2 = new node;
    node* node3 = new node;
    node* node4 = new node;
    node* node5 = new node;
    node* node6 = new node;
    root ->data = 0;
    node1->data = 1;
    node2->data = 2;
    node3->data = 2;
    node4->data = 3;
    node5->data = 3;
    node6->data = 4;
    root ->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = nullptr;
    
    Solution sol;
    sol.printList(root);
    sol.deleteDuplicates(root);
    return 0;
}







