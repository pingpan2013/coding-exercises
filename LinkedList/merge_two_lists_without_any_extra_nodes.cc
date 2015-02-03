/*
 * =====================================================================================
 *
 *       Filename:  merge_two_lists_recursively.cc
 *
 *    Description:  merge two linked lists without using any extra nodes
 *
 *        Created:  02/03/2015 09:57:42
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution{
public:
    // method 1: recursion, pretty elegant
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2){
        if(!l1) return l2;
        if(!l2) return l1;

        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }

        if(l1->val > l2->val){
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }

    // method 2: similiar with insertion sort
    ListNode* mergeTwoLists_(ListNode *l1, ListNode *l2){
        if(!l1) return l2;
        if(!l2) return l1;

        // we assume that the head of l1 is smaller than the head of l2
        if(l1->val > l2->val)   return mergeTwoLists(l2, l1);

        // insert l2 to l1
        // prety straight-forward
    }
};
