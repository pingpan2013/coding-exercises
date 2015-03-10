/*
 * =====================================================================================
 *
 *       Filename:  constuct_bt_from_preorder.cc
 *
 *    Description:  construct bst from its preorder traversal sequence
 *
 *        Created:  03/10/2015 00:40:36
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

// method 1: time complexity O(n^2)
TreeNode* construct(vector<int> preorder){
    if(preorder.empty())    return nullptr;
    
    int start = 0;
    return helper(preorder, start, 0, preorder.size() - 1);
}

TreeNode* helper(vector<int> preorder, int &index, int low, int high){
    if(index >= preorder.size() || low > high){
        return nullptr;
    }
    
    TreeNode *root = new TreeNode(preorder[index]);

    if(low == high) return root;

    // find the first element that is bigger than root->val
    int rIndex = -1;
    for(int rIndex = low; rIndex<= high; rIndex ++){
        if(preorder[rIndex] > root->val) break;
    }
    
    index ++;
    root->left  = helper(preorder, index, low, rIndex - 1);
    root->right = helper(preorder, index, rIndex, high);

    return root;
}

// method 2: first get the inorder sequence by sort(preorder)
//           then construct the bst by combining the preorder and inorder sequences
// Complexity: O(n^2)

// method 3: similiar with the solution of "validate bst"
//           set an range for every node, initially it's <INT_MIN, INT_MAX>
//           the first node is definitely in the range, so we construct 
//           the node. To construct its substree, set the range to <INT_MIN, root->val>, if the 
//           value is in the range, it is definitely in its left subtree. Similiar with the right 
//           subtree. Recursively construct the bst by updating the ranges
//           Reference: http://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversa/
TreeNode* construct_bst(vector<int> &pre){
    if(pre.empty()) return nullptr;
    
    int start = 0;
    return helper(pre, start, INT_MIN, INT_MAX);
}

TreeNode* helper(vector<int> &pre, int &index, int minVal, int maxVal){
    if(index >= pre.size()) return nullptr;

    TreeNode* root = nullptr;

    if(pre[index] > min && pre[index] < max){
        root = new TreeNode(pre[index]);
        index ++;

        if(index >= pre.size()) break;

        root->left = helper(pre, index, minVal, root->val);
        root->right = helper(pre, index, root->val, maxVal);
    }

    return root;
}

