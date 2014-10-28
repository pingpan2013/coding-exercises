/*
 * =====================================================================================
 *    Description:  Detect if a linked list has a cycle in it
 *                  Can u solve this without using extra space?
 *        Created:  09/20/2014 05:36:08 PM
 *       Compiler:  g++ 4.7.0
 * =====================================================================================
 */


#include "linklist.h"
#include <iostream>

using namespace std;

class Solution{
public:    
    bool isExistCycle(node* root){
        if(!root)   return false;
        node* slow_ptr = root;
        node* fast_ptr = root;

        while(slow_ptr && fast_ptr){
            if(slow_ptr == fast_ptr)
                return true;
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }
        return false;
    }
};



