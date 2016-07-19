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

int harfToSayi(char harf){
  return ((int)(harf)-96);
}

int main(){

    cout << "- Satranç -\nArda Mavi - ardamavi.com" << endl;

    string kazanan = "Yok";
    string oyunSirasi = "Siyah";
    pair <int, int> tasinKonumu;
    pair <int, int> oynanacakYer;

    Tahta tahta;

  do{

    // Siradaki Oyuncu Dondurulur.
    if(oyunSirasi == "Beyaz"){
        oyunSirasi = "Siyah";
    }else{
        oyunSirasi = "Beyaz";
    }

    do{

      // Mac icin ekran temizleme:
      system("clear");

      // Tahta Silinir ve Cizilir:
      tahta.tahtaCiz();

    cout << "\nOyun Sırası: " << oyunSirasi << endl;

    char tasinKonumuChar[3];
    cout << "\nTaşın Konumunu giriniz: ";
    cin >> tasinKonumuChar;
    tasinKonumu.first = tasinKonumuChar[0];
    tasinKonumu.second = harfToSayi(tasinKonumuChar[1]);

    char oynanacakYerChar[3];
    cout << "\nTaşı Oynayacağınız Konumu Giriniz: ";
    cin >> oynanacakYerChar;
    oynanacakYer.first = oynanacakYerChar[0];
    oynanacakYer.second = harfToSayi(oynanacakYerChar[1]);

    //TODO: Doğru oynanmış mı ?
  }while(!(tahta.hareketEt(oyunSirasi, tasinKonumu,oynanacakYer)));

    //TODO: Kazananın belirlenmesi.
    kazanan = "Beyaz";

  }while(kazanan == "Yok");

  cout << "Oyun Bitti\n\nKazanan: " << kazanan << endl;

    return 0;
}
