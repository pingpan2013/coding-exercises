/*
 * =====================================================================================
 *
 *       Filename:  validate_bst.cc
 *
 *    Description:  validate a BST
 *
 *        Created:  02/15/2015 09:55:00
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
    // 
    bool isValidBST(TreeNode *root) {
        long long pre = INT_MIN;  // cannot let pre = INT_MIN -1 directly, then pre = 0 because of
                                  // integer overflow
        pre--;
        return dfs(root, pre);
    }
    
    bool isValidBST_(TreeNode *root){
        long long minVal = INT_MIN;   // the same as pre
        minVal--;
        
        long long maxVal = INT_MAX;   // the same as pre
        maxVal++;
        
        return valid(root, minVal, maxVal);
    }
    
private:
    bool valid(TreeNode *root, long long min, long long max){
        if(!root)   return true;
        
        if(root->val <= min || root->val >= max)  return false;
        
        return valid(root->left, min, root->val) && valid(root->right, root->val, max);
    }


    bool dfs(TreeNode *root, long long &pre){
        if(!root)   return true;
        
        if(dfs(root->left, pre)){
            if(root->val > pre){
                pre = root->val;
                return dfs(root->right, pre);
            }
            else  return false;
        }
        else return false;
    }
};


