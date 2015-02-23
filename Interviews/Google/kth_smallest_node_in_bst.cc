/*
 * =====================================================================================
 *
 *       Filename:  kth_smallest_node_in_bst.cc
 *
 *    Description:  kth smallest node in BST
 *
 *        Created:  02/22/2015 23:54:37
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

// Method 1: inorder traversal
void findKthSmallest(TreeNode *root, int k, int &cnt, int &ret){
    if(!root)   return;

    findKthSmallest(root->left, k, cnt, ret);
    if(++cnt == k){
        ret = root->val;
        return;
    }  
    findKthSmallest(root->right, k, cnt, ret);
}

int findKthSmallest(TreeNode *root, int k){
    int cnt = 0;
    int ret;

    findKthSmallest(root, k, cnt, ret);
    
    return ret;
}

// Method 2: Order Statistic Tree
//           Reference: http://www.geeksforgeeks.org/find-k-th-smallest-element-in-bst-order-statistics-in-bst/
//
//           Maintain a tree that each of its node stores the information of the number of the nodes of its left 
//           subtree 
//           
//           struct node{
//               int val;
//               int lcnt;   // the # of nodes in its left subtree
//
//               node* left;
//               node* right;
//           };
//
//           Then we in can this in a binary search way. O(lng)
int findKthSmallest(node* root, int k){
    if(!root)   return -1;
    
    int result = -1;
    while(true){
        if(root->lcnt+1 == k){
            result = root->val;
            return result;
        }
        else if(root->lcnt + 1 < k){
            k = k-(root->lvnt+1);
            root = root->right;
        }
        else{
            root = root->left;
        }
    }

    return -1;
}

