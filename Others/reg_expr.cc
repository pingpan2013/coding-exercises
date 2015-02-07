/*
 * =====================================================================================
 *
 *       Filename:  reg_expr.cc
 *
 *    Description:  regular expression exercises
 *
 *        Created:  12/08/2014 18:00:10
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <regex>

using namespace std;

int main(){
	// example
	std::string str = " Mem(100)=120";
	std::regex regex("^[\\s]*Mem\\(([0-9]+)\\)\\s*=\\s*([0-9]+(\\.[0-9]+)?)\\s*$");
	std::smatch m;

	std::cout << std::regex_match(str, m, regex) << std::endl;

        for(auto res : m){
            cout << res << endl;
        }
    
        return 0;
}



