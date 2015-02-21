/*
 * =====================================================================================
 *
 *       Filename:  reorder_list_2nd.cc
 *
 *    Description:  2nd try
 *
 *        Created:  02/21/2015 15:53:08
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
    void reorderList(ListNode *head) {
        if(!head || !head->next || !head->next->next)   return;
        
        // partition
        ListNode *p = head;
        ListNode *q = head;
        while(q && q->next){
            p = p->next;
            q = q->next->next;
        }
        
        q = p->next;
        p->next = nullptr;
        
        // reverse the second half of the list
        ListNode *prev = nullptr;
        while(q){
            ListNode *next = q->next;
            q->next = prev;
            prev = q;
            q = next;
        }
        
        // merge
        q = prev;
        p = head;
        while(p && q){
            ListNode *next1 = p->next;
            ListNode *next2 = q->next;
            
            q->next = p->next;
            p->next = q;
            
            p = next1;
            q = next2;
        }
        
        return;
    }
};


