/*
 * =====================================================================================
 *
 *       Filename:  store_bt_to_array.cc
 *
 *    Description:  store binary tree to an array
 *
 *        Created:  02/24/2015 15:02:44
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <cmath>
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

int getDepth(TreeNode *root){
    if(!root)   return 0;

    return max(getDepth(root->left), getDepth(root->right)) + 1;
}

void dfs(vector<int> &ret, TreeNode *root, int index){
    if(!root)    return;

    ret[index] = root->val;
    dfs(ret, root->left, 2*index+1);
    dfs(ret, root->right, 2*index+2);
}

vector<int> transform(TreeNode* root){
    vector<int> ret;
    if(!root)   return ret;

    int depth = getDepth(root);
    ret.resize(pow(2, depth));    

    dfs(ret, root, 0);
    return ret;
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
    
    vector<int> ret = transform(root);
    
    cout << "Size: " << ret.size() << endl;
    for(auto it : ret){
        cout << it << " ";
    }
    cout << endl;
 
    return 0;
}

