/*
 * =====================================================================================
 *
 *       Filename:  linked_array_list.cc
 *
 *    Description:  constuct a data structure: LinkedList<ArrayList<Integer>>
 *
 *        Created:  02/25/2015 12:11:58
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class LinkedArrayListNode{
public:
    vector<int> arr;
    size_t arr_size;
    LinkedArrayListNode *next;
    
    // constructor
    LinkedArrayListNode(vector<int> &_arr, size_t _size) : arr(_arr), arr_size(_size){  
        arr.resize(arr_size);
    }
};


class LinkedArrayList{
public:
    LinkedArrayList(){
    }

    // insert an elment into the LinkedArrayList
    void insert(int val){
        // current ListNode is full
        if(head->arr.size() == head->arr.arr_size){
            if(head->next->arr.size() == head->arr.arr_size()){
                // if next ListNode is also full, create a new ListNode between the two ListNodes
                // and insert the val into the new created ListNode
                              
            }
            else{
                // if the next ListNode is not full, just insert the element into the next ListNode
                int curSize = head->next->arr.size();
                head->next->arr[curSize] = val;
            }
        } 
        else{
            head->arr[arr.size()] = val;
        }
    }

    void delete(){

    }

private:
    LinkedListNode *head;
};
