// Arda Mavi - ardamavi.com

#include <iostream>
#include "Tas.h"
#include "Fil.h"
#include "Kale.h"

using namespace std;

class Vezir : public Tas{

    public:
        Vezir(takım renk, int x, int y) : Tas(renk, "Vezir", x, y){}

    bool yolKntrl(vector<Tas*> taslar, pair <int, int> gidilecekyer){

        return Kale(this->getTakım(), this->getKonum().first, this->getKonum().second).yolKntrl(taslar, gidilecekyer)
                || Fil(this->getTakım(), this->getKonum().first, this->getKonum().second).yolKntrl(taslar, gidilecekyer);
    }

};
