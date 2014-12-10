/*
 * =====================================================================================
 *
 *       Filename:  min_depth_of_bt.cc
 *
 *    Description:  Minimal depth of binary tree
 *
 *        Created:  12/10/2014 18:09:20
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
    // For BT probelms, first consider BFS or DFS
    // (1) For BFS, use queue
    // (2) For DFS, use recursion

    // BFS
    int minDepth_(TreeNode *root) {
        if(!root) return 0;
        
        queue< pair<TreeNode*, int> >  queue;
        queue.push(make_pair(root, 1));
        
        while(!queue.empty()){
            if(!queue.front().first->left && !queue.front().first->right)
                return queue.front().second;
                
            pair<TreeNode*, int> curNode = queue.front();
            queue.pop();
            
            if(curNode.first->left)
                queue.push(make_pair(curNode.first->left, curNode.second+1));
            
            if(curNode.first->right)
                queue.push(make_pair(curNode.first->right, curNode.second+1));
        }
    }
    
    // DFS
    int minDepth(TreeNode *root){
        // Exit 1
        if(!root)   return 0;
        
        // Exit 2
        if(!root->left && !root->right){
            return 1;
        }
        // Recursion and DFS
        else if(!root->left && root->right){
            return (1 + minDepth(root->right));
        }
        else if(root->left && !root->right){
            return (1 + minDepth(root->left));
        }
        else{
            return 1 + min(minDepth(root->left), minDepth(root->right));
        }
    }
};



