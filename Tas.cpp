// Arda Mavi - ardamavi.com

#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

enum takim{

    beyaz = 1,
    siyah = -1

};

class Tas{
    private:
        takim renk;
        string adi;
        pair <int, int> konum;

    public:



        Tas(takim renk, string adi, int x, int y){
            this->renk = renk;
            this->adi = adi;
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

            char tmpKisaltma[3] = {tmpRenk, adi[0], '\0'};
            string kisaltma = tmpKisaltma;

            return kisaltma;
        }

        pair<int, int> getKonum() {
            return this->konum;
        }

        takim  getTakim(){
            return this->renk;
        }

        string getadi(){
            return this->adi;
        }

        void setKonum(pair <int, int> gidilecekYer){
            this->konum = gidilecekYer;
        }
};
