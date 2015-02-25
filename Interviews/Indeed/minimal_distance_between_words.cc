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
#include <vector>

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


// Possible follow-up
// if we need to call this function frequently and the data set is large
// we'd better construct indexes for each word and then check the indexes to 
// calculate the minimal distance between all of two words' indexes
// 
// Use hashtable to build indexes:
// unordered_map<string, vector<int> >
//
// e.g. word1 -> [1, 4, 5, 8, 9]
//      word2 -> [2, 7, 6, 8, 10]
// Then all we need do is to find the pair of elements, each from one array,
// s.t. the difference between them are smallest
int findMinDiff(vector<int> &index1, vector<int> &index2){
    if(index1.empty() || index2.empty())    return INT_MAX;
    
    int m = index1.size(), n = index2.size();
   
    // corner case optimization
    if(index1[m-1] < index2[0]){
        return abs(index1[m-1] - index2[0]);
    }

    if(index1[0] > index2[n-1]){
        return abs(index1[0] - index2[n-1]);
    }
    
    int i = 0, j = 0;
    int min_diff = INT_MAX;
    while(i < m && j < n){
        min_diff = min(min_diff, abs(index1[i] - index2[j]));
        
        if(index1[i] < index2[j]){
            i++;
        }
        else if(index1[i] > index2[j]){
            j++;
        }
        else{
            // should throw exception because two different words cannot 
            // have the same index
        }
    }

    return min_diff;
}


int main(){
    string text("python is good, but java is better, python java"); 

    string word1("python");
    string word2("java");
    cout << minDistance(text, word1, word2) << endl;    

    // find min diff between two sorted arrays
    vector<int> index1({2, 15, 26, 48, 100});
    vector<int> index2({23, 46, 56, 78, 99});
    cout << findMinDiff(index1, index2) << endl;

    return 0;
}

