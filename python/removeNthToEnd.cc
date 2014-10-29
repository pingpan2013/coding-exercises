/*
 * =====================================================================================
 *    Description:  Given a list, remove the nth node from the end and return its head
 *        Created:  09/20/2014 05:36:08 PM
 *       Compiler:  g++ 4.7.0
 * =====================================================================================
 */


#include "linklist.h"
#include <iostream>

using namespace std;

class Solution{
public:    
    node* removeNth(node* root, int n){
        node* head = root;
        node* pilot = root;
        node* pre = root;
        node* cur = root;
        
        int cnt = 0
        while(cnt++ < n)
            pilot = pilot->next;

        while(cur && pilot){
            cur = cur->next;
            pre = cur;
            pilot = pilot->next;
        }
        
        pre->next = cur->next;
        return head;

    }
};

