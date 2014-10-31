/*
 * =====================================================================================
 *
 *       Filename:  test.cc
 *
 *    Description:  
 *
 *        Created:  10/30/2014 22:52:56
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;

void fun1(int &g){
    g++;
}

int func2(int &g){
    fun1(g);
    g++;
}

int main(){
    int g = 100;
    func2(g);

    cout << g << endl;

    return 0;

}
