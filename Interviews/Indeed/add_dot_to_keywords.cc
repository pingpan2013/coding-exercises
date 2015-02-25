/*
 * =====================================================================================
 *
 *       Filename:  add_dot_to_keywords.cc
 *
 *    Description:  add dots both before and after the keyword in a string
 *
 *        Created:  02/24/2015 23:53:26
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

void addDotsToKeywords(string &str, string &keyword){
    if(str.empty()) return;

    int pos1 = 0;
    int pos2 = 0;

    while(true){
        pos1 = str.find_first_not_of(" ", pos2);
        if(pos1 == string::npos)    break;

        pos2 = str.find_first_of(" ", pos1);
        if(pos2 == string::npos){
            pos2 = str.size();
        }

        string word = str.substr(pos1, pos2-pos1);

        if(word == keyword){
            str.insert(pos1, ".");
            str.insert(pos2 + 1, ".");

            pos2 += 2;
        }
    }

    return;
}


int main(){
    string text("python is good, but c++ is better than python and java! python");
    string keyword("python");
    addDotsToKeywords(text, keyword);

    cout << text << endl;

    return 0;
}

