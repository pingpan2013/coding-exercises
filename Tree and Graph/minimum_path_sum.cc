/*
 * =====================================================================================
 *
 *       Filename:  minimum_path_sum.cc
 *
 *    Description:  
 *
 *        Created:  01/30/2015 00:30:15
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

int minimum_path_sum(TreeNode* root){
    if(!root)   return 0;

    int min_sum = INT_MIN;
    dfs(root, 0, min_sum);
    return 
}

void dfs(TreeNode* root, int cur_sum, int &min_sum){
    if(!root)   return;

    cur_sum += root->val;
    if(!root->left && !root->right){
        if(cur_sum < min_sum){
            min_sum = cur_sum;
        }
        return;
    }

    dfs(root->left, cur_sum, min_sum);
    dfs(root->right, cur_sum, min_sum);

//    cur-_sum -= root->val;
}


