/*
 * =====================================================================================
 *
 *       Filename:  swap_nibbles_in_byte.cc
 *
 *    Description:  swap two nibbles in a byte
 *                  reference: http://www.geeksforgeeks.org/swap-two-nibbles-byte/
 *              
 *                  e.g.
 *                  x = 10010001
 *                  x1 = (11110000 & x) >> 4 = 00001001
 *                  x2 = (00001111 & x) << 4 = 00010000
 *                  x3 = x1 | x2 = 00011001
 *
 *        Created:  02/07/2015 17:55:58
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <cassert>
#include <iostream>
#include <cstdlib>

using namespace std;

unsigned char swapNibbles(unsigned char x){
    
    return (x & 0x0F) << 4 | (x & 0xF0) >> 4;
}

void printBits(unsigned char x){
    for(int i = 0; i < sizeof(x) * 8; i++){
        cout << (x & 0x01);
        x >>= 1;
    }
    cout << endl;
}

int main(){
    
    unsigned char x = 198;
    printBits(x);
    printBits(swapNibbles(x));

    return 0;
}
