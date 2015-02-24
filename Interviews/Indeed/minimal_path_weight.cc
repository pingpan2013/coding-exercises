/*
 * =====================================================================================
 *
 *    Description:  find the path with minimal weight from root to leaf 
 *
 *        Created:  02/24/2015 15:02:44
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <vector>
#include <iostream>

using namespace std;

struct TreeNode{
    TreeNode(int _val) : left(nullptr), right(nullptr){
        val = _val;
    }

    TreeNode *left;
    TreeNode *right;
    int val;
};

void dfs(TreeNode *root, int curWeight, int &ret){
    if(!root)   return;

    if(!root->left && !root->right){
        ret = min(ret, curWeight + root->val);
        return;
    }
    
    // cut off some subtrees when the current sum already
    // exceeds the current minimal sum
    if(curWeight + root->val > ret){
        return;
    }

    dfs(root->left, curWeight+root->val, ret);
    dfs(root->right, curWeight+root->val, ret);
}


int minPath(TreeNode *root){
    if(!root)   return 0;

    int ret = INT_MAX;  // do we need to consider overflow?
    dfs(root, 0, ret);

    return ret;
}

void test(TreeNode *root){
    cout << "Minimal Path: " << minPath(root) << endl;
}

int main()
{
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->left->left=new TreeNode(5);
    root->left->right=new TreeNode(6);
    root->right->left=new TreeNode(7);
    root->left->left->left->left=new TreeNode(8);
    test(root);  // 9

    root->left->right->left = new TreeNode(100);
    test(root);  // 11

    root->right->left->right = new TreeNode(100);
    test(root);  // 20

    return 0;
}

