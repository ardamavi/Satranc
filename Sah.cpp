// Arda Mavi - ardamavi.com

#include <iostream>
#include "Tas.h"

using namespace std;

class Sah : public Tas{

    public:
    Sah(takim renk, int x, int y) : Tas(renk, "Sah", x, y){}

    // Oynanacak yer ile şu anki mesafenin karesini ölçüyor. (Pisagor üçgeni)
    double mesafeKare(pair <int, int> konum1, pair <int, int> konum2){

        double sonuc = (double)( ((konum2.first-konum1.first)*(konum2.first-konum1.first)) +
                ((konum2.second - konum1.second)*(konum2.second - konum1.second)) );

        return sonuc;
    }

    bool sahaYakinMi(vector<Tas*> taslar, pair <int, int> gidilecekyer){

        for (int i = 0; i < taslar.size(); i++) {
            // Taş Bizim Taşsa :
            if(taslar[i]->getKonum() == this->getKonum()){
                continue;
            }

            // Burada kaladın :

            // Çevredeyse :
                for (int a = -1; a < 2; a++) {
                    // Satır Kontrol :
                    for (int b = -1; b < 2; b++) {
                        // Stun Kontrol :
                        if(taslar[i]->getKonum() == make_pair(gidilecekyer.first+a, gidilecekyer.second+b)){
                            if(taslar[i]->getAdi() == "Sah") {
                                return true;
                            }
                        }
                    }
                }

        }

        return false; // Yakın değil.
    }

    bool yolKntrl(vector<Tas*> taslar, pair <int, int> gidilecekyer){

        // 1 adım oynar.
        // Başka şaha en az 1 kare uzaklıkta yaklaşabilir.
        // Başka şahı yiyemez.

        // Kendi yerine oynayamaz:
        if(this->getKonum() == gidilecekyer){
            return false;
        }

        if(mesafeKare(this->getKonum(),gidilecekyer) > 2){
            return false;
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

        if(sahaYakinMi(taslar, gidilecekyer)){
            return false;
        }

        return true;
    }

};
