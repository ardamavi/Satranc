// Arda Mavi - ardamavi.com

#include <iostream>
#include "Tas.h"

using namespace std;

class Piyon: public Tas{
    public:
        Piyon(takım renk, int x, int y) : Tas(renk, "Piyon", x, y){}

        bool vezirOlsunMu(takım renk,pair <int, int> gidilecekYer){

            if(renk == beyaz){
                // Taşın rengi beyaz ise:
                if(gidilecekYer.first == 0){
                    return true;
                } else{
                    return false;
                }
            }else{
                // Taşın rengi siyah ise:
                if(gidilecekYer.first == 7){
                    return true;
                } else{
                    return false;
                }
            }

        }

        bool yolKntrl(vector<Tas*> taslar, pair<int, int> gidilecekYer){
            // benim konumum this->konum
            //taslar[i].konum

            if(this->getKonum() == gidilecekYer){
                return false;
            }

            int yön;
            int başlamaYeri;

            if (this->getTakım() == beyaz)
            {
                yön = 1;
                başlamaYeri = 1;
            }
            else{
                yön = -1;
                başlamaYeri = 6;
            }

            // Geri gidemez :
            if(yön == 1 && this->getKonum().first > gidilecekYer.first){
                return false;
            } else if(yön == -1 && this->getKonum().first < gidilecekYer.first){
                return false;
            }


            if(( gidilecekYer != make_pair(this->getKonum().first+ (1 * yön), this->getKonum().second))
               && !((gidilecekYer == make_pair(this->getKonum().first+ (2 * yön), this->getKonum().second)) && this->getKonum().first == 1)
               && (gidilecekYer != make_pair(this->getKonum().first+ (1 * yön), this->getKonum().second- (1 * yön)))
               && (gidilecekYer != make_pair(this->getKonum().first+ (1 * yön), this->getKonum().second+ (1 * yön)))){
                return false;
            }

            int ileriLimiti = 1;
            // Piyon başlama yerindeyse
            if(this->getKonum().first == başlamaYeri){
                ileriLimiti = 2;
            }
            int mesafe = (gidilecekYer.first - this->getKonum().first) * yön;

            if (ileriLimiti < mesafe)
            {
                return false;
            }

            // İleri gidiliyorsa :
            if(gidilecekYer.second == this->getKonum().second) {

                for (int i = 0; i < taslar.size(); i++) {
                    if (taslar[i]->getKonum() == this->getKonum()) {
                        continue;
                    }
                    if (taslar[i]->getKonum() ==
                                      make_pair(this->getKonum().first + (1 * yön), this->getKonum().second)) {
                        return false;
                    }
                    if (mesafe > 1 && taslar[i]->getKonum() ==
                                      make_pair(this->getKonum().first + (2 * yön), this->getKonum().second)) {
                        return false;
                    }
                }
            }

            // çapraz gidiyorsa
            if(gidilecekYer == make_pair(this->getKonum().first+ (1 * yön), this->getKonum().second- (1 * yön))){

                // Eğer çaprazı doluysa:
                for (int i = 0; i < taslar.size(); i++) {
                    if(taslar[i]->getKonum() == this->getKonum()){
                        continue;
                    }
                    if(taslar[i]->getKonum() == make_pair(this->getKonum().first+ (1 * yön), this->getKonum().second- (1 * yön))){
                        if (taslar[i]->getTakım() == this->getTakım()) {
                            return false;
                        }
                        else {
                            return true;
                        }
                    }
                }
                return false;

            } else if(gidilecekYer == make_pair(this->getKonum().first+ (1 * yön), this->getKonum().second+ (1 * yön))){
                // Eğer çaprazı doluysa:
                for (int i = 0; i < taslar.size(); i++) {
                    if(taslar[i]->getKonum() == this->getKonum()){
                        continue;
                    }
                    if(taslar[i]->getKonum() == make_pair(this->getKonum().first+ (1 * yön), this->getKonum().second+ (1 * yön))){
                        if (taslar[i]->getTakım() == this->getTakım()) {
                            return false;
                        }
                        else{
                            return true;
                        }
                    }
                }
                return false;

            }

            // Piyon belirtilen konuma gidebilir mi?
            // 1. Piyon başlangıç satırındaysa ve önü boşsa 1 veya 2 adım önüne gidebilir.
            // 2. Piyon başlangıç satırında değilse ve önü boşsa 1 adım önüne gidebilir.
            // 3. Piyon çaprazında rakip taş varsa, çapraz önüne gidebilir.

            return true;
        }
};
