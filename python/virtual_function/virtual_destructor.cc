/*
 * =====================================================================================
 *
 *       Filename:  virtual_destructor.cc
 *
 *    Description:  test the virtual destrcutor
 *
 *        Created:  10/28/2014 14:24:21
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

class base{
    public:
        base() {
            cout << "Base constructor called!" << endl;
        }

        virtual ~base(){
            cout << "Base destuctor called" << endl;
        }
};


class derived: public base{
    public:
        devired(){
            cout << "Devired constructor called!" << endl;
        }
        
        virtual ~base(){
            cout << "Base destuctor called" << endl;
        }
};

int main(){
    base *b = new derived();
    delete b;

    return 0;
}
