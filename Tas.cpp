// Arda Mavi - ardamavi.com

#include <iostream>
#include <string>
#include <utility>
#include <vector>
//#include "Tas.h"
//#include "Tahta.h"
/*#include "At.h"
#include "Piyon.h"
#include "Fil.h"
#include "Sah.h"
#include "Kale.h"
#include "Vezir.h"*/

using namespace std;

enum takım{

    beyaz = 1,
    siyah = -1

};


class Tas{
    private:
        takım renk;
        string adı;
        pair <int, int> konum;

    public:



        Tas(takım renk, string adı, int x, int y){
            this->renk = renk;
            this->adı = adı;
            this->konum = make_pair(x, y);
        }

        string tasKisaltmasi(){

            char tmpRenk;

            switch (this->renk){

                case 1:
                    tmpRenk = 'b';
                    break;
                case -1:
                    tmpRenk = 's';
                    break;

            }

            char tmpKısaltma[3] = {tmpRenk, adı[0], '\0'};
            string kısaltma = tmpKısaltma;

            return kısaltma;
        }

        pair<int, int> getKonum() {
            return this->konum;
        }

        takım  getTakım(){
            return this->renk;
        }

        string getAdı(){
            return this->adı;
        }

        void setKonum(pair <int, int> gidilecekYer){
            this->konum = gidilecekYer;
        }
};
