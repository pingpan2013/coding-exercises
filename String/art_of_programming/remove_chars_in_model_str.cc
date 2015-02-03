/*
 * =====================================================================================
 *
 *       Filename:  remove_chars_in_model_str.cc
 *
 *    Description:  remove chars in model string from a target string
 *
 *        Created:  02/02/2015 23:01:45
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */


#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution{
public:
    // method 1: O(n) time 0(1) space
    // use hash to scale up
    void removeModelStr(char *target, char *model){
        if(*model == '\0')  return;

        vector<bool> flag(26, false);

        for(int i = 0; i < strlen(model); i++){
            flag[model[i] - 'a'] = true;
        }
    
        int index = 0;
        for(int i = 0; i < strlen(target); i++){
            if(target[i] == ' ' || flag[target[i] - 'a'] == false){
                target[index++] = target[i];
            }
        }
        target[index] = '\0';
    }
};


int main(){
    char target[] = "welcome to umich";
    char model[] = "wtu";
    
    Solution sln;
    sln.removeModelStr(target, model);
    cout << target << endl;
    
    return 0;
}

