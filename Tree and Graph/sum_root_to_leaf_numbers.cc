/*
 * =====================================================================================
 *
 *       Filename:  sum_root_to_leaf_numbers.cc
 *
 *    Description:  sum root to leaf numbers

                    Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
                    An example is the root-to-leaf path 1->2->3 which represents the number 123.
                    Find the total sum of all root-to-leaf numbers.
                    For example,
                      1
                     / \
                    2   3
                    
                    The root-to-leaf path 1->2 represents the number 12.
                    The root-to-leaf path 1->3 represents the number 13.
                    Return the sum = 12 + 13 = 25.

 *
 *        Created:  02/04/2015 23:37:22
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
    int sumNumbers(TreeNode *root) {
        if(!root) return 0;
        
        int sum = 0;
        dfs(root, sum, 0);
        
        return sum;
    }
    
private:
    void dfs(TreeNode *root, int &sum, int tmp){
        if(!root)   return;
        
        if(root && !root->left && !root->right){
            tmp = tmp * 10 + root->val;
            sum += tmp;
            return;
        }
        
        tmp = tmp*10 + root->val;
        dfs(root->left, sum, tmp);
        dfs(root->right, sum, tmp);
    }
};




