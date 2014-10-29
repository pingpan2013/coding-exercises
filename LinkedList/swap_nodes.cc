/*
 * =====================================================================================
 *    Description: given a list, swap every two adjacent nodes and return its head 
 *                 1. only use constant space
 *                 2. cannot modify the values in the nodes
 *        Created:  09/27/2014 03:30:09 PM
 *       Compiler:  g++ 4.7.0
 * =====================================================================================
 */

#include "linklist.h"
#include <iostream>

using namespace std;

class Solution{
public:
    node* swapNodes(node* root){
        if(!root)   return nullptr;
        
        node* cur = root;
        node* helper = new node;
        helper->data = 0;
        helper->next = root;
        node* pre = helper;

        while(cur){
            if(!cur->next)  break;;
           
            node* temp = cur->next->next;
            cur->next->next = pre->next;
            pre->next = cur->next;
            cur->next = temp;
                
            pre = cur;
            cur = cur->next;
        }
        
        return helper->next;
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
    node5->data = 4;
    node6->data = 5;
    root ->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = nullptr;
    
    Solution sol;
    node* cur = sol.swapNodes(root);
    while(cur){
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
    return 0;
}
