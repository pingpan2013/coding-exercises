/*
 * =====================================================================================
 *
 *       Filename:  case_permutation.cc
 *
 *    Description:  given a string write all the possible upper case and lower case 
                    strings of it. eg. given a string THE print tHE,ThE,THe,thE,The,tHe,
                    the..... 
 *
 *        Created:  02/17/2015 12:26:04
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;


void generateRec(char *s, int pos, int len)
{
        if(pos >= len)
        {
                cout << s << endl;
                return;
        }

        s[pos] = tolower(s[pos]);
        generateRec(s, pos+1, len);
        s[pos] = toupper(s[pos]);
        generateRec(s, pos+1, len);
}


int main(void)
{
        char str[] = "THE";
        generateRec(str, 0, strlen(str));
        return 0;
}
