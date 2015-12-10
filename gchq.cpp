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
    
    table.print();
    
    if (table.valid())
        std::cout << "\nTable is valid\n";
    else
        std::cout << "\nTable is invalid\n";
        
        
    return 0;
}