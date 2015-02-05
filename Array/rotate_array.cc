/*
 * =====================================================================================
 *
 *       Filename:  rotate_array.cc
 *
 *    Description:  rotate array
 *
 *        Created:  02/04/2015 23:01:56
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#define vector<int>::iterator vec_itr;

class Solution{
public:
    void rotateVec(vec_itr first, vec_itr mid, vec_itr last){
        vec_itr next = mid;
        
        // each time rotate min(mid->last, first->mid-1) 
        // repeat the process
        while(first != next){
            swap(*first++, *next++);

            if(next == last)   next = mid;    // consider the e.g. 12345 67
            else if(first == mid)    mid = next;   // consider the e.g. 123 45678
        }
    }
};


