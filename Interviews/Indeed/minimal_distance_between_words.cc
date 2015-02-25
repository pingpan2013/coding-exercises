/*
 * =====================================================================================
 *
 *       Filename:  minimal_distance_between_words.cc
 *
 *    Description:  find the minimal distance between words in a given string
 *
 *        Created:  02/24/2015 16:14:15
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <cmath>

using namespace std;

int minDistance(string &text, string &word1, string &word2){
    if(text.empty())    return -1;

    int index1 = -1;
    int index2 = -1;

    int cnt = 0;
    int min_distance = INT_MAX;

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
            index1 = cnt;
            
            if(index2 != -1){
                min_distance = min(min_distance, cnt - index2);
            }
        }
        else if(word == word2){
            index2 = cnt;
            
            if(index1 != -1){
                min_distance = min(min_distance, cnt - index1);
            }
        }
        
        cnt++;
    }

    if(index1 != -1 && index2 != -1)    return  min_distance;
    
    return -1;
}


int main(){
    string text("python is good, but java is better, python java"); 

    string word1("python");
    string word2("java");
    cout << minDistance(text, word1, word2) << endl;    

    return 0;
}

