/*
 * =====================================================================================
 *
 *       Filename:  strstr.cc
 *
 *    Description:  implement strstr()
 *
 *        Created:  02/19/2015 02:16:09
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

// brute-forced way
int strstr(char *s, char *t){
    if(*t == '\0')  return 0;
    if(*s == '\0')  return -1;

    int len1 = strlen(s);
    int len2 = strlen(t);

    int i = 0;
    int j = 0;
    while(s[i+j] != '\0' && t[j] != '\0' && i <= len1-len2){
        if(s[i+j] == t[j]){
            j++;
        }
        else{
            i++;
            j = 0;
        }
    }

    if(j == len2)   return i;

    return -1;
}

// method 2: kmp
// method 3: suffix tree
