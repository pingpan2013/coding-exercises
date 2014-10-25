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
#include "linkedlist.h"

using namespace std;

class Solution{
public: 
    // sort list using recursion, space won't be constant in this case
    ListNode* sortList_rec(ListNode* head){
        assert(head != nullptr && "Empty list!");
        if(head->next = nullptr)
            return head;

        ListNode *l = head; 
        ListNode *r = head; 

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

        while(l->next && r->next){
            
        } 


    }
};

int main(){

    Solution sol;


    return 0;
}



