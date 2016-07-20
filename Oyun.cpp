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
  return ((int)(harf)-97);
}

int sayiCharToSayi(char sayiChar){
  return ((int)sayiChar-49);
}

int main(){

    // Mac icin ekran temizleme:
    system("clear");

    // Mac için seslendirme:
    //system("say Arda Mavi nin Satranç oyununa hoş geldiniz");

    cout << "- Satranç -\nArda Mavi - ardamavi.com" << endl;
    cout << "Girişler SayiHarf seklinde olmalidir. Orn: 2e" << endl;
    cout << "Oyundan çıkış: kntrl c\n" << endl;

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

bool oynamaTamamMi = true;

    do{

      // Tahta Silinir ve Cizilir:
      tahta.tahtaCiz();

      if(!oynamaTamamMi){
        cout << "\nHatalı Giriş !\n";
        system("say Hatalı giriş!");
      }

    // Mac icin oyun sırası seslendirme:
    cout << "\nOyun Sırası: " << oyunSirasi << endl;
    if(oyunSirasi == "Beyaz"){
      system("say Oyun sırası beyaz takımda");
    }else if(oyunSirasi == "Siyah"){
      system("say Oyun sırası siyah takımda");
    }

    char tasinKonumuChar[3];
    cout << "\nTaşın Konumunu giriniz: ";
    cin >> tasinKonumuChar;
    tasinKonumu.first = sayiCharToSayi(tasinKonumuChar[0]);
    tasinKonumu.second = harfToSayi(tasinKonumuChar[1]);

    char oynanacakYerChar[3];
    cout << "\nTaşı Oynayacağınız Konumu Giriniz: ";
    cin >> oynanacakYerChar;
    oynanacakYer.first = sayiCharToSayi(oynanacakYerChar[0]);
    oynanacakYer.second = harfToSayi(oynanacakYerChar[1]);

    //Dogru oynanmis mi :
    oynamaTamamMi = (tahta.hareketEt(oyunSirasi, tasinKonumu,oynanacakYer));

    // Mac icin ekran temizleme:
    system("clear");

  }while(!oynamaTamamMi);

    // Sah mı ?
    if(tahta.sahVarMi(oyunSirasi)){
      cout << "Şah !" << endl;

      // Mac için seslendirme :
      system("say Şah !");
    }

  }while(kazanan == "Yok");

  // Tahta Silinir ve Cizilir:
  tahta.tahtaCiz();

  cout << "\nKazanan: " << kazanan << "\nOyun Bitti\n" << endl;

  // Mac icin oyunun bitimini sesli haber verme:
  system("say Oyun bitti !");
  system("say Kazanan: ");

  // Mac icin kazanan seslendirme:
  if(kazanan == "Beyaz"){
    system("say Kazanan Beyaz takım!");
  }else if(kazanan == "Siyah"){
    system("say Kazanan Siyah takım!");
  }else{
    system("say Kazanan yok!");
  }

    return 0;
}
