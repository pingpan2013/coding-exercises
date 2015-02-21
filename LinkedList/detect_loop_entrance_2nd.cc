/*
 * =====================================================================================
 *
 *       Filename:  detect_loop_entrance_2nd.cc
 *
 *    Description:  2nd try
 *
 *        Created:  02/21/2015 15:33:52
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
    ListNode *detectCycle(ListNode *head) {
        if(!head)   return head;
        
        ListNode *p = head;
        ListNode *q = head;
        while(q && q->next){
            p = p->next;
            q = q->next->next;
            
            if(p == q)  break;
        }
        
        // no cycle
        if(!q || !q->next)  return nullptr;
        
        p = head;
        while(q != p){
            p = p->next;
            q = q->next;
        }
        
        return p;
    }
};
