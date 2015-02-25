/*
 * =====================================================================================
 *
 *       Filename:  check_syntax_of_python.cc
 *
 *    Description:  check the syntax of python(check the indents to see if it's reasonable)
 *
 *        Created:  02/24/2015 20:48:47
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <fstream>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<string> data;

void readData(){
    ifstream file("text.py");
    
    string line;
    while(getline(file, line)){
        data.push_back(line);
    }
}

bool checkIndents(){
    stack<int> st;

    for(int i = 0; i < data.size(); i++){
        int numOfSpace = data[i].find_first_not_of(" ");
        
        // Watchout 1:
        // Skip Empty line
        if(numOfSpace == string::npos)  continue;
        cout << numOfSpace << endl;        
        
        if(st.empty()){
            st.push(numOfSpace);
        }  
        else{
            int lastNumOfSpace = st.top();
            
            // if current indent is equal or larger than the last indent, go on
            if(numOfSpace >= lastNumOfSpace){
                st.push(numOfSpace);
                continue;
            }
            
            // otherwise check the previous indents until we find a match
            // 
            // Watchout 2:
            // when pop out or st.top(), must gurantee that it is not empty
            while(!st.empty()){
                if(numOfSpace == st.top()){
                    break;
                }
                st.pop();
            }
            
            // if there is no match, return false
            if(st.empty())  return false;
        }
    }

    return true;
}

int main(){
    readData();
    
    if(checkIndents()){
        cout << "The indents are appropriate!" << endl;
    }
    else{
        cout << "The indents are inappropriate!" << endl;
    }

    return 0;
}
