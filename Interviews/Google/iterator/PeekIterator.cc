/*
 * =====================================================================================
 *
 *       Filename:  PeekIterator.cc
 *
 *    Description:  PeekIterator
 *                  Reference: http://www.fgdsb.com/2015/01/25/peek-iterator/
 *
 *        Created:  02/23/2015 23:03:48
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

// A simplified iterator class
class Iterator{
public:
    Iterator(vector<int> &_data) : data(_data){
        tail = 0;
    }
    
    bool has_next(){
        return tail < data.size();
    }

    int get_next(){
        return data[tail++];
    }

private:
    vector<int> data;
    size_t tail;
};

// access the next element without moving the iterator
class PeekIterator{
public:
    PeekIterator(Iterator &it) : itr(it){  }

    int peek(){
        if(peeks.empty()){
            int ret = itr.get_next();
            peeks.push_back(itr);
            return ret;
        }
        else{
            return peeks.back();
        }
    }
    
    bool has_next(){
        return itr.has_next() || !peek.empty(); 
    }
    
    // when calling get_next(), return the previous peek, and pop out
    int get_next(){
        if(!peeks.empty()) {
            int ret =  peeks.back();
            peeks.pop();
            return ret;
        } 
        else{
            return itr.get_next();
        }
    }

private:
    Iterator itr;      // inner iterator
    vector<int> peeks; // store the nodes of the peek
};
