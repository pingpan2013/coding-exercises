/*
 * =====================================================================================
 *
 *       Filename:  find_prime_factors_of_num.cc
 *
 *    Description:  find all the prime factors of a given number
 *
 *        Created:  02/24/2015 00:08:41
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <vector>
#include <iostream>

using namespace std;

vector<int> factor(int n){
    vector<int> ret;

    for(long long i = 2; i * i <= n; ++i){
        while(n % i == 0){    // factor out all i's, this will cut the runtime
            ret.push_back(i);
            n /= i;           
        }
    }
    
    // Attention here, n is the last factor
    if(n > 1){
        ret.push_back(n);
    }

    return ret;
}

void test(int x){
    auto v = factor(x);
    cout << x << ":\t";
    
    for(auto i : v) cout << i << ";";
    cout << endl;
}

int main(){
    test(10);
    test(4);
    test(13);
    test(1028);

    return 0;
}
