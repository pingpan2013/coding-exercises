/*
 * =====================================================================================
 *
 *       Filename:  merge_k_sorted_lists.cc
 *
 *    Description:  merge k sorted list, similiar with sort k iterators in Indeed interview
 *                  question.
 *
 *        Created:  02/25/2015 11:53:33
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
 
struct Comp{
    bool operator()(ListNode *x, ListNode *y){
        return (x->val > y->val);
    }
};
 
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty())   return nullptr;
        
        priority_queue<ListNode*, vector<ListNode*>, Comp> pqueue;
        for(auto listHead : lists){
            if(listHead) pqueue.push(listHead);
        }
        
        ListNode dummy(-1);
        ListNode *cur = &dummy;
        
        while(!pqueue.empty()){
            ListNode *smallestElement = pqueue.top();
            pqueue.pop();
            cur->next = smallestElement;
            cur = cur->next;
            
            if(smallestElement->next){
                pqueue.push(smallestElement->next);
            }
        }
        
        return dummy.next;
    }
};


