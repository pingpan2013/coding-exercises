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
 * Description:  Build a linked list by pushing node from the head each time
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
 * Description:  Build a linked list by pushing node from the tail each time
 *               Using three methods, randomly choose one of them
 *               The difference lies in how to handle the very first node
 *--------------------------------------------------------------------------------------
 */
void linkedList::Build_from_tail(){
	srand(time(nullptr));
	int num_of_method = rand() % 3 + 1;	

	// use special case to handle the first node
	if(num_of_method == 1){
		cout << "Build from tail using method 1!" << endl;
		
		Push(&head, 1);
		node* tail = head;

		for(int i = 2; i < 5; i ++){
			Push(&tail->next, i);
			tail = tail->next;
		}

		return;
	}
	// use some temporary dummy code to handle the first node
	else if(num_of_method == 2){
		cout << "Build from tail using method 2!" << endl;
		
		node dummy;
		node* tail = &dummy;
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
		
		node** tailRef = &head;
	
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
 * Description:  Push a node in front of the given head pointer
 *--------------------------------------------------------------------------------------
 */
void linkedList::Push(node** _head, int value){
	node* newNode = new node;
	newNode->data = value;
	newNode->next = *_head;
	*_head = newNode;
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
	node* cur = head;
	
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
	node* cur = head;
	
	cout << "Current length " << Length() << " : ";

	while(cur){
		cout << cur->data;
		if(cur->next)
			cout << " -> ";
		cur = cur->next;
	}

	cout << endl;
}
