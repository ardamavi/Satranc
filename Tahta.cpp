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
#include "Tahta.h"
#include "Color.h"


Color::Modifier color1(Color::BG_COLOR1);
Color::Modifier color2(Color::BG_COLOR2);
Color::Modifier cerceveColor(Color::BG_CERCEVE);
Color::Modifier tasBeyaz(Color::FG_TASBEYAZ);
Color::Modifier yaziBeyaz(Color::FG_BEYAZ);
Color::Modifier tasSiyah(Color::FG_TASSIYAH);
Color::Modifier defaultColor(Color::FG_DEFAULT);

using namespace std;


Tahta::Tahta(){
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

void Tahta::tahtaSil(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            tahta[i][j] = "   ";
        }
    }
}

void Tahta::tahtaCiz(){
    tahtaSil();
    for (int i = 0; i < taslar.size(); i++){
        Tas* tas = taslar[i];
        tahta[tas->getKonum().first][tas->getKonum().second] = (tas->tasKisaltmasi());
    }
    string cerceve = "    A  B  C  D  E  F  G  H    ";
    cout << cerceveColor << yaziBeyaz << cerceve << endl;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if (j == 0){
                cout << yaziBeyaz << " " << cerceveColor << i + 1 << " ";
            }
            if(j%2 == 0){
              if(i%2 == 0){
                cout << color1;
              }else{
                cout << color2;
              }
            }else{
              if(i%2 != 0){
                cout << color1;
              }else{
                cout << color2;
              }
            }

            if(tahta[i][j] != "   "){

              for (int c = 0; c < taslar.size(); c++) {
                if(taslar[c]->getKonum() == make_pair(i, j)){
                  if(taslar[c]->getTakim() == siyah){
                    // Beyaz ise :
                      cout << tasSiyah << tahta[i][j] ;
                  }else{
                    // Siyah ise :
                      cout << tasBeyaz << tahta[i][j] ;
                  }
                }
              }

            }else{
              cout << tahta[i][j] ;
            }

            if (j == 7){
                cout << yaziBeyaz << cerceveColor << " " << i + 1 << " ";
            }
        }
        cout << endl;
    }
    cout << yaziBeyaz << cerceveColor << cerceve << endl;
}

vector<Tas*>* Tahta::getTaslar(){
return &(this->taslar);
}

void Tahta::tasEkle(Tas* tas){
this->taslar.push_back(tas);
}

void Tahta::setTaslar(vector<Tas*> gelenTaslar){
  this->taslar.clear();
  this->taslar = gelenTaslar;
}

bool Tahta::tasHareket(pair<int, int> gidilecekYer, int rakipTasSira, bool rakiptasVarMi, int tasSira){
this->taslar[tasSira]->setKonum(gidilecekYer);
// Burada rakip tas var ise, erase et :
  if(rakiptasVarMi){
    this->taslar.erase(this->taslar.begin() + rakipTasSira);
  }
return true;
}

// hareket edildi : true
// 1. Verilen konumdaki tası bul
// 2. Tasin turunu ismine bakarak bul ve casting yap
// 3. Tasın gidilecekyere gidip gidemeyecegine bak.
// 4. Gidebiliyorsa konumunu guncelle.
// 5. Eger gittigi yerde baska bir rakip tas varsa, onu yok et.
bool Tahta::hareketEt(string oyuncuSirasi, pair <int, int> tasKonum, pair <int, int> gidilecekYer){

int tasSira;

for (int i = 0; i < this->taslar.size(); i++) {
    if(this->taslar[i]->getKonum() == tasKonum){
        tasSira = i;
        if(taslar[i]->getTakim() == beyaz && oyuncuSirasi != "Beyaz"){
          return false;
        }else if(taslar[i]->getTakim() == siyah && oyuncuSirasi != "Siyah"){
          return false;
        }
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

bool Tahta::sahVarMi(string hareketEdenTakim){

  pair <int, int> karsiTakimSahKonum;
  int i = 0;
  takim hareketEdenTakimKim;

  if(hareketEdenTakim == "Beyaz"){
    hareketEdenTakimKim = beyaz;
  }else{
    hareketEdenTakimKim = siyah;
  }

  for (i  = 0; i < taslar.size(); i++) {
    if(taslar[i]->getTakim() == hareketEdenTakimKim){
      continue;
    }

    if(taslar[i]->getAdi() == "Sah"){
      karsiTakimSahKonum = taslar[i]->getKonum();
      break;
    }

  }

  for(i = 0; i < taslar.size(); i++){

    if(taslar[i]->getTakim() != hareketEdenTakimKim){
      continue;
    }

    if(this->taslar[i]->getAdi() == "Piyon"){
      if (((Piyon*)this->taslar[i])->yolKntrl(taslar, karsiTakimSahKonum)) {
        // Sah varsa true doner :
          return true;
      }
    }else if(taslar[i]->getAdi() == "Kale"){
      if (((Kale*)this->taslar[i])->yolKntrl(taslar, karsiTakimSahKonum)) {
        // Sah varsa true doner :
          return true;
      }
    }else if(taslar[i]->getAdi() == "At"){
      if (((At*)this->taslar[i])->yolKntrl(taslar, karsiTakimSahKonum)) {
        // Sah varsa true doner :
          return true;
      }
    }else if(taslar[i]->getAdi() == "Fil"){
      if (((Fil*)this->taslar[i])->yolKntrl(taslar, karsiTakimSahKonum)) {
        // Sah varsa true doner :
          return true;
      }
    }else if(taslar[i]->getAdi() == "Vezir"){
      if (((Vezir*)this->taslar[i])->yolKntrl(taslar, karsiTakimSahKonum)) {
        // Sah varsa true doner :
          return true;
      }
    }else if(taslar[i]->getAdi() == "Sah"){
      if (((Sah*)this->taslar[i])->yolKntrl(taslar, karsiTakimSahKonum)) {
        // Sah varsa true doner :
          return true;
      }
    }

  }

// Sah yok :

return false;

}
