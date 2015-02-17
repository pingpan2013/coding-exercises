/*
 * =====================================================================================
 *
 *       Filename:  recover_bst.cc
 *
 *    Description:  Two elements of a binary search tree (BST) are swapped by mistake.
                    Recover the tree without changing its structure. 
 *
 *        Created:  01/03/2015 17:54:50
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
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
    
    void recoverTree(TreeNode *root) {
        if(!root)   return;
        
        TreeNode *first = nullptr;   // should be initialized to nullptr, otherwise may cause
        TreeNode *second = nullptr;  // overflow
        TreeNode *pre = nullptr;
        
        dfs(root, pre, first, second);
        
        if(first && second)
            swap(first->val, second->val);
    }

private:
    void dfs(TreeNode *root, TreeNode* &pre, TreeNode* &first, TreeNode* &second){
        if(!root)
            return;
            
        dfs(root->left, pre, first, second);
        
        if(pre && pre->val > root->val){
            if(!first){
                first = pre;
            }    
            second = root;
        }
        pre = root;
        
        dfs(root->right, pre, first, second);
    }
};

