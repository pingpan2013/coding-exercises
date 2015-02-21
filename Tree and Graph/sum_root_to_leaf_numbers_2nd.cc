/*
 * =====================================================================================
 *
 *       Filename:  sum_root_to_leaf_numbers_2nd.cc
 *
 *    Description:  sum root to leaf numbers, 2nd try 
 *
 *        Created:  02/20/2015 20:23:21
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
        if(!root)   return 0;
        
        int sum = 0;
        string num;
        dfs(root, num, sum);
        
        return sum;
    }
    
private:
    void dfs(TreeNode *root, string &num, int &sum){
        if(!root)   return;
        
        num.push_back(root->val + '0');
        if(!root->left && !root->right){
            sum += atoi(num.c_str());   // there may be overflow
            num.pop_back();
            return;
        }
        
        dfs(root->left, num, sum);
        dfs(root->right, num, sum);
        num.pop_back();
    }
};


