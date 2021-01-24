#include <vector>

using namespace std;

class GaleShapley {
// skrivanje privatne implementacije
// od korisnika
#ifdef GALESHAPLEY_IMPL
private:
    size_t N;
    vector<vector<int> > preferira;
    bool zPreferiraM1(int z, int m, int m1);
    void spojiPrilagodiVektore(
        vector<vector<int> > &muskarci, 
        vector<vector<int> > &zene
    );
#endif

public:
    GaleShapley(
        vector<vector<int> > muskarci, 
        vector<vector<int> > zene
    );
    void printSolution();
};
