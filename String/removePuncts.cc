/*
 * =====================================================================================
 *
 *       Filename:  removePuncts.cc
 *
 *    Description:  remove punctuations in a string
 *
 *        Created:  11/04/2014 00:14:39
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <string>
#include <iostream>
#include <cctype>

using namespace std;

void removePuncts(string &text){
    for (int i = 0, len = text.size(); i < len; i++)
    {
        if (ispunct(text[i]))
        {
            text.erase(i--, 1);
            len = text.size();
        }
    }
}

void removePuncts_2(string &text){
    for(auto c: text)
        if(ispunct(c))  text.erase(text.find_first_of(c)); 
}

int main() {
    string text = "this. is my string. it's here.";
    removePuncts(text);
    cout << text << endl;

    string text2 = "this. is my string. it's here.";
    removePuncts_2(text2);
    cout << text2 << endl;

    return 0;
}

