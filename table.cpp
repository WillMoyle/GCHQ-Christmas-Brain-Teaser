// GCHQ 2015 Christmas Brain Teaser - Solution
// Author: Will Moyle
// Last Modified: 10 December 2015

// TABLE FUNCTION DEFINITION FILE

#include "table.hpp"

Table::Table() : rows(ROWS), columns(COLUMNS) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            elements[i][j] = false;
    
    elements[3][3] = true;
    elements[3][4] = true;
    elements[3][12] = true;
    elements[3][13] = true;
    elements[3][21] = true;
    
    elements[8][6] = true;
    elements[8][7] = true;
    elements[8][10] = true;
    elements[8][14] = true;
    elements[8][15] = true;
    elements[8][18] = true;
    
    elements[16][6] = true;
    elements[16][11] = true;
    elements[16][16] = true;
    elements[16][20] = true;
    
    elements[21][3] = true;
    elements[21][4] = true;
    elements[21][9] = true;
    elements[21][10] = true;
    elements[21][15] = true;
    elements[21][20] = true;
    elements[21][21] = true;
    
    int rElements[] = {7, 3, 1, 1, 7, 0, 0, 0, 0,
        1, 1, 2, 2, 1, 1, 0, 0, 0,
        1, 3, 1, 3, 1, 1, 3, 1, 0,
        1, 3, 1, 1, 6, 1, 3, 1, 0,
        1, 3, 1, 5, 2, 1, 3, 1, 0,
        1, 1, 2, 1, 1, 0, 0, 0, 0,
        7, 1, 1, 1, 1, 1, 7, 0, 0,
        3, 3, 0, 0, 0, 0, 0, 0, 0,
        1, 2, 3, 1, 1, 3, 1, 1, 2,
        1, 1, 3, 2, 1, 1, 0, 0, 0,
        4, 1, 4, 2, 1, 2, 0, 0, 0,
        1, 1, 1, 1, 1, 4, 1, 3, 0,
        2, 1, 1, 1, 2, 5, 0, 0, 0,
        3, 2, 2, 6, 3, 1, 0, 0, 0,
        1, 9, 1, 1, 2, 1, 0, 0, 0,
        2, 1, 2, 2, 3, 1, 0, 0, 0,
        3, 1, 1, 1, 1, 5, 1, 0, 0,
        1, 2, 2, 5, 0, 0, 0, 0, 0,
        7, 1, 2, 1, 1, 1, 3, 0, 0,
        1, 1, 2, 1, 2, 2, 1, 0, 0,
        1, 3, 1, 4, 5, 1, 0, 0, 0,
        1, 3, 1, 3, 10, 2, 0, 0, 0,
        1, 3, 1, 1, 6, 6, 0, 0, 0,
        1, 1, 2, 1, 1, 2, 0, 0, 0,
        7, 2, 1, 2, 5, 0, 0, 0, 0};
    
    
    int cElements[] = {7, 2, 1, 1, 7, 0, 0, 0, 0,
        1, 1, 2, 2, 1, 1, 0, 0, 0,
        1, 3, 1, 3, 1, 3, 1, 3, 1,
        1, 3, 1, 1, 5, 1, 3, 1, 0,
        1, 3, 1, 1, 4, 1, 3, 1, 0,
        1, 1, 1, 2, 1, 1, 0, 0, 0,
        7, 1, 1, 1, 1, 1, 7, 0, 0,
        1, 1, 3, 0, 0, 0, 0, 0, 0,
        2, 1, 2, 1, 8, 2, 1, 0, 0,
        2, 2, 1, 2, 1, 1, 1, 2, 0,
        1, 7, 3, 2, 1, 0, 0, 0, 0,
        1, 2, 3, 1, 1, 1, 1, 1, 0,
        4, 1, 1, 2, 6, 0, 0, 0, 0,
        3, 3, 1, 1, 1, 3, 1, 0, 0,
        1, 2, 5, 2, 2, 0, 0, 0, 0,
        2, 2, 1, 1, 1, 1, 1, 2, 1,
        1, 3, 3, 2, 1, 8, 1, 0, 0,
        6, 2, 1, 0, 0, 0, 0, 0, 0,
        7, 1, 4, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 4, 0, 0, 0, 0,
        1, 3, 1, 3, 7, 1, 0, 0, 0,
        1, 3, 1, 1, 1, 2, 1, 1, 4,
        1, 3, 1, 4, 3, 3, 0, 0, 0,
        1, 1, 2, 2, 2, 6, 1, 0, 0,
        7, 1, 3, 2, 1, 1, 0, 0, 0};
    
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < 9; j++)
            rInfo[i][j] = rElements[(i*9) + j];
    
    for (int i = 0; i < columns; i++)
        for (int j = 0; j < 9; j++)
            cInfo[i][j] = cElements[(i*9) + j];
    
}

void Table::print() {
    std::cout << "\nPrinting Board:\n\n-";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            std::cout << "--";
        std::cout << "\n|";
        for (int j = 0; j < columns; j++) {
            if (elements[i][j] == false)
                std::cout << " |";
            else
                std::cout << "X|";
        }
        
        int rowSum = 0;
        
        for (int j = 0; j < 9; j++) {
            if (rInfo[i][j] != 0) {
                std::cout << " " << rInfo[i][j];
                rowSum += rInfo[i][j];
            }
            else
                std::cout << "  ";
        }
        
        
        std::cout << "    " << rowSum << "\n-";
    }
    
    for (int j = 0; j < columns; j++)
        std::cout << "--";
    
    for (int i = 0; i < 9; i++) {
        std::cout << "\n";
        for (int j = 0; j < columns; j++) {
            if (cInfo[j][i] != 0)
                std::cout << " " << cInfo[j][i];
            else
                std::cout << "  ";
        }
    }
    std::cout << "\n ";
    for (int i = 0; i < columns; i++) {
        int colSum = 0;
        for (int j = 0; j < 9; j++)
            colSum += cInfo[i][j];
        std::cout << colSum;
        if (colSum < 10)
            std::cout << " ";
    }
    
    std::cout << std::endl;
}

bool Table::validRow(int r) {
    int position = 0;
    int block = 0;
    
    while (elements[r][position] == false && position < columns)
        position++;
    
    while (rInfo[r][block] != 0) {
        int curBlock = 0;
        while (elements[r][position] == true && position < columns) {
            position++;
            curBlock++;
        }
        if (curBlock != rInfo[r][block])
            return false;
        block++;
        while (elements[r][position] == false && position < columns)
            position++;
    }
    return true;
}

bool Table::validColumn(int c) {
    int position = 0;
    int block = 0;
    
    while (elements[position][c] == false && position < rows)
        position++;
    
    while (cInfo[c][block] != 0) {
        int curBlock = 0;
        while (elements[position][c] == true && position < rows) {
            position++;
            curBlock++;
        }
        if (curBlock != cInfo[c][block])
            return false;
        block++;
        while (elements[position][c] == false && position < rows)
            position++;
    }
    return true;
}

bool Table::valid() {
    for (int i = 0; i < rows; i++)
        if (!validRow(i))
            return false;
    
    for (int j = 0; j < columns; j++)
        if (!validColumn(j))
            return false;
    
    return true;
}



