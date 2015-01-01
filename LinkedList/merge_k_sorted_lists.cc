/*
 * =====================================================================================
 *
 *       Filename:  merge_k_sorted_lists.cc
 *
 *    Description:  merge k sorted lists
 *
 *        Created:  12/31/2014 18:51:38
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
        if(lists.empty()) return nullptr; 
        if(lists.size() == 1) return lists[0];
        
        priority_queue<ListNode*, vector<ListNode*>, Comp> queue;
        
        for(auto i : lists){
            if(i)
                queue.push(i);
        }        
        
        ListNode* dummyNode = new ListNode(-1);
        ListNode* cur = dummyNode;
        while(!queue.empty()){
            ListNode *temp = queue.top();
            queue.pop();
            if(temp->next)
                queue.push(temp->next);
            
            cur->next = temp;
            cur = cur->next;
        }
        
        return dummyNode->next;
    }
};


