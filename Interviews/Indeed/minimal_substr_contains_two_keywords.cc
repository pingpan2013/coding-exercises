/*
 * =====================================================================================
 *
 *    Description:  find the minimal substr that contains the two words in a given string
 *
 *        Created:  02/24/2015 16:14:15
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

string minDistance(string &text, string &word1, string &word2){
    if(text.empty())    return " ";

    int index1 = -1;
    int index2 = -1;
    
    int start = -1;
    int min_distance = INT_MAX;
    
    // two pointers 
    int pos1 = 0;
    int pos2 = 0;
    while(true){
        pos1 = text.find_first_not_of(" ", pos2);
        if(pos1 == string::npos){
            break;
        }

        pos2 = text.find_first_of(" ", pos1);
        if(pos2 == string::npos){
            pos2 = text.size();
        }

        string word = text.substr(pos1, pos2-pos1);

        if(word == word1){
            index1 = pos1;  // index
            if(index2 == -1)    continue;

            if(index1 + word.size() -index2 < min_distance){
                min_distance = index1 + word.size() - index2;
                start = index2;
            }
        }
        else if(word == word2){
            index2 = pos1;
            if(index1 == -1)    continue;

            if(index2 + word.size() - index1 < min_distance){
                min_distance = index2 + word.size() - index1;
                start = index1;
            }
        }
    }

    if(index1 != -1 && index2 != -1)    return  text.substr(start, min_distance);
    
    return " ";
}

void test(string &text, string &word1, string &word2){
    cout << minDistance(text, word1, word2) << endl;    
}


int main(){
    // general test
    string text("python is good, but java is better, python + java python"); 
    string word1("python");
    string word2("java");
    test(text, word1, word2);

    // empty word test 1
    text = "pythoni is good";
    test(text, word1, word2);

    // empty word test 2
    text = "none of them";
    test(text, word1, word2);

    return 0;
}

