/*
 * =====================================================================================
 *
 *       Filename:  reverse_nodes_in_k_group.cc
 *
 *    Description:  reverse nodes in k-group
 *
 *        Created:  01/13/2015 21:17:26
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(!head || k < 2)   return head;
        
        ListNode dummyNode(-1);
        dummyNode.next = head;
        
        ListNode *p = &dummyNode;
        ListNode *prev;
        
        while(p){
            prev = p;
            for(int i = 0; i < k; i++){
                p = p->next;
                if(!p)  return dummyNode.next;
            }
            
            // reverse a group: insertion from the front
            ListNode *end = p->next;
            ListNode *cur = prev->next;
            while(cur && cur->next != end){
                ListNode *next = cur->next;
                cur->next = next->next;
                next->next = prev->next;
                prev->next = next;
            }
            
            p = cur;
        }
        
        return dummyNode.next;
    }
};



