/*
 * =====================================================================================
 *    Description:  Preorder traverse a binary tree 
 *        Created:  09/19/2014 01:00:10 AM
 *       Compiler:  g++ 4.7.0
 * =====================================================================================
 */

#include <iostream>
#include <stack>
#include <vector>
#include "binaryTree.h"

using namespace std;

class Solution{
public:
    /* Solution using recursion */
    void preOrderTraverse_rec(node* root){
        if(!root)
            return;
        
        cout << root->data << " ";
        preOrderTraverse_rec(root->left);
        preOrderTraverse_rec(root->right);
    }
    
    // Solution using iteration
    void preOrderTraverse_iter(node* root) {
        stack<node*> st;
        node *current = root;
        while (!st.empty() || current) {
            while(current){
                cout << current->data << " ";
                st.push(current);
                current = current->left;
            }
            
            current = st.top();
            st.pop();
            current = current->right;
        }
        cout << endl;
    }

     // iterative method 2, faster
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if(!root)   return res;
        
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()){
            TreeNode *top = st.top();
            res.push_back(top->val);
            st.pop();
            
            if(top->right)  st.push(top->right);
            if(top->left)   st.push(top->left);
        }
        
        return res;
    }
};

int main(){
    Solution sol;
    node *root = new node(1);
    node *node1 = new node(2);
    node *node2 = new node(3);
    node *node3 = new node(4);
    node *node4 = new node(5);
    root->left  = node1;
    root->right = node2;
    node1->right= node3;
    node3->left = node4;
    
    cout << "Recursion: " << endl;
    sol.preOrderTraverse_rec(root);
    cout << endl;

    cout << "Iteration: " << endl;
    sol.preOrderTraverse_iter(root);
}



