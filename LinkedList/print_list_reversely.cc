/*
 * =====================================================================================
 *
 *       Filename:  print_list_reversely.cc
 *
 *    Description:  print list reversely
 *
 *        Created:  02/03/2015 09:38:20
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution{
public:
    // General methods:
    // method 1: use extra space, e.g. stack
    // method 2: reverse the list and then output the list
    
    // method 3: recursion
    void printList(ListNode* head){
        if(!head)   return;

        printList(head->next);

        cout << head->data->val;
    }
};

