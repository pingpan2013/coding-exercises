/*
 * =====================================================================================
 *    Description:  Define the node of a tree
 *
 *        Created:  09/19/2014 01:00:10 AM
 *       Compiler:  g++ 4.7.0
 * =====================================================================================
 */


struct ListNode{
    int val;
    ListNode* next;
    ListNode(int _data): val(_data), next(nullptr){}
};


