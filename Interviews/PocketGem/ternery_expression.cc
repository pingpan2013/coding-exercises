/*
 * =====================================================================================
 *
 *       Filename:  ternery_expression.cc
 *
 *    Description:  construct a tree for ternery expression
 *
 *        Created:  02/22/2015 21:30:56
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

struct Node{
    Node(char c) : val(c){
        left = nullptr;
        right = nullptr;
    }

    char val;
    Node *left;
    Node *right;
};
 
class TerneryExpression{
public:
    TerneryExpression(string &str){
        root = buildTree(str);

        cout << "Done building tree!" << endl;
    }
    
    Node* buildTree(string &str){
        if(str.empty()) return nullptr;
        
        int start = 0;
        return build(str, start);
    }
    
    void outputTree(){
        cout << "DFS:" << endl; 
        dfs(root);
    }

    void dfs(Node *n){
        if(!n)  return;

        cout << n->val << endl;
        dfs(n->left);
        dfs(n->right);
    }

private:
    Node* build(string str, int &pos){
        if(pos >= str.size())   return nullptr;
        
        Node *root = new Node(str[pos]);
        if(pos+1 < str.size() && str[pos+1] == '?'){
            ++pos;
            ++pos;
            root->left = build(str, pos);
        
            ++pos;
            ++pos;
            root->right = build(str, pos);
        }
        
        return root;
    }

    Node *root;
};

int main(){
    cout << "Test 1: " << endl;
    string str1("a?b:c?d:e");
    TerneryExpression te1(str1);
    te1.outputTree();

    cout << "Test 2: " << endl;
    string str2("a?b?c:d:e");
    TerneryExpression te2(str2);
    te2.outputTree();

    return 0;
}
