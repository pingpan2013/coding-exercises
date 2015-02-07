/*
 * =====================================================================================
 *
 *       Filename:  count_trailing_zeros.cc
 *
 *    Description:  calculate the number of trailing zeros in n factorial
 *
 *        Created:  11/22/2014 23:25:11
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */


// it depends on how many pairs (2, 5) there ara. Since the total number of digit 
// 2 is obviously much more than the number of digit 5, we just need calculate 
// how many digit 5 there exists. 

int numOfTrailingZeros(int n){
    if(n < 4)   return 0;

    int num = 0;
    while(n > 0){
        num += n/5;
        n /= 5;
    }

    return num;
}

