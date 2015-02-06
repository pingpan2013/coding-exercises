/*
 * =====================================================================================
 *
 *       Filename:  intersection_of_two_rectangels.cc
 *
 *    Description:  calculate the intersection area of two rectangels
 *
 *        Created:  02/06/2015 11:17:21
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <cassert>

using namespace std;

class Rectangle{
public:
    int x1, y1;
    int x2, y2;

    Rectangle(int _x1, int _y1, int _x2, int _y2){
        x1 = _x1;
        y1 = _y1;
        x2 = _x2;
        y2 = _y2;
    }
};

class Solution{
public:
    bool ifIntersected(Rectangle &r1, Rectangle &r2){
        return !(r1.x2 < r2.x1 || r1.x1 > r2.x2 || r1.y2 > r2.y1 || r1.y1 < r2.y2);
    }

    int calculateIntersectionArea(Rectangle &r1, Rectangle &r2){
        if(!ifIntersected(r1, r2))  return 0;

        int x_overlap = min(r1.x2, r2.x2) - max(r1.x1, r2.x1);
        cout << "x_overlap: " << x_overlap << endl;

        int y_overlap = min(r1.y1, r2.y1) - max(r1.y2, r2.y2);
        cout << "y_overlap: " << y_overlap << endl;
        
        return x_overlap * y_overlap;
    }
};

int main(){
    Rectangle r1(0, 2, 2, 0);
    Rectangle r2(1, 3, 3, 1);
    
    Solution sln;    
    assert(sln.calculateIntersectionArea(r1, r2) == 1 && "Failed in test1, normal intersection!");
    
    cout << "Passed all test cases!" << endl;
    return 0;
}
