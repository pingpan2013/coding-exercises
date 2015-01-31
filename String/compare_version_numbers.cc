/*
 * =====================================================================================
 *
 *       Filename:  compare_version_numbers.cc
 *
 *    Description:  compare version numbers
 *
 *        Created:  01/30/2015 22:10:18
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        if(version1.empty())    return version2.empty();
        if(version2.empty())    return version1.empty();
        
        int pre1 = 0;
        int pre2 = 0;
        int pos1, pos11 = 0, pos2, pos22 = 0;
        string part1;
        string part2;
        
        while(pos11 != string::npos && pos22 != string::npos){
            // part of version1
            pos1 = version1.find_first_not_of(".", pre1);
            pos11 = version1.find_first_of(".", pos1);
            pre1 = pos11;
            part1 = (pos11 == string::npos) ? version1.substr(pos1) : version1.substr(pos1, pos11 - pos1);
            
            // part of version2
            pos2 = version2.find_first_not_of(".", pre2);
            pos22 = version2.find_first_of(".", pos2);
            pre2 = pos22;
            part2 = (pos22 == string::npos) ? version2.substr(pos2) : version2.substr(pos2, pos22 - pos2);
            
            if(atoi(part1.c_str()) < atoi(part2.c_str()))   return -1;
            else if(atoi(part1.c_str()) > atoi(part2.c_str()))  return 1;
        }
        

        // must consider the situation that one part is 0
        // e.x.   "1" vs "1.0"
        if(pos11 == pos22)  return 0;
        else if(pos11 == string::npos){
            part2 = version2.substr(pre2+1);
            cout << part2 << endl;
            
            if(atoi(part2.c_str()) == 0)    return 0;
            return -1;    
        }  
        else if(pos22 == string::npos){
            part1 = version1.substr(pre1+1);
            if(atoi(part1.c_str()) == 0)    return 0;
            return 1;
        }  
    }
};


int main(){
    Solution sln;
    cout << sln.compareVersion("1", "1.1") << endl;

    return 0;
}
