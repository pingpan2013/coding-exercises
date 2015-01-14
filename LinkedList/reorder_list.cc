/*
 * =====================================================================================
 *
 *       Filename:  reorder_list.cc
 *
 *    Description:  reorder list
 *
 *        Created:  01/13/2015 16:36:15
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

#include "leetcode.h"
#include <iostream>

using namespace std;

class Solution {
public:
    void reorderList(ListNode *head) {
        if(!head || !head->next || !head->next->next)   return;
        
        // split list
        ListNode *slow = head;
        ListNode *fast = head;
        

        while(slow && fast &&fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
 
        fast = slow->next;
        slow->next = nullptr;
       
        // reverse the second half of the linked list
        ListNode *pre = nullptr;
        ListNode *next = nullptr;
        while(fast){
            next = fast->next;
            fast->next = pre;
            pre = fast;
            fast = next;
        }
        
        fast = pre;     
        slow = head;
        // Merge the two lists: head and head_2
        while(slow){
            if(fast){
                ListNode *next1 = slow->next;
                ListNode *next2 = fast->next;
            
                slow-> next = fast;
                fast->next = next1;
                
                slow = next1;
                fast = next2;
            }
            else break;
        }
    }
};

int main() {
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = nullptr;

    Solution sln;

    sln.reorderList(&n1);

    return 0;
}
