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
