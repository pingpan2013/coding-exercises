/*
 * =====================================================================================
 *
 *       Filename:  postorder_traversal.cc
 *
 *    Description:  postorder traversal
 *
 *        Created:  01/16/2015 00:49:57
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if(!root)   return res;
        
        stack<TreeNode*> st;
        st.push(root);
        TreeNode *pre = nullptr;  // the last visited node
        
        while(!st.empty()){
            TreeNode *top = st.top();
            // visit and pop
            if((!top->left && !top->right) || (pre && (top->left == pre || top->right == pre))){
                res.push_back(top->val);
                pre = top;
                st.pop();
            }
            // add new nodes
            else{
                if(top->right)  st.push(top->right);
                if(top->left)   st.push(top->left);
            }
        }
    }
};
