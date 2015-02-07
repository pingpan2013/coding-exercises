/*
 * =====================================================================================
 *
 *       Filename:  swap.cc
 *
 *    Description:  swap two nums in palce without temporary variables
 *
 *        Created:  11/22/2014 23:19:55
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

void swap(int &a, int &b){
    b = a - b;
    a = a - b;
    b = a + b;
}

void swap(int &a, int &b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

// Bugs: if the two parameters refer to the same variable
//       the two algorithms will not work
