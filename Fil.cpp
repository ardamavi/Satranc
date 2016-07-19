// Arda Mavi - ardamavi.com

#include <iostream>
#include "Tas.h"

using namespace std;

class Fil : public Tas{

    public:
        Fil(takim renk, int x, int y): Tas(renk, "Fil", x, y){}

    bool yolKntrl(vector<Tas*> taslar, pair <int, int> gidilecekyer){

        // Capraz gider.
        // Onune biri cikana kadar.

        // Capraz gitme kontrol :
        // X azalirsa ayni oranda y de azalir YA DA x artarken ayni oranda y de artar.
        // Kendi Yerine oynayamaz :
        if(this->getKonum() == gidilecekyer){
            return false;
        }

        // Gittigi yerde tas olma :
        for(int i = 0; i < taslar.size(); i++){
            if(taslar[i]->getKonum() == this->getKonum()){
                continue;
            }
            if(taslar[i]->getKonum() == gidilecekyer) {
                if(taslar[i]->getTakim() == this->getTakim()){
                    return false;
                }
            }
        }

        // Karsisina tas cıkma:
        // x Azaliyorsa : Sol ya da Sag Yukari cikiliyor
        if(this->getKonum().first-gidilecekyer.first > 0) {
            if (this->getKonum().second-gidilecekyer.second > 0) {
                // Sol Yukari Çikiliyor.
                if( ( this->getKonum().first-gidilecekyer.first != this->getKonum().second-gidilecekyer.second ) ){
                    return false;
                }
                for (int i = gidilecekyer.first+1; i < this->getKonum().first; i++) {
                    for (int k = 0; k < taslar.size(); k++) {
                        if(taslar[i]->getKonum() == this->getKonum()){
                            continue;
                        }
                        if(taslar[k]->getKonum() == make_pair(i,i)){
                            return false;
                        }
                    }
                }

            }else{
                // Sag Yukari Çikiliyor.
                // X azalirsa ayni oranda y de azalir YA DA x artarken ayni oranda y de artar.
                if((this->getKonum().first + this->getKonum().second != gidilecekyer.first + gidilecekyer.second)){
                    return false;
                }
                for (int i = this->getKonum().first+1, j = this->getKonum().second-1; i < gidilecekyer.first-1; i++) {
                    for (int k = 0; k < taslar.size(); k++) {
                        if(taslar[i]->getKonum() == this->getKonum()){
                            continue;
                        }
                        if(taslar[k]->getKonum() == make_pair(i,j)){
                            return false;
                        }
                    }
                    j--;
                }
                }
            }else {
            // x Artiyorsa : Sol ya da Sag Asagi Iniliyor
            if(this->getKonum().second-gidilecekyer.second > 0){
                // Sol Aşagi Iniliyor.

                // X azalirsa ayni oranda y de azalir YA DA x artarken ayni oranda y de artar.
                if((this->getKonum().first + this->getKonum().second != gidilecekyer.first + gidilecekyer.second)){
                    return false;
                }

                for (int i = this->getKonum().first+1, j = this->getKonum().second-1; i < gidilecekyer.first-1; i++) {
                    for (int k = 0; k < taslar.size(); k++) {
                        if(taslar[i]->getKonum() == this->getKonum()){
                            continue;
                        }
                        if(taslar[k]->getKonum() == make_pair(i,j)){
                            return false;
                        }
                    }
                    j--;
                }

            }else{
                // Sag Asagi Iniliyor.
                if( ( this->getKonum().first-gidilecekyer.first != this->getKonum().second-gidilecekyer.second ) ){
                    return false;
                }
                for (int i = this->getKonum().first+1; i < gidilecekyer.first; i++) {
                    for (int k = 0; k < taslar.size(); k++) {
                        if(taslar[i]->getKonum() == this->getKonum()){
                            continue;
                        }
                        if(taslar[k]->getKonum() == make_pair(i,i)){
                            return false;
                        }
                    }
                }

            }
        }

        return true;
    }

};
