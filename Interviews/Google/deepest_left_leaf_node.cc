/*
 * =====================================================================================
 *
 *       Filename:  deepest_left_leaf_node.cc
 *
 *    Description:  find the deepest left leaf node in a binary tree.
 *                  Reference: http://www.geeksforgeeks.org/deepest-left-leaf-node-in-a-binary-tree/                 
 *
 *        Created:  02/23/2015 12:06:14
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

// dfs:
// max_level: the max_level of the tree
// cur_level: current level of the tree when traversing
// isLeft:    a flag to indicate if the current node is a left child
void dfs(TreeNode *root, TreeNode *result, int &max_level, int cur_level, bool isLeft){
       
}

Node* deepestLeftLeafNode(TreeNode *root){
    if(root)    return nullptr;

    TreeNode *lnode = nullptr;
    int max_level = 0;
    
    dfs(root, lnode, max_level, 0, false);

    return lnode;
}
