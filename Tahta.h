// Arda Mavi - ardamavi.com

#ifndef TAHTA_H
#define TAHTA_H

#include "Tas.h"

class Tahta {
    private:
        string tahta[8][8];
        vector <Tas*> taslar;

    public:
        Tahta(){
        }

        void tahtaSil();

        void tahtaÇiz();

    vector<Tas*> getTaslar();

    void tasEkle(Tas* tas);


    bool hareketEt(vector<Tas*>, pair <int, int> , pair <int, int>);

};

#endif
