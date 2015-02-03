/*
 * =====================================================================================
 *
 *       Filename:  first_unrepeated_char_in_a_string.cc 
 *
 *        Created:  02/02/2015 23:42:10
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class solution{
public:
    // method 1: use a counter array, constant space, O(n) time
    char firstUnrepeatedChar(string &str){
        if(str.empty()) return ' ';

        vector<int> flag(256, 0);

        for(int i = 0; i < str.size(); i++){
            flag[str[i]] ++;
        }

        for(int i = 0; i < str.size(); i++){
            if(flag[str[i]] == 1)   return str[i];
        }

        return ' ';
    }    

    // method 2: hash_map
    //           time complexity O(n), space O(n)
}
