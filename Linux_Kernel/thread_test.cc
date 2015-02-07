/*
 * =====================================================================================
 *
 *       Filename:  thread_test.cc
 *
 *    Description:  test thread library
 *
 *        Created:  02/05/2015 00:28:21
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <thread>

using namespace std;

void func(){
    cout << "C++ Multi-thread!!" << endl;
}


int main(){

    thread t(func);
    t.join();

    cout << "End Of Main Program" << endl;

    return 0;
}


