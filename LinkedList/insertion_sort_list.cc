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
    ListNode *insertionSortList(ListNode *head) {
        if(!head || !head->next)
            return head;
        
        // The list always begins with dummyNode->next
        ListNode *dummyNode = new ListNode(INT_MIN);
        ListNode *cur = head;
        
        while(cur){
            ListNode *next = cur->next;
            
            //ListNode *insertion_node = find_insertion_node(dummyNode, cur);
            ListNode *insertion_node = dummyNode;
            while(insertion_node->next && insertion_node->next->val < cur->val)
                insertion_node = insertion_node->next;
            
            cur->next = insertion_node->next;
            insertion_node ->next = cur;
            
            cur = next;        
        }
        
        return dummyNode->next;
    }
    
private:
    ListNode *find_insertion_node(ListNode* head, ListNode* cur){
        while(head->next && head->next->val < cur->val)
            head = head->next;
            
        return head;
    }
};




