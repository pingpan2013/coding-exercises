/*
 * =====================================================================================
 *
 *       Filename:  flatten_iterator.cc
 *
 *    Description:  flatten iterator
 *
 *        Created:  02/25/2015 01:14:09
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class FlattenIterator{
public:
    FlattenIterator(vector<vector<int> > &vec){
        itr1 = vec.begin();
        itr1_end = vec.end();
        
        get_itr2();
    }

    bool hasNext(){
        return (itr2 != itr2_end || itr1 != itr1_end);
    }
    
    int next(){
        if(itr2 == itr2_end){
            if(itr1 != itr1_end){
                get_itr2();
            }
        }

        int ret = *itr2;
        itr2++;
        
        // Attention:
        // handle empty vectors
        //
        // when itr2 reaches the end of current vector and the next nect is empty 
        if(itr2 == itr2_end){
            if(itr1 != itr1_end){
                get_itr2();
            }
        }
        return ret;
    }

private:
    void get_itr2(){
        itr2 = itr1->begin();
        itr2_end = itr1->end();
        itr1++;
    }
    
    // iterate through the outer vectors
    vector<vector<int> >::iterator itr1;  // points to the next vector
    vector<vector<int> >::iterator itr1_end;

    // iterate through the inner vectors
    vector<int>::iterator itr2;      // points to the next value
    vector<int>::iterator itr2_end;
};

int main(){
    vector<vector<int> > vec({{1, 2}, {}, {3, 4}});
    
    //vector<vector<int> >::iterator itr = vec.begin();
    //if(itr != vec.end()){}    
    
    FlattenIterator itr(vec);

    while(itr.hasNext()){
       cout << itr.next() << " ";
    }
    cout << endl;

    return 0;
}
