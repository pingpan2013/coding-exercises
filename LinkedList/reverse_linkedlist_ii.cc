/*
 * =====================================================================================
 *
 *       Filename:  reverse_linkedlist_ii.cc
 *
 *    Description:  reverse linked list II
 *
 *        Created:  01/13/2015 21:11:03
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(!head || m >= n)  return head;
        
        int k = n - m;
        if(k == 0)  return head;

        ListNode dummy(-1);
        dummy.next = head;
        ListNode *p = &dummy;
        
        // get the beginning point
        for(int i = 1; i < m; i ++)
            p = p->next;
        
        // q is the insertion node
        ListNode *q = p->next;
        
        // insert the reversed node one by one, similiar with insertion sort
        for(int i = m; i < n; i++){
            ListNode *next = q->next;
            q->next = next->next;
            next->next = p->next;
            p->next = next;
        }
        
        return dummy.next;
    }
};


