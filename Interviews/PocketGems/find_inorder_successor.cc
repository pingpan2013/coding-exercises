/*
 * =====================================================================================
 *
 *       Filename:  find_inorder_successor.cc
 *
 *    Description:  find inorder successor in BST
 *                  CC150 #4.6
 *
 *        Created:  02/19/2015 00:55:16
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

/* Each node has a parent node */
// pretty straight forward
TreeNode* inorderSuccesor(TreeNode *p){
    if(!p)  return nullptr;

    if(p->right){
        p = p->right;
        while(p){
            p = p->left;
        }
        return p;
    }
    else{
        if(p->parent && p == p->parent->left){
            return p->parent;
        }
        else{
            // Go up until we are on the left instead of the right

            // check p and p->parent in case we are initially on the rightmost node, 
            // it doesnt have inordersuccesor!
            // then p->parent may become nullptr
            // it will cause error if we use p->parent->right in this situation
            while(p && p->parent && p == p->parent->right){
                p = p.parent;
            }

            return p->parent;
        }
    }
}

/* Each node doesnt have parent node */
TreeNode* inorderSuccesor_(TreeNode *root, TreeNode *p){
    if(!p || !root) return nullptr;
    
    if(p->right){
        p = p->right;
        while(p){
            p = p->left;
        }
        return p;
    }

    TreeNode *succ = nullptr;
    while(root){
        if(root->val < p->val){
            root = root->right;
        }
        else if(root->val > p->val){
            succ = root;   // the potential succ node
            root = root->left;  
        }
        else
            break;  // reaching node p
    }

    return succ;  // already handled the case if p is the right most node which 
                  // doesnt have inorder succesor
}
