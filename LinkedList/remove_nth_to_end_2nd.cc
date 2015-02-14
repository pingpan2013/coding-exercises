/*
 * =====================================================================================
 *
 *       Filename:  remove_nth_to_end_2nd.cc
 *
 *    Description:  2 nd try
 *
 *        Created:  02/13/2015 23:21:32
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(!head)   return head;
        
        ListNode *p = head;
        for(int i = 0; i < n; i++){
            p = p->next;
        }
        
        // attention:      
        // if n is the length: corner case
        if(!p){
            head = head->next;
            return head;
        }
        
        ListNode *q = head;
        while(p->next){
            p = p->next;
            q = q->next;
        }
        
        q->next = q->next->next;
        return head;
    }
};
