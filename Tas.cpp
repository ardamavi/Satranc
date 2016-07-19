// Arda Mavi - ardamavi.com

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "Tas.h"

using namespace std;

string Tas::tasKisaltmasi(){

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


Tas::Tas(takim renk, string adi, int x, int y){
    this->renk = renk;
    this->adi = adi;
    this->konum = make_pair(x, y);
}

pair<int, int> Tas::getKonum() {
    return this->konum;
}

takim  Tas::getTakim(){
    return this->renk;
}

string Tas::getAdi(){
    return this->adi;
}

void Tas::setKonum(pair <int, int> gidilecekYer){
    this->konum = gidilecekYer;
}
