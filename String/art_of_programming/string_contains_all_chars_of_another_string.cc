/*
 * =====================================================================================
 *
 *       Filename:  string_contains_all_chars_of_another_string.cc
 *
 *    Description:  check if string A contains all chars of string B, assume B is
 *                  shorter than A
 *
 *        Created:  02/02/2015 23:42:10
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class solution{
    // method 1: sort + comparing
    //           time complexity O(nlgn), space O(1)
    //           drawback: need change the string, O(n) space needed for backup
    void stringContains(string &str_a, stirng &str_b){
        assert(str_a.size() >= str_b.size());
        
        sort(str_a.begin(), str_a.end());
        sort(str_b.begin(), str_b.end());

        while(int pa = 0, int pb = 0; pa < str_b.size(); pb++){
            while(pa < str_a.size() && str_a[pa] < str_b[pb]){
                pa ++;  // consider duplicate chars, don't move pa until pb steps to next char
            }
            
            if(pa >= str_a.size() || str_a[pa] > str_b[pb]){
                return false;
            }
            
            // str_a[pa] == str_b[pb]
        }
    }

    // method 2: hash_map
    //           time complexity O(n), space O(n)
}
