/*
 * =====================================================================================
 *
 *       Filename:  first_non_repeating_char.cc
 *
 *    Description:  find the first non repeating char
 *
 *        Created:  02/22/2015 17:22:35
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */


#include <iostream>
#include <unordered_map>
#include <list>
#include <cassert>

using namespace std;

// Naive Method: use a counter array: first count the num of times of each char appears in the array
//               then traverse the original string to find the first char with counter == 1 in the counter array
//               Time complexity: 0(n+n)

// Method 1: linked hashmap in Java: the hashmap could be iterated in the order the elements are inserted
//           C++ doesn't support linked hashmap currently, the boost library could acheive this
//           
// Method 2: hashmap + dll, time complexity O(n), space: O(s), s is the number of the single elements in the string
//
//           Advantage: Only need traverse the original string once, and 
//           could know the first non repeated char at any time along with the original string, it's the front of the DLL
char find_first_non_repeated_char(const string &str){
    if(str.empty()) return '\0';

    unordered_map<char, list<char>::iterator> charMap;  // map chat to its position in the DLL
    list<char> charList;

    for(int i = 0; i < str.size(); i++){
        char c = str[i];

        if(charMap.find(c) == charMap.end()){
            charList.push_back(c);
            charMap[c] = --charList.end();
        }
        else{
            list<char>::iterator it = charMap[c];
            charList.erase(it);
        }
    }
    
    if(!charList.empty())
        return charList.front();
    else
        return '\0';
}

int main(){
    string str("abcab");
    assert(find_first_non_repeated_char(str) == 'c');
    
    str.push_back('c');
    assert(find_first_non_repeated_char(str) == '\0');

    str.push_back('d');
    assert(find_first_non_repeated_char(str) == 'd');
    
    cout << "Passed all the test cases!" << endl;

    return 0;
}
