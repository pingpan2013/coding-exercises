/*
 * =====================================================================================
 *
 *       Filename:  gray_check.cc
 *
 *    Description:  check if two bytes could be placed successively in a sequence of 
 *                  gray codes
 *                  
 *                  (That is these two bytes only differ in 1 bit)
 *
 *        Created:  03/01/2015 15:41:45
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <cassert>

using namespace std;

int grayCheck(unsigned char term1, unsigned char term2){
    int term = term1 ^ term2;
    int num = 0;

    while(term > 0){
        num++;
        term = term & (term - 1);
    }

    return (num == 1) ? 1 : 0;
}

void test(unsigned char term1, unsigned char term2){
    if(grayCheck(term1, term2) == 1){
        cout << "Could be placed!" << endl;
    }
    else{
        cout << "Couldn't be placed!" << endl;
    }
}

int main(){
    unsigned char term1 = 0b0111111;
    unsigned char term2 = 0b0111110;

    test(term1, term2);  // could

    term1 &= 0;
    test(term1, term2);  // couldn't
    
    term1 = 0b00000001;
    term2 = 0b00000010;
    test(term1, term2);  // couldn't
    
    term1 &= 0;
    test(term1, term2);  // could

    return 0;
}

