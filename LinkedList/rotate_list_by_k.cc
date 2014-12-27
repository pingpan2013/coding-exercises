/*
 * =====================================================================================
 *
 *       Filename:  rotate_list_by_k.cc
 *
 *    Description:  Given a list, rotate the list to the right by k places, where k is non-negative.
 *
 *					For example:
 *					Given 1->2->3->4->5->NULL and k = 2,
 *					return 4->5->1->2->3->NULL.
 *
 *        Created:  12/27/2014 12:12:44
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
    ListNode *rotateRight(ListNode *head, int k) {
        if(!head || k <= 0)
            return head;
            
        ListNode *beg = head;
        ListNode *tail = head;
        
        // handle the situation when k is bigger than the length of the linked list
        int length = 0;
        while(beg){
            length ++;
            beg = beg->next;
        }
        
        k = k % length;
        if(k == 0)  return head;
        beg = head;
        
        while(k-- > 0 && tail)
            tail = tail->next;
            
        while(tail->next){
            tail = tail->next;
            beg = beg->next;
        }
        
        tail->next = head;
        head = beg->next;
        beg->next = nullptr;
        
        return head;
    }
};


