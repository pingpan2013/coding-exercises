/*
 * =====================================================================================
 *
 *       Filename:  find_inorder_successor.cc
 *
 *    Description:  find inorder successor in BST
 *
 *        Created:  02/23/2015 14:44:35
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

// Each node is ith parent node
TreeNode* findInorderSuccessor(TreeNode *root, TreeNode *p){
    if(!root || !p)   return nullptr;
    
    if(p->right){
        p = p->right;
        while(p){
            p = p->left;
        }

        return p;
    }
    else{
        // if p is a left child
        if(p && p->parent && p == p->parent->left){
            return p->parent;
        }
        
        // if p is a right child 
        // Go up until p is on e the left subtree of a node
        while(p && p->parent && p == p->parent->right){
            p = p->parent;
        }
        
        // p->parent might nullptr means that p was originally the rightmost node 
        return p->parent; 
    }
}

// Each node doesn't have a pointer of parent node
TreeNode *findInorderSuccessor_(TreeNode *root, TreeNode *p){
    if(!root || !p) return nullptr;
    
    // if p has right child
    if(p->right){
        p = p->right;
        while(p)    
            p = p->left;
        return p;
    }
    
    // search from the root
    TreeNode *succ = nullptr;
    while(root){
        if(p->val == root->val){
            break;
        }
        else if(p->val < root->val){
            succ = root;
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    
    return succ;
}
