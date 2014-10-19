/*
 * =====================================================================================
 *
 *    Description:  add two linked lists representing two non-negative numbers.
 *                  The digits are stored in reverse order and each of their codes
 *                  contain a single digit. Add the two numbers and return it as a 
 *                  linked list.
 *
 *                  example:(1->4->3) + (5->6->4)
 *                  return :(7->0->8)
 *
 *        Created:  09/20/2014 05:36:08 PM
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include "linklist.h"
#include <cassert>

using namespace std;

class Solution{
public:    
    node* addTwoNumbers(node* n1, node* n2){
        if(!n1) return n2;
        if(!n2) return n1;
        
        node* cur1 = n1; 
        node* cur2 = n2; 
        node* res  = new node(-1);
        node* cur = res;

        unsigned int temp = 0;
        unsigned int sum = 0;
        unsigned int digit = 0;
        while(cur1 &&  cur2){
            sum = cur1->data + cur2->data + temp;
            digit = (sum >= 10) ? sum-10 : sum;
            temp = (sum >= 10) ? 1 : 0;
            
            node *newNode = new node(digit);
            cur->next = newNode;
            cur1 = cur1->next;
            cur2 = cur2->next;
            cur = newNode;
        }
       
        node *rest = res;
        if(!cur1 && !cur2)  return rest->next;
        else{
            rest = (cur1) ? cur1 : cur2;
        }

        assert(rest && "rest cannot be nullptr here!");

        while(rest){
            sum = rest->data + temp;
            digit = (sum >= 10) ? sum-10 : sum;
            temp = (sum >= 10) ? 1 : 0;
            node *newNode = new node(digit);
            cur->next = newNode;

            cur = cur->next;
            rest = rest->next;
        }

        return res->next;
    }
};

int main(){
    Solution sol;
    node *node1 = new node(2);
    node *node2 = new node(4);
    //node *node3 = new node(3);
    node1->next = node2;
    //node2->next = node3;

    node *node4 = new node(5);
    node *node5 = new node(6);
    node *node6 = new node(4);
    node4->next = node5;
    node5->next = node6;

    node *res = sol.addTwoNumbers(node1, node4);

    unsigned int cnt = 0;
    while(res){
        cnt ++;
        cout << res->data << " ";
        res = res->next;

        if(cnt > 10)    break;
    }
    cout << endl;
}



