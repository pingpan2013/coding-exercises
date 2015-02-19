/*
 * =====================================================================================
 *
 *       Filename:  lowest_common_ancestor.cc
 *
 *    Description:  lowest common ancestor
 *
 *        Created:  02/19/2015 00:44:32
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

TreeNode *lca(TreeNode *root, TreeNode *p, TreeNode *q){
    if(!root)   return nullptr;

    if(root == p || root == q)  return root;

    TreeNode *l = lca(root->left, p, q);
    TreeNode *r = lca(root->right, p, q);

    if(l && r)  return root;
    return l ? l : r;
}

/* Follow up */

// The problem with this code occurs when either p or q is not present in the bst
// This solution cannot distinguish between these two cases:
// 1. p is a child of q (or verse versa)
// 2. q is in the tree while p is not
// both of these two cases will return q, but in the second case it should return nullptr
//
// Solution 1:
// Traverse the tree first to make sure that both p and q are in the tree
//
// Solution 2
// make_pair<TreeNode*, bool> in indicate this case if bool = false
// Reference: CC150 4.7
