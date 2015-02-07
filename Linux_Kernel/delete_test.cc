/*
 * =====================================================================================
 *
 *       Filename:  delete_test.cc
 *
 *    Description:  test delete function
 *
 *        Created:  02/01/2015 14:35:47
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

int main(){

    int* a = new int(5);
    delete a;
        
    a = nullptr;
    delete a;   // it's ok if a is pointed to nullptr
                // otherewise delete a twice will result in undefined error
    return 0;
}



