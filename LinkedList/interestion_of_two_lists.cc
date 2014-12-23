/*
 * =====================================================================================
 *
 *       Filename:  interestion_of_two_lists.cc
 *
 *    Description:  intersection of two linked lists 
 *
 *        Created:  12/22/2014 19:40:32
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
    // Method 1:
    // with extra space
    // using hashmap to record the address along the traversal path
    //
    // MLE: Memory Limit Exceeded
    
    // Method 2:
    // without extra space, complexity O(m+n)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        if(!headA || !headB)
            return nullptr;
        
        int len1 = 0;
        int len2 = 0;
        
        ListNode *cur1 = headA;
        ListNode *cur2 = headB;
        
        // calculate the difference between the lengths of the two linked lists
        while(cur1){
            len1 ++;
            cur1 = cur1->next;
        }
        
        while(cur2){
            len2 ++;
            cur2 = cur2->next;
        }
        
        int diff_len = len2 - len1;
        
        cur1 = headA;
        cur2 = headB;
        if(diff_len > 0){
            while(diff_len --)
                cur2 = cur2->next;
        }
        else if(diff_len < 0){
            while(diff_len ++)
                cur1 = cur1->next;
        }
        
        // Compare the next pointer
        while(cur1 && cur2){
            if(cur1 == cur2)
                return cur1;
            
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        
        return nullptr;
    }
};

