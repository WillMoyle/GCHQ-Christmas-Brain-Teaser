// GCHQ 2015 Christmas Brain Teaser - Solution
// Author: Will Moyle
// Last Modified: 10 December 2015

/* This program provides a solution to the 2015 Christmas Brain Teaser posted
 by GCHQ. The problem can be found at:
 http://www.gchq.gov.uk/SiteCollectionImages/grid-shading-puzzle.jpg */

#include <iostream>
#include "table.hpp"

using namespace std;

int main() {
    
    Table table;
    
    table.allFirstValidRows();
    
    bool test = true;
    if (test) {
        table.printRow(22);
        
        while (table.nextValidRow(22))
            table.printRow(22);
        
        
        if (table.firstValidRow(22)) {
            cout << "\nReturns true";
        };
        table.printRow(22);
        cout << "\n";
    }
    if (test) {
        table.printRow(22);
        
        while (table.nextValidRow(22))
            table.printRow(22);
        
        
        if (table.firstValidRow(22)) {
            cout << "\nReturns true";
        };
        table.printRow(22);
        cout << "\n";
    }
    else {
        table.solve();
        table.print();
    }
    
    cout << "\n\n";
    
    return 0;
}