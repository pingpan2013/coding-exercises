/*
 * =====================================================================================
 *
 *       Filename:  level_order_traversal_sec.cc
 *
 *    Description:  dfs + queue to solve level order traveral
 *
 *        Created:  01/25/2015 23:37:25
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
    // method 1: queue
    vector<vector<int> > levelOrder_(TreeNode *root) {
        vector<vector<int> > res;
        if(!root)   return res;
        
        queue<pair<TreeNode*, int> > queue;
        queue.push(make_pair(root, 1));
        
        vector<int> cur;
        
        while(!queue.empty()){
            auto top = queue.front();
            queue.pop();
            
            cur.push_back(top.first->val);
            
            if(queue.empty() || top.second != queue.front().second){
                res.push_back(cur);
                cur.clear();
            }
            
            if(top.first->left) queue.push(make_pair(top.first->left, top.second + 1));
            if(top.first->right) queue.push(make_pair(top.first->right, top.second + 1));
        }
        
        return res;
    }
    
    // method 2: dfs
    vector<vector<int>> levelOrder(TreeNode *root){
        vector<vector<int> > res;
        if(!root)   return res;
        
        int level = getHeight(root);
        res.resize(level);
        dfs(res, root, 0);
        
        return res;
    }
    
private:
    void dfs(vector<vector<int> > &res, TreeNode *root, int lvl){
        if(!root)   return;
        
        res[lvl].push_back(root->val);
        dfs(res, root->left, lvl+1);
        dfs(res, root->right, lvl+1);
    }

    int getHeight(TreeNode *root){
        if(!root)   return 0;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }
};


