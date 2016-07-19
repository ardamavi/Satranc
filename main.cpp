// Arda Mavi - ardamavi.com

#include <iostream>
#include <utility>
#include "Tahta.h"
#include "Tas.h"
#include "Piyon.h"
#include "At.h"
#include "Fil.h"
#include "Sah.h"
#include "Kale.h"
#include "Vezir.h"

using namespace std;

// Fonksiyonlar :

int main(){

    // Mac icin ekran temizleme:
    //system("clear");

    Tahta tahta;

    //cout << tahta.hareketEt(make_pair(1,0), make_pair(2,0)) << endl;

    //cout << tahta.hareketEt(make_pair(1,0),make_pair(2,0)) << endl;


    //cout << 1 + 5 << endl;
    //Sah* sah = new Sah(beyaz, 5, 5);
    Piyon* piyon = new Piyon(beyaz, 5, 5);
    //tahta.tasEkle(sah);
    //tahta.tasEkle(sah2);

    return 0;
}
