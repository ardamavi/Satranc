// Arda Mavi - ardamavi.com

#include <iostream>
#include <vector>
#include <utility>
#include "Tas.h"
#include "Kale.h"
#include "At.h"
#include "Fil.h"
#include "Vezir.h"
#include "Piyon.h"
#include "Sah.h"


using namespace std;

class Tahta {
    private:
        // Satranç Tahtası:
        string tahta[8][8];

        vector <Tas*> taslar;


    public:
        Tahta(){
            int satir = 1;
            takim renk = beyaz;
            for (int i = 0; i < 8; i++){
                Piyon* piyon = new Piyon(renk, satir, i);
                taslar.push_back(piyon);
                if (i == 7 && renk == beyaz){
                    renk = siyah;
                    satir = 6;
                    i = -1;
                }
            }

            renk = beyaz;
            satir = 0;
            int sutun = 0;

            taslar.push_back(new Kale(renk, satir, sutun++));
            taslar.push_back(new At(renk, satir, sutun++));
            taslar.push_back(new Fil(renk, satir, sutun++));
            taslar.push_back(new Vezir(renk, satir, sutun++));
            taslar.push_back(new Sah(renk, satir, sutun++));
            taslar.push_back(new Fil(renk, satir, sutun++));
            taslar.push_back(new At(renk, satir, sutun++));
            taslar.push_back(new Kale(renk, satir, sutun++));


            renk = siyah;
            satir = 7;
            sutun = 0;
            taslar.push_back(new Kale(renk, satir, sutun++));
            taslar.push_back(new At(renk, satir, sutun++));
            taslar.push_back(new Fil(renk, satir, sutun++));
            taslar.push_back(new Vezir(renk, satir, sutun++));
            taslar.push_back(new Sah(renk, satir, sutun++));
            taslar.push_back(new Fil(renk, satir, sutun++));
            taslar.push_back(new At(renk, satir, sutun++));
            taslar.push_back(new Kale(renk, satir, sutun++));

        }

        void tahtaSil(){
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    tahta[i][j] = "   ";
                }
            }
        }

        void tahtaÇiz(){
            tahtaSil();
            for (int i = 0; i < taslar.size(); i++){
                Tas* tas = taslar[i];
                tahta[tas->getKonum().first][tas->getKonum().second] = tas->tasKisaltmasi() + " ";
            }
            string cerceve = "  A  B  C  D  E  F  G  H  ";
            cout << cerceve << endl;
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    if (j == 0){
                        cout << i + 1 << " ";
                    }
                    cout << tahta[i][j];
                    if (j == 7){
                        cout << i + 1;
                    }
                }
                cout << endl;
            }
            cout << cerceve << endl;
        }

    vector<Tas*> getTaslar(){
        return this->taslar;
    }

    void tasEkle(Tas* tas){
        this->taslar.push_back(tas);
    }

    bool tasHareket(pair<int, int> gidilecekYer, int rakipTasSira, bool rakiptasVarMi, int tasSira){
      // Burada rakip taş varsa, erase et
      if(rakiptasVarMi){
          this->taslar.erase(this->taslar.begin() + rakipTasSira);
      }
      this->taslar[tasSira]->setKonum(gidilecekYer);
      return true;
    }

    // hareket edildi : true
    // 1. Verilen konumdaki taşı bul
    // 2. Taşın türünü ismine bakarak bul ve casting yap
    // 3. Taşın gidilecekyer'e gidip gidemeyeceğine bak.
    // 4. Gidebiliyorsa konumunu güncelle.
    // 5. Eğer gittiği yerde başka bir rakip taş varsa, onu yok et.
    bool hareketEt(pair <int, int> tasKonum, pair <int, int> gidilecekYer){

        int tasSira;

        for (int i = 0; i < this->taslar.size(); i++) {
            if(this->taslar[i]->getKonum() == tasKonum){
                tasSira = i;
                break;
            }
        }

        int rakipTasSira;
        bool rakiptasVarMi = false;

        for (int j = 0; j < this->taslar.size(); j++) {
            if(this->taslar[j]->getKonum() == gidilecekYer){
                rakiptasVarMi = true;
                rakipTasSira = j;
                break;
            }
        }

        if(this->taslar[tasSira]->getAdi() == "Piyon"){
          if (((Piyon*)this->taslar[tasSira])->yolKntrl(this->taslar, gidilecekYer)) {
              return this->tasHareket(gidilecekYer,rakipTasSira,rakiptasVarMi,tasSira);
          }
        }else if(taslar[tasSira]->getAdi() == "Kale"){
          if (((Kale*)this->taslar[tasSira])->yolKntrl(this->taslar, gidilecekYer)) {
              return this->tasHareket(gidilecekYer,rakipTasSira,rakiptasVarMi,tasSira);
          }
        }else if(taslar[tasSira]->getAdi() == "At"){
          if (((At*)this->taslar[tasSira])->yolKntrl(this->taslar, gidilecekYer)) {
              return this->tasHareket(gidilecekYer,rakipTasSira,rakiptasVarMi,tasSira);
          }
        }else if(taslar[tasSira]->getAdi() == "Fil"){
          if (((Fil*)this->taslar[tasSira])->yolKntrl(this->taslar, gidilecekYer)) {
              return this->tasHareket(gidilecekYer,rakipTasSira,rakiptasVarMi,tasSira);
          }
        }else if(taslar[tasSira]->getAdi() == "Vezir"){
          if (((Vezir*)this->taslar[tasSira])->yolKntrl(this->taslar, gidilecekYer)) {
              return this->tasHareket(gidilecekYer,rakipTasSira,rakiptasVarMi,tasSira);
          }
        }else if(taslar[tasSira]->getAdi() == "Sah"){
          if (((Sah*)this->taslar[tasSira])->yolKntrl(this->taslar, gidilecekYer)) {
              return this->tasHareket(gidilecekYer,rakipTasSira,rakiptasVarMi,tasSira);
          }
        }

        return false;
    }

};
