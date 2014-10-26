/*
 * =====================================================================================
 *    Description:  sort linked list with O(nlogn) and constant space
 *
 *        Created:  09/20/2014 05:36:08 PM
 *       Compiler:  g++ 4.7.0
 * =====================================================================================
 */


#include <iostream>
#include <cassert>
#include "linkedList.h"

using namespace std;

class Solution{
public: 
    // sort list using recursion, space won't be constant in this case
    ListNode* sortList_rec(ListNode* head){
        assert(head != nullptr && "Empty list!");
        if(head->next == nullptr)
            return head;

        ListNode *l = head; 
        ListNode *r = head; 

        // find the mid node of the list
        while(l->next && l->next->next){
            l = l->next->next;
            r = r->next;
        }
        
        l = r;
        r = r->next;
        l->next = nullptr; // attention here

        // Recursively sort left and right parts of the list
        l = sortList_rec(head);
        r = sortList_rec(r);
        
        // Merge
        return mergeList(l, r);
    }

private:
    ListNode* mergeList(ListNode *l, ListNode *r){
        ListNode *res = new ListNode(-1);
        ListNode *cur = res;

        while(l && r){
            if(l->val < r->val){
                cur->next = l;
                l = l->next; 
            }
            else{
                cur->next = r;
                r = r->next;
            }
            cur = cur->next;
        } 

        // handle the rest part of l or r
        if(!l)
            cur->next = r;
        
        if(!r)
            cur->next = l;
        
        cur = res->next;
        delete res;
        return cur;
    }
};

int main(){

    Solution sol;
    
    linkedList *list = new linkedList;
    list->Build_from_head();
    list->Push(&list->head, 10);
    list->Push(&list->head, 8);
    list->Push(&list->head, 14);
    list->Push(&list->head, 5);
    list->printList();
    list->head = sol.sortList_rec(list->head); 
    list->printList();
    
    delete list;
    return 0;
}



