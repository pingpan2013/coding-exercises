/*
 * =====================================================================================
 *
 *       Filename:  flatten_binary_tree_to_list.cc
 *
 *    Description:  Given a binary tree, flatten it to a linked list in-place.

                    For example,
                    Given

                           1      
                          / \
                         2   5
                        / \   \
                       3   4   6

                    The flattened tree should look like:

                    1                    
                     \
                      2
                       \
                        3
                         \
                          4
                           \
                            5
                             \
                              6
 *
 *        Created:  02/17/2015 22:38:13
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
    void flatten(TreeNode *p) {
        if(!p)   return;
        
        while(p){
            if(p->left){
                TreeNode *q = p->left;
                
                while(q->right){
                    q = q->right;
                } 
                
                q->right = p->right;
                p->right = p->left;
                
                // !!
                // !! don't forget to set the left subtree to nullptr
                p->left = nullptr;
            }
            
            p = p->right;
        }
    }
};


