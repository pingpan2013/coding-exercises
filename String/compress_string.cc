/*
 * =====================================================================================
 *
 *       Filename:  compress_string.cc
 *
 *    Description:  compress string:
 *                  aabbbcccd => a2b3c3d1
 *
 *        Created:  02/09/2015 23:24:08
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    void compressString(string &s){
        if(s.empty())   return;

        int i = 0;
        int k = 1;
        while(i < s.length()){
            s[k-1] = s[i];

            int cnt = 1;
            while(i < s.size() - 1 && s[i] == s[i+1]){
                i++;
                cnt++;
            }
            
            // if there is only 1 of the char
            if(cnt == 1){
                s.insert(s.begin() + k, cnt + '0'); // if appreared only once, we insert instead of replacing 
                k = k + 2;
                i = i + 2;
            }
            // more than 1 chars
            else{
                s[k] = (cnt + '0');   // for simplicity, we assume that each char appears less than 10 times
                k = k + 2;            // it's easy to adjust here if appreared more than 10 times
                i++;
            }
        }
    
        s.resize(k-1);   // k-2+1
    }
};

int main(){
    Solution sln;
    
    string s("abbbccdeeeefffk");
    sln.compressString(s);
    cout << s << endl;
    
    string s1("aaaaaaa");
    sln.compressString(s1);
    cout << s1 << endl;

    return 0;
}

