/*
 * =====================================================================================
 *
 *       Filename:  excel.h
 *
 *    Description:  the skeleton of the design of Excel
 *
 *        Created:  03/08/2015 14:11:49
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

// base class for each cell
class Cell{
public:
    Cell(int _row, int _col) : rowIdx(_row), colIdx(_col) {}
    
    int getRowIdx();
    int getColIdx();
    
    virtual void setData();

private:
    int rowIdx;
    int colIdx;
};

// Cell that stores functions
class FuncCell : class Cell{
public:
    Cell(){}

private:
    void (*func)(void*);     // function pointer
    vector<Cell> references; // handle references
};

// Cell that stores basic datatypes like string, int, float
template <typename T>
class NormCell : class Cell{
public:
    NormCell(T _data, int rowIdx, int colIdx) : Cell(rowIdx, colIdx), data(_data){}
    
    T getData();
    void setData(T _data);
    
private:
    T data;
};


class Excel{
public:
        
private:
    // method 1:
    // hashmap<rowIdx, hashmap<colIdx, Cell> >
    //
    // Drawbacks: it takes O(n) to delete one column
    // Improvement: sacrifice space for speed
    unordered_map<int, list<Cell> > rowData;   // map rowIdx to its data, use list instead of vector to avoid sparse matrix
    unordered_map<int, list<Cell> > colData;   // the same as rowData
};

// process:
// 1. Basic data structure: use double hashmaps to store the data of each row and each colume respectively
// 2. Big picture: use MVC model, the Models are the two maps we just designed, the Controller is responsible for coordinating
//    the front-end part and back-end part, we need to implement some functions to perform related operations, e.g. insertion,
//    deletion, modification etc. The view is basically the GUI of the Excel.
// 3. Details:
//    (1) Q: The datatype of each cell: could be string, integer, float, date ... more importantly, it could be a function, how 
//        to handle this case?
//        A: Design two classes extend the basic Cell class, one for storing the basic datatypes and the other one for storing
//        functions.
//    (2) Q: How to handle reference, e.g. B1 = C1, B1 should change if C1 changes ?
//        A: For each cell, maintain a vector to store all the other cells it refers to 
