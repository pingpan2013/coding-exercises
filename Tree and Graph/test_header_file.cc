/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  For general test
 *
 *        Created:  10/29/2014 16:51:18
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include "binarytree.h"
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    //int a[] = {1, 2, 3, 4, 5, 6};
    //node* n = create_bst(a, 0, 5);
    
    char b[] = {'c', 'e', 'r', 'n', 'e', 'r'};
    sort(b, b+6);
    node* n = create_bst(b, 0, 5);
    levelOrderTrav(n);
        
    return 0;
}
