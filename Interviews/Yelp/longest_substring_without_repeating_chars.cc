/*
 * =====================================================================================
 *
 *       Filename:  longest_substring_without_repeating_chars.cc
 *
 *    Description:  longest substring without repeating characters
 *
 *        Created:  03/03/2015 22:26:27
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

string longestSubstr(string &str){
    if(str.empty()) return "";

    int start = 0;
    int max_len = 1;
    int n = str.size();
    unordered_map<char, int> charToIndex;  //  map character to its last index

    for(int i = 0; i < n; i++){
        char c = str[i];
        if(charToIndex.find(c) == charToIndex.end()){
            charToIndex[c] = i;
            continue;
        }

        // the char already appeared
        int lastIndex = charToIndex[c];
        
        for(int j = start; j < i; j++){
            charToIndex.erase(str[j]);
        }
        
        if(i - lastIndex > max_len){
            max_Len = i - lastIndex;  // update the maximum length
            start = lastIndex + 1;    // update the starting index
        }

        charToIndex[c] = i;
    }
    
    return str.substr(start, max_len);
}
