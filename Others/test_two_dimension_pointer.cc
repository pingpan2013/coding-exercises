/*
 * =====================================================================================
 *
 *       Filename:  test_two_dimension_pointer.cc
 *
 *    Description:  
 *
 *        Created:  12/10/2014 16:53:53
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

struct node{
    int value;
    node* next;
};

int main(){
  
    node* n = nullptr;
    node** pCur = &n;

    cout << &n << endl;
    
    cout << pCur << endl;
    cout << *pCur << endl;

    node* newNode = new node();
    newNode->value = 1;
    newNode->next = nullptr;

    *pCur = newNode;
    cout << n << endl;    

    return 0;
}




