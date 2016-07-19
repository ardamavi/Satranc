// Arda Mavi - ardamavi.com

#include <iostream>
#include "Tas.h"

using namespace std;

class Fil : public Tas{

    public:
        Fil(takim renk, int x, int y): Tas(renk, "Fil", x, y){}

    bool yolKntrl(vector<Tas*> taslar, pair <int, int> gidilecekyer){

        // Çapraz gider.
        // Önüne biri çıkana kadar.

        // Çapraz gitme kontrol :
        // X azalırsa aynı oranda y de azalır YA DA x artarken aynı oranda y de artar.
        // Kendi Yerine oynayamaz :
        if(this->getKonum() == gidilecekyer){
            return false;
        }

        // Gittiği yerde taş olma :
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

        // Karşısına taş çıkma:
        // x Azalıyorsa : Sol ya da Sağ Yukarı çıkılıyor
        if(this->getKonum().first-gidilecekyer.first > 0) {
            if (this->getKonum().second-gidilecekyer.second > 0) {
                // Sol Yukarı Çıkılıyor.
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
                // Sağ Yukarı Çıkılıyor.
                // X azalırsa aynı oranda y de azalır YA DA x artarken aynı oranda y de artar.
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
            // x Artıyorsa : Sol ya da Sağ Aşağı İniliyor
            if(this->getKonum().second-gidilecekyer.second > 0){
                // Sol Aşağı İniliyor.

                // X azalırsa aynı oranda y de azalır YA DA x artarken aynı oranda y de artar.
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
                // Sağ Aşağı İniliyor.
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
