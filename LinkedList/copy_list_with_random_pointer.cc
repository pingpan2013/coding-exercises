/*
 * =====================================================================================
 *
 *       Filename:  copy_list_with_random_pointer.cc
 *
 *    Description:  copy list with random pointer
 *
 *        Created:  02/21/2015 12:17:19
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)   return nullptr;
        
        // map old node to new node
        unordered_map<RandomListNode*, RandomListNode*> map; 
        RandomListNode dummy(-1);
        RandomListNode *p = &dummy;
        
        RandomListNode *q = head;
        while(q){
            RandomListNode *newNode = new RandomListNode(q->label);
            map[q] = newNode;
            
            p->next = newNode;
            p = p->next;
            q = q->next;
        }
        
        q = head;
        p = dummy.next;
        while(q && q){
            p->random = map[q->random];
            
            p = p->next;
            q = q->next;
        }
        
        return dummy.next;
    }
};
