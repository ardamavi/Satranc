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

    void setTaslar(vector<Tas*>);

    bool tasHareket(pair<int, int>, int, bool, int);

    bool hareketEt(string, pair <int, int> , pair <int, int>);

    pair<int, int> rakipTakimSahKonum(takim);

    int rakipTakimSahSira(takim);

    pair<bool, int> tehditVarMi(pair<int, int>, takim);

    bool sahMatMi(takim, int);

    bool sahVarMi(takim);

};

#endif
