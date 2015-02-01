/*
 * =====================================================================================
 *
 *       Filename:  fork_test.cc
 *
 *    Description:  test fork function
 *
 *        Created:  01/31/2015 23:14:40
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */


#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h>    // fox exit()
#include <iostream>

using namespace std;

int gVariable = 100;

int main(){
    string sIdentifier;
    int sVariable = 1;

    pid_t pID = fork(); 
    if(pID == 0){
        sIdentifier = "Child Process: ";
        gVariable ++;
        sVariable ++;
    }
    else if(pID > 0){
        sIdentifier = "Parent Process: ";
    }

    cout << sIdentifier;
    cout << " Global Variable: " << gVariable;
    cout << " Stack  Variable: " << sVariable << endl;

    return 0;
}
