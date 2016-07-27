// Arda Mavi - ardamavi.com

#include <iostream>
#include <string>
#include <utility>
#include "Color.h" // namespace Color
#include "Tahta.h"
#include "Tas.h"
#include "Piyon.h"
#include "At.h"
#include "Fil.h"
#include "Sah.h"
#include "Kale.h"
#include "Vezir.h"
#include "Color.h"

Color::Modifier defaultColorfg(Color::FG_DEFAULT);
Color::Modifier defaultColorbg(Color::BG_DEFAULT);

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

    cout << defaultColorbg << defaultColorfg;

    cout << "- Satranç -\nArda Mavi - ardamavi.com" << endl;
    cout << "Girişler SayiHarf seklinde olmalidir. Orn: 2e" << endl;
    cout << "Rok girişleri için: \"uzun rok\" ya da \"kısa rok\" diye yazmalısınız." << endl;
    cout << "Oyundan çıkış: kntrl c\n" << endl;

    string kazanan = "Yok";
    string oyunSirasi = "Siyah";
    pair <int, int> tasinKonumu;
    pair <int, int> oynanacakYer;
    bool sahDurum = false;

    Tahta tahta;

  do{

    // Siradaki Oyuncu Dondurulur.
    if(oyunSirasi == "Beyaz"){
        oyunSirasi = "Siyah";
    }else{
        oyunSirasi = "Beyaz";
    }

    bool oynamaTamamMi = true;
    takim takimOyunSirasi;
    takim takimEskiOyunSirasi;

    do{

      cout << defaultColorbg << defaultColorfg << endl;
      // Tahta Silinir ve Cizilir:
      tahta.tahtaCiz();
      cout << defaultColorbg << defaultColorfg << endl;

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

    string eskiOyunSirasi;

    if(oyunSirasi == "Beyaz"){
      takimOyunSirasi = beyaz;
      eskiOyunSirasi = "Siyah";
      takimEskiOyunSirasi = siyah;
    }else if(oyunSirasi == "Siyah"){
      takimOyunSirasi = siyah;
      eskiOyunSirasi = "Beyaz";
      takimEskiOyunSirasi = beyaz;
    }

    vector<Tas*> taslarKopya;

    // Taşlar kopyalanır:
    for (int i = 0; i < tahta.getTaslar()->size(); i++) {
      taslarKopya.push_back(new Tas(*(*(tahta.getTaslar()))[i]));
    }

    string tasinKonumuChar;
    cout << "\nTaşın Konumunu giriniz: ";
    getline(cin, tasinKonumuChar);

    if(tahta.karsilastir(tasinKonumuChar, KISA_ROK, 8) != true && tahta.karsilastir(tasinKonumuChar, UZUN_ROK, 8) != true){
    tasinKonumu.first = sayiCharToSayi(tasinKonumuChar[0]);
    tasinKonumu.second = harfToSayi(tasinKonumuChar[1]);

      string oynanacakYerChar;
      cout << "\nTaşı Oynayacağınız Konumu Giriniz: ";
      getline(cin, oynanacakYerChar);
      oynanacakYer.first = sayiCharToSayi(oynanacakYerChar[0]);
      oynanacakYer.second = harfToSayi(oynanacakYerChar[1]);
    }

    if(sahDurum == true){

      if(tahta.karsilastir(tasinKonumuChar, KISA_ROK, 8) != true && tahta.karsilastir(tasinKonumuChar, UZUN_ROK, 8) != true){
        tahta.hareketEt(oyunSirasi, tasinKonumu, oynanacakYer);
      }else{
        tahta.rokYapma(oyunSirasi, tasinKonumuChar);
      }

      sahDurum = tahta.sahVarMi(takimEskiOyunSirasi);

      if(sahDurum == true){
        // Kopyalanan orijinale atanir :
        tahta.setTaslar(taslarKopya);
        cout << "Şahınızı kurtarmanız lazım !" << endl;

        // Mac için seslendirme :
        system("say Şahınızı kurtarmanız lazım !");

        oynamaTamamMi = false;
      }else{
        //Dogru oynanmis mi :
        oynamaTamamMi = true;
      }

    }else{

      if(tahta.karsilastir(tasinKonumuChar, "kısa rok", 8) != true && tahta.karsilastir(tasinKonumuChar, UZUN_ROK, 8) != true){
        //Dogru oynanmis mi :
        oynamaTamamMi = (tahta.hareketEt(oyunSirasi, tasinKonumu,oynanacakYer));
      }else{
        oynamaTamamMi = tahta.rokYapma(oyunSirasi, tasinKonumuChar);
      }

      if(tahta.sahVarMi(takimEskiOyunSirasi)){
        oynamaTamamMi = false;
        cout << "Şahınızı tehlikeye atamazsınız !" << endl;

        tahta.setTaslar(taslarKopya);

        // Mac için seslendirme :
        system("say Şahınızı tehlikeye atamazsınız !");
      }
    }

    // Mac icin ekran temizleme:
    system("clear");

    for (int i = 0; i < taslarKopya.size(); i++)
    {
      delete(taslarKopya[i]);
    }
    taslarKopya.clear();
  }while(!oynamaTamamMi);

    // Şah ve mat var mı ?
    sahDurum = tahta.sahVarMi(takimOyunSirasi);

    // Sah mı ?
    if(sahDurum){
      cout << "Şah !" << endl;

      // Mac için seslendirme :
      system("say Şah !");


      if(tahta.sahMatMi(takimOyunSirasi, tahta.tehditVarMi(tahta.rakipTakimSahKonum(takimOyunSirasi), takimOyunSirasi).second)){
        // Mat oldu !
        cout << "Mat !" << endl;
        system("say Mat !");

        kazanan = oyunSirasi;
      }

    }

  }while(kazanan == "Yok");

  // Tahta Silinir ve Cizilir:
  tahta.tahtaCiz();

  cout << defaultColorbg << defaultColorfg;

  cout << "\nOyun Bitti\n" << "\nKazanan: " << kazanan << endl;

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
