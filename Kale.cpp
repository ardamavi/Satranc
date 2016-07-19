// Arda Mavi - ardamavi.com

#include <iostream>
#include "Tas.h"

using namespace std;

class Kale: public Tas{

    public:
        Kale(takim renk, int x, int y) : Tas(renk, "Kale", x, y){}

    bool yolKntrl(vector<Tas*> taslar, pair <int, int> gidilecekyer){
        // Kendi Yerine oynayamaz :
        if(this->getKonum() == gidilecekyer){
            return false;
        }
        // Kale Kurallar:

        // 1. Sağ sola gidebilir.
        // 2. Yukarı aşşağı gidebilir.

        // Gideceği yerle arasında taş varsa false döne.

        // Ta ki önüne biri çıkana kadar :
            // Önüne çıkan farklı renkse yer.
            // Aynı renkse gidemez.

        // Sağ sol ve aşağı yukarı kontrol :
        if(!(gidilecekyer.first == this->getKonum().first || gidilecekyer.second == this->getKonum().second)) {
            return false;
        }

        // Gideceği yerle arasında taş varsa false döner:

        if(gidilecekyer.first == this->getKonum().first){
            // Sağ sol giderse:    (Y ekseni değişir)

            for (int i = 0; i < taslar.size(); i++) {
                if(taslar[i]->getKonum() == this->getKonum()){
                    continue;
                }

                if(gidilecekyer.second < this->getKonum().second){
                    // Sola Hareket:

                    if(taslar[i]->getKonum().first == this->getKonum().first && taslar[i]->getKonum().second < this->getKonum().second){
                        // Taşımızın solunda :

                        if(gidilecekyer.second < taslar[i]->getKonum().second){
                            // Taş yoluna çıktı :
                            return false;
                        }

                    }

                } else{
                    // Sağ hareket :

                    if(taslar[i]->getKonum().first == this->getKonum().first && taslar[i]->getKonum().second > this->getKonum().second){
                        // Taşımızın sağında :

                        if(gidilecekyer.second > taslar[i]->getKonum().second){
                            // Taş yoluna çıktı :
                            return false;
                        }

                    }

                }
            }

        }else if(gidilecekyer.second == this->getKonum().second){
            // Yukarı aşağı giderse : (X ekseni değişir)

            for (int i = 0; i < taslar.size(); i++) {
                if(taslar[i]->getKonum() == this->getKonum()){
                    continue;
                }

                if(gidilecekyer.first < this->getKonum().first){
                    // yukarı Hareket:

                    if(taslar[i]->getKonum().first > gidilecekyer.first
                       && taslar[i]->getKonum().second == gidilecekyer.second
                       && this->getKonum().first > taslar[i]->getKonum().first){
                        // Önümüze çıktı :
                        return false;
                    }
                    }else{
                    // aşağı hareket :

                    if(taslar[i]->getKonum().first < gidilecekyer.first
                       && taslar[i]->getKonum().first > this->getKonum().first
                       && gidilecekyer.second == taslar[i]->getKonum().second){
                        // Önümüze çıktı :
                        return false;
                    }
                }
            }
        // Gittiği yerde kendi takımı varsa false döner :
        for (int k = 0; k < taslar.size(); k++) {
            if(taslar[k]->getKonum() == this->getKonum()){
                continue;
            }
            if(taslar[k]->getKonum() == gidilecekyer) {
                if (this->getTakim() == taslar[k]->getTakim()){
                    return false;
                }
            }
        }
        }
        return true;
    }
};
