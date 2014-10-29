/*
 * =====================================================================================
 *
 *       Filename:  linkedList.cpp
 *
 *    Description:  implement simple linkedList class
 *
 *        Created:  03/17/2014 04:24:16 PM
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include "linkedList.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
 *--------------------------------------------------------------------------------------
 *       Class:  linkedList
 *      Method:  linkedList :: Build_from_end
 * Description:  Build a linked list by pushing ListNode from the head each time
 *--------------------------------------------------------------------------------------
 */
void linkedList::Build_from_head(){
	for(int i = 4; i >= 1; i --)
		Push(&head, i);
}

/*
 *--------------------------------------------------------------------------------------
 *       Class:  linkedList
 *      Method:  linkedList :: Build_from_tail
 * Description:  Build a linked list by pushing ListNode from the tail each time
 *               Using three methods, randomly choose one of them
 *               The difference lies in how to handle the very first ListNode
 *--------------------------------------------------------------------------------------
 */
void linkedList::Build_from_tail(){
	srand(time(nullptr));
	int num_of_method = rand() % 3 + 1;	

	// use special case to handle the first ListNode
	if(num_of_method == 1){
		cout << "Build from tail using method 1!" << endl;
		
		Push(&head, 1);
		ListNode* tail = head;

		for(int i = 2; i < 5; i ++){
			Push(&tail->next, i);
			tail = tail->next;
		}

		return;
	}
	// use some temporary dummy code to handle the first ListNode
	else if(num_of_method == 2){
		cout << "Build from tail using method 2!" << endl;
		
		ListNode dummy(0);
		ListNode* tail = &dummy;
		dummy.next = nullptr;

		for(int i = 1; i < 5; i ++){
			Push(&tail->next, i);
			tail = tail->next;
		}

		head = dummy.next;
	}
	// use local reference 
	else if(num_of_method == 3){
		cout << "Build from tail using method 3!" << endl;
		
		ListNode** tailRef = &head;
	
		for(int i = 1; i < 5; i ++){
			Push(tailRef, i);
			tailRef = &((*tailRef)->next);
		}		
	}
}

/*
 *--------------------------------------------------------------------------------------
 *       Class:  linkedList
 *      Method:  linkedList :: Push
 * Description:  Push a ListNode in front of the given head pointer
 *--------------------------------------------------------------------------------------
 */
void linkedList::Push(ListNode** _head, int value){
	ListNode* newListNode = new ListNode(0);
	newListNode->val = value;
	newListNode->next = *_head;
	*_head = newListNode;
}


/*
 *--------------------------------------------------------------------------------------
 *       Class:  linkedList
 *      Method:  linkedList :: Length
 * Description:  Calculate the current length of the linked list
 *--------------------------------------------------------------------------------------
 */
int linkedList::Length(){
	int count = 0;
	ListNode* cur = head;
	
	while(cur){
		count ++;
		cur = cur->next;
	}

	return count;
}


/*
 *--------------------------------------------------------------------------------------
 *       Class:  linkedList
 *      Method:  linkedList :: printList
 * Description:  Display the current linked list
 *--------------------------------------------------------------------------------------
 */
void linkedList::printList(){
	ListNode* cur = head;
	
	cout << "Current length " << Length() << " : ";

	while(cur){
		cout << cur->val;
		if(cur->next)
			cout << " -> ";
		cur = cur->next;
	}

	cout << endl;
}
