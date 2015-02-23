/*
 * =====================================================================================
 *    Description: given a list, swap every two adjacent nodes and return its head 
 *                 1. only use constant space
 *                 2. cannot modify the values in the nodes
 *        Created:  09/27/2014 03:30:09 PM
 *       Compiler:  g++ 4.7.0
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
    // recursion
    ListNode *swapPairs(ListNode *head){
        if(!head)   return head;
        
        if(head && head->next){
            ListNode *next = head->next->next;
            ListNode *temp = head;
            
            head = head->next;
            head->next = temp;
            temp->next = swapPairs(next);
        }
        
        return head;
    } 
    
    // iterative
    ListNode *swapPairs(ListNode *head) {
        if(!head || !head->next)
            return head;
        
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;

        ListNode *cur = head;
        ListNode *pre = dummyNode;
        
        
        while(cur && cur->next){
            ListNode *next = cur->next->next;
            
            pre->next = cur->next;
            cur->next = next;
            pre->next->next = cur;
            
            pre = cur;
            cur = next;
        }
        
        head = dummyNode->next;
        delete dummyNode;
        return head;
    }
};

