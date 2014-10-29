/*
 * =====================================================================================
 *
 *       Filename:  print_last_k_lines.cc
 *
 *    Description:  print the last k lines of a given file
 *
 *        Created:  10/28/2014 21:58:54
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */


#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

class Solution{
    public:
        void printLastKLines(ifstream &fin, int k){
            if(!fin || k <= 0)    return;
            
            int line_no = 0;
            string *str = new string[k]; 

            while(getline(fin, str[line_no % k])){
                line_no ++;
            }
            
            int start = -1;
            int cnt = -1;
            if(line_no <= k){
                start = 0;
                cnt = line_no;
            }
            else{
                start = line_no % k;
                cnt = k;
            }
           
            assert(cnt <= k && cnt >= 0 && "wrong length!");
            assert(start <= k && start >= 0 && "wrong starting index!");

            for(int i = 0; i < cnt; i ++){
                cout << str[(start + i) % k] << endl;
            }

            delete []str;
        }
};

int main(){
    Solution sol;
    ifstream myfile("test.in");

    if(myfile){
        cout << "Last 20 lines:" << endl;
        sol.printLastKLines(myfile, 20);
    }
    myfile.close();

    ifstream myfile1("test.in");
    if(myfile){
        cout << "Last 5 lines:" << endl;
        sol.printLastKLines(myfile1, 5);
    }
    else
        cout << "Error in opening file!" << endl;
    myfile1.close();
    
    return 0;
}



