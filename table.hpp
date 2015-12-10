// GCHQ 2015 Christmas Brain Teaser - Solution
// Author: Will Moyle
// Last Modified: 10 December 2015

// TABLE CLASS HEADER FILE

#ifndef table_hpp
#define table_hpp

#include <vector>
#include <iostream>

const int ROWS = 25;
const int COLUMNS = 25;
const int INFO_LEN = 9;

class Table{
private:
    int rows;
    int columns;
    bool elements[ROWS][COLUMNS];
    int rInfo[ROWS][INFO_LEN];
    int cInfo[COLUMNS][INFO_LEN];
    

public:
    Table();
    
    void print();
    
    bool validRow(int r);
    
    bool validColumn(int c);
    
    bool valid();
};




#endif