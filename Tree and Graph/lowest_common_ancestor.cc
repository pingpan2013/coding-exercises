/*
 * =====================================================================================
 *
 *       Filename:  least_common_ancestor.cc
 *
 *    Description:  LCA: lowest common ancestor
 *
 *        Created:  02/01/2015 21:47:05
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution{
public:
    // method 1: top down, traverse down the left or right subtree to count how many times
    //           p or q appears, go down
    
    // method 2: bottom up, worst case O(n)
    TreeNode* find_LCA(TreeNode *root, TreeNode *p, TreeNode *q){
        if(!root)   return root;

        if(root == p || root == q)  return root;

        TreeNode *l = find_LCA(root->left, p, q);
        TreeNode *r = find_LCA(root->right, p, q);
        
        if(l && r)  return root;
        return l ? l : r;
    }
};

