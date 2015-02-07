/*
 * =====================================================================================
 *
 *       Filename:  test_link_list.cc
 *
 *    Description:  
 *
 *        Created:  12/26/2014 10:09:39
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include "linkedList.h"
#include <iostream>

using namespace std;

void f(ListNode* n){
    n->next->val = 10;
    
    n = n->next;

    return;
}


int main(){
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);

    n1->next = n2;

    f(n1);

    cout << n1->val << endl;
    cout << n2->val << endl;

    return 0;
}

