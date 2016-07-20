// Arda Mavi - ardamavi.com

#ifndef TAHTA_H
#define TAHTA_H

#include "Tas.h"
#include <utility>

class Tahta {
    private:
        string tahta[8][8];
        vector <Tas*> taslar;

    public:
        Tahta();

        void tahtaSil();

        void tahtaCiz();

    vector<Tas*>* getTaslar();

    void tasEkle(Tas* tas);

    bool tasHareket(pair<int, int>, int, bool, int);

    bool hareketEt(string, pair <int, int> , pair <int, int>);

    bool sahVarMi(string);

};

#endif
