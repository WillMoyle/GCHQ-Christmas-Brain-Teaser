// GCHQ 2015 Christmas Brain Teaser - Solution
// Author: Will Moyle
// Last Modified: 10 December 2015

// TABLE FUNCTION DEFINITION FILE

#include "table.hpp"

Table::Table() : rows(ROWS), columns(COLUMNS) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            elements[i][j] = false;
    
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
    
    for (int i = 0; i < rows; i++) {
        blockMoving[i] = 0;
        for (int j = 0; j < 9; j++) {
            rInfo[i][j] = rElements[(i*9) + j];
            if (rInfo[i][j] != 0)
                blockMoving[i]++;
        }
    }
    
    for (int i = 0; i < columns; i++)
        for (int j = 0; j < 9; j++)
            cInfo[i][j] = cElements[(i*9) + j];
    
    
}

void Table::printRow(int r) {
    std::cout << "\n|";
    for (int i = 0; i < 25; i++) {
        if (elements[r][i])
            std::cout << "X|";
        else
            std::cout << " |";
    }
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

bool Table::firstValidRow(int r) {
    blockMoving[r] = 0;
    for (int j = 0; j < 9; j++) {
        if (rInfo[r][j] != 0)
            blockMoving[r]++;
    }
    bool changesMade = false;
    int numBlocks = 0;
    while (rInfo[r][numBlocks] != 0)
        numBlocks++;
    
    int position = 0;
    
    for (int i = 0; i < numBlocks && position < 25; i++) {
        for (int j = 0; j < rInfo[r][i] && position < 25; j++) {
            if (!elements[r][position])
                changesMade = true;
            elements[r][position] = true;
            position++;
        }
        if (elements[r][position])
            changesMade = true;
        elements[r][position] = false;
        position++;
    }
    while (position < 25) {
        if (elements[r][position])
            changesMade = true;
        elements[r][position] = false;
        position++;
    }
    
    return changesMade;
}

void Table::allFirstValidRows() {
    for (int i = 0; i < rows; i++)
        firstValidRow(i);
}

bool Table::shiftByOne(int r, int c) {
    if (elements[r][columns - 1] == true)
        return false;
    for (int i = columns-1; i >= c; i--)
        elements[r][i] = elements[r][i-1];
    elements[r][c] = false;
    return true;
}

int Table::positionOfMovingBlock(int r) {
    int position = 0;
    for (int i = 1; i < blockMoving[r]; i++) {
        while (position < 24 && elements[r][position] == false)
            position++;
        while (position < 24 && elements[r][position] == true)
            position++;
    }
    while (position < 24 && elements[r][position] == false)
        position++;
    return position;
}

bool Table::shiftLeftOne(int r, int c) {
    if (c == 0 || elements[r][c-1])
        return false;
    while (c < 25) {
        elements[r][c-1] = elements[r][c];
        c++;
    }
    elements[r][columns - 1] = false;
    return true;
}

bool Table::resetRow(int r) {
    int shiftPosition = positionOfMovingBlock(r);
    while ((blockMoving[r] == 1 && shiftPosition > 0)
           || (blockMoving[r] > 1
               && shiftPosition > 2
               && !elements[r][shiftPosition - 2])) {
        if (shiftLeftOne(r, shiftPosition)) {
            shiftPosition--;
        }
        else
            return false;
    }
    return true;
}

bool Table::completeRow(int r) {
    int position = 0;
    while (!elements[r][position] && position < 25)
        position++;
    for (int i = position; i < 24; i++)
        if (!elements[r][i] && !elements[r][i+1])
            return false;
    return true;
}

bool Table::nextValidRow(int r) {
    if (completeRow(r))
        return false;
    
    int shiftPosition = positionOfMovingBlock(r);
    bool reset = false;
    while (!shiftByOne(r, shiftPosition)) {
        reset = true;
        /*if (completeRow(r))
            return false;*/
        while (!resetRow(r)) {
            blockMoving[r]--;
        }
        blockMoving[r]--;
        shiftPosition = positionOfMovingBlock(r);
    }
    if (reset)
        blockMoving[r]++;
    return true;
}

bool Table::matchesTemplate() {
    return elements[3][3] && elements[3][4] && elements[3][12]
    && elements[3][13] && elements[3][21] && elements[8][6] && elements[8][7]
    && elements[8][10] && elements[8][14] && elements[8][15] && elements[8][18]
    && elements[16][6] && elements[16][11] && elements[16][16] && elements[16]
    && elements[21][3] && elements[21][4] && elements[21][9] && elements[21][10]
    && elements[21][15] && elements[21][20] && elements[21][21];
}

bool Table::solve() {
    shiftingRow = 24;
    bool shift = false;
    while (shiftingRow >= 0 && !(valid() && matchesTemplate())) {
        while (shiftingRow >= 0 && !nextValidRow(shiftingRow)) {
            shift = true;
            if (valid() && matchesTemplate()) {
                std::cout << "\nPuzzle solved\n";
                return true;
            }
            while (shiftingRow >= 0 && firstValidRow(shiftingRow))
                shiftingRow--;
            shiftingRow--;
        }
        if (shift) {
            shiftingRow++;
            shift = false;
        }
    }
    if (valid() && matchesTemplate()) {
        std::cout << "\nPuzzle solved\n";
        return true;
    }
    return false;
}
