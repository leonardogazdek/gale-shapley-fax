#include <iostream> 
#include <vector>
#include "galeshapley.h"

using namespace std; 
  
int main() { 
    vector<vector<int> > muskarci = {
        {1, 0, 2}, 
        {2, 1, 0}, 
        {0, 2, 1},
    };

    vector<vector<int> > zene = {
        {1, 0, 2}, 
        {2, 1, 0}, 
        {0, 2, 1}, 
    };

    GaleShapley solution(muskarci, zene);
    solution.printSolution();
    return 0; 
} 