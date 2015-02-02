/*
 * =====================================================================================
 *
 *       Filename:  partition_list_2nd.cc
 *
 *    Description:  partitioning list
 *
 *        Created:  02/02/2015 11:38:02
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
    // three methods, insert smaller ones from the front
    //        or      insert bigger ones from the end
    //        or      create a new list and then splice the two lists together, we use this method
    ListNode *partition(ListNode *head, int x) {
        if(!head || !head->next)    return head;
        
        ListNode dummyNode(-1);
        dummyNode.next = head;
        ListNode *q = &dummyNode;
        
        ListNode newHead(-1);
        ListNode *p = &newHead;
        
        while(q->next){
            if(q->next->val < x){
                q = q->next;
                continue;
            }    
            
            ListNode *next = q->next;
            
            q->next = (q->next->next) ? q->next->next : nullptr;   // take care, no need to advance q since q->next already changed
            //q = q->next;
            
            p->next = next;
            p = p->next;
        }
        
        p->next = nullptr;
        q->next = newHead.next;
        
        return dummyNode.next;
    }
};





