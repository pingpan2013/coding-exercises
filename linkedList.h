/*
 * =====================================================================================
 *
 *       Filename:  testPush.cpp
 *
 *    Description:  a simple linked list class
 *
 *        Created:  03/17/2014 04:17:15 PM
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H


struct ListNode{
	ListNode* next;
	int data;
};


class linkedList{
public:
	linkedList(){ head = nullptr; }
	
	// utility functions
	void Build_from_head();                 /* add items from the front */
	void Build_from_tail();                 /* add items from the tail */
	void Push(ListNode** head, int data);       /* push a item into the linkedlist */
   	void printList();                       /* display the linkedlist */
	int Length();                           /* calculate the current length */

	// The only member, the head pointer
	ListNode* head;
};

#endif
