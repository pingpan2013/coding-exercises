/*
 * =====================================================================================
 *
 *       Filename:  convert_sorted_list_to_bst.cc
 *
 *    Description:  convert sorted list to bst
 *
 *        Created:  02/17/2015 21:34:30
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
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(!head)   return nullptr;
        
        return helper(head, nullptr);
    }
    
private:
    TreeNode* helper(ListNode *head, ListNode *end){
        if(head == end)   return nullptr;
        
        ListNode *p = head;
        ListNode *q = head;
        while(q && q->next && q != end && q->next != end){
            p = p->next;
            q = q->next->next;
        }
        
        TreeNode *root = new TreeNode(p->val);
        root->left = helper(head, p);
        root->right = helper(p->next, end);
        
        return root;
    }
};
