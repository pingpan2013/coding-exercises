/*
 * =====================================================================================
 *
 *       Filename:  convert_bst_to_list.cc
 *
 *    Description:  convert bst to doubly linked list
 *
 *        Created:  03/08/2015 21:32:08
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

void convert(Node *root, Node* &pre, Node* &head)
{
    if(!root)   return;

    convert(root->left, pre, head);
    
    // corner case 1
    if(!pre)   // head of the list
    {
        head = root;
    }
    else
    {
        pre->right = root;
    }

    Node* right = root->right;
    
    // corner case 2
    // update the head's left pointer and the tail's right pointer dynamically
    head->left = root;
    root->right = head;

    pre = root;

    convert(right, pre, head);
}
