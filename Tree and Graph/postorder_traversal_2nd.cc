/*
 * =====================================================================================
 *
 *       Filename:  postorder_traversal_2nd.cc
 *
 *    Description:  Error point: attention, must check if pre is not nullptr
 *
 *        Created:  02/22/2015 00:45:31
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
        vector<int> result;
        if(!root)   return result;
        
        stack<TreeNode*> st;
        st.push(root);
        TreeNode *pre = nullptr;
        
        while(!st.empty()){
            TreeNode *top = st.top();
            
            if(!top->left && !top->right || (pre && (top->left == pre || top->right == pre))){
                result.push_back(top->val);
                st.pop();
                
                pre = top;
            }
            else{
                if(top->right)  st.push(top->right);
                if(top->left)   st.push(top->left);
            }
        }
        
        return result;
    }
};


