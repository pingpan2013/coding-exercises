/*
 * =====================================================================================
 *
 *       Filename:  path_sum.cc
 *
 *    Description:  path sum
 *
 *        Created:  02/04/2015 23:46:58
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
    bool hasPathSum(TreeNode *root, int sum) {      
        if(!root)   return false;
        
        if(!root->left && !root->right && root->val == sum)    return true;
            
        return hasPathSum(root->left, sum-root->val)
                   || hasPathSum(root->right, sum-root->val);
    }
};


