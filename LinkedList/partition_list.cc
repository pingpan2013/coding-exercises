/*
 * =====================================================================================
 *
 *       Filename:  partition_list.cc
 *
 *    Description:  Given a linked list and a value x, partition it such
 *                  that all nodes less than x come before nodes greater than or equal to x.
 *
 *                  You should preserve the original relative order of the nodes in each 
 *                  of the two partitions.
 *
 *                  For example,
 *                  Given 1->4->3->2->5->2 and x = 3,
 *                  return 1->2->2->4->3->5. 
 *
 *        Created:  12/28/2014 11:02:35
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
    ListNode *partition(ListNode *head, int x) {
        if(!head)   return nullptr;
        
        ListNode *safeG = new ListNode(0);
        safeG->next = head;
        ListNode *cur = safeG;

        int length = 0;
        ListNode *tail = safeG;
        while(tail->next){
            tail = tail->next;
            length ++;
        }
        
        while(length-- > 0){
            if(cur->next->val >= x){
                tail->next = cur->next;
                tail = tail->next;
                
                cur->next = cur->next->next;
            }
            else{
                cur = cur->next;
            }
        }
        tail->next = nullptr;
        
        head = safeG->next;
        delete safeG;
        return head;
    }
};
