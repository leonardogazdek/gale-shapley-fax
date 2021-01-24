#define GALESHAPLEY_IMPL

#include <iostream>
#include <algorithm>
#include "galeshapley.h"

using namespace std;

bool GaleShapley::zPreferiraM1(int z, int m, int m1) { 
    for (int i = 0; i < N; i++) { 
        if (preferira[z][i] == m1) 
            return true;                 
    } 
    return false; 
} 

void GaleShapley::spojiPrilagodiVektore(
    vector<vector<int> > &muskarci, 
    vector<vector<int> > &zene
) {
    for(vector<int>& prefs : muskarci) {
        for(int& pref : prefs) {
            pref += N;
        }
    }
    muskarci.insert(muskarci.end(), zene.begin(), zene.end());
    preferira = muskarci;
}

GaleShapley::GaleShapley(
    vector<vector<int> > muskarci, 
    vector<vector<int> > zene
) : N(muskarci[0].size()) {
    spojiPrilagodiVektore(muskarci, zene);
}

void GaleShapley::printSolution() { 
    vector<int> zPartner(N);
    vector<bool> mZauzet(N);
    // -1 oznacava da zena nema partnera, 
    // inicijalizirati sve elemente vektora na -1
    fill(zPartner.begin(), zPartner.end(), -1);
    // false oznacava da je muskarac slobodan
    fill(mZauzet.begin(), mZauzet.end(), false);
    int n_slobodnih = N; 
    // iteriraj dok ima slobodnih muskaraca
    while (n_slobodnih > 0) { 
        int m; 
        // spremi indeks prvog 
        // slobodnog muskarca u varijablu m
        for (m = 0; m < N; m++) 
            if (mZauzet[m] == false) 
                break; 
        // iteriranje kroz listu preferenca trenutnog
        // muskarca sve dok on ne postane zauzet
        for (int i = 0; i < N && mZauzet[m] == false; i++) { 
            int z = preferira[m][i]; 
            // ako zena nema partnera, muskarac postaje njen partner
            if (zPartner[z-N] == -1) { 
                zPartner[z-N] = m; 
                mZauzet[m] = true; 
                n_slobodnih--; 
            } else { 
                int m1 = zPartner[z-N]; 
                // ako zena ima partnera, ali vise preferira 
                // muskarca koji se iterira, on postaje njen partner
                if (zPreferiraM1(z, m, m1) == false) { 
                    zPartner[z-N] = m; 
                    mZauzet[m] = true; 
                    mZauzet[m1] = false; 
                } 
            } 
        } 
    } 
    // ispis
    cout << " M\tZ" << endl; 
    for (int i = 0; i < N; i++) 
        cout << " " << zPartner[i] << "\t" << i << endl; 
} 