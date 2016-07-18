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

// Oyuncular:
/*enum oyuncular{
    beyaz ,
    siyah,
    berabere,
    başlamadı,
    yok
};
oyuncular oyuncu;*/


// Fonksiyon Protoripleri:

//void oyna(oyuncular oyuncu);

void menü();

void yzileoyna();

void kazananyaz();

void oyuncuyaz();

bool oynanacakyerkntl(char konum);

int harftosayi(char harf);

bool kurallarkntrl(string taş, string olduğuYer, string  oynanacakyer);

bool piyonOynamaYeriKntrl(string renk, string olduğuYer, string  oynanacakyer);


// Değişkenler:
bool bitti;
char seçim;
//oyuncular kazanan;
char konum[2];
char oynanacakyer[2];


// Fonksiyonlar :

int main(){

    // Mac için ekran temizleme:
    //system("clear");

    Tahta tahta;

//cout << tahta.hareketEt(make_pair(1,0), make_pair(2,0)) << endl;

    //cout << hareketEt(make_pair(1,0),make_pair(2,0)) << endl;

    Sah* sah = new Sah(beyaz, 5, 5);
    tahta.tasEkle(sah);
    //tahta.tasEkle(sah2);

    cout << sah->yolKntrl(tahta.getTaslar(), make_pair(4,3)) << endl;

    /*cout << "Arda Mavi - İki Kişilik Satranç" << endl ;

    bitti = false;
    oyuncu = siyah;
    kazanan = başlamadı;

    menü();

    if(seçim != '0')
        kazanan = yok;
    do{

        system("clear");

        // Sıradaki Oyuncu Döndürülür.
        if(oyuncu == beyaz)
            oyuncu = siyah;
        else
            oyuncu = beyaz;

        if(seçim == '2') {
            // Satranç tahtası çizilir:
            tahtaçiz();
            oyna(oyuncu);
        }else if(seçim == '1') {
            yzileoyna();
            break;
        }

        // Kazanan Belirlenir : kazanankntrl()

    }while(kazanan == yok);

    cout << endl << "Kazanan: ";
    kazananyaz();*/

    return 0;
}


/*
void menü(){

    cout << "\n- Menü -" << endl
    << "0 - Çıkış (kntrl-c)\n1 - Bilgisayara Karşı\n2 - İki Kişilik" << endl
    << "\nLütfen Birini Seçiniz: ";

    cin >> seçim;

    switch(seçim){

        case '0':
            // Çıkış İşlemi
            break;
        case '1':
            // Yapay Zeka
            break;
        case '2':
            // İki Kişilik Oyun
            break;
        default:
            // Hatalı Giriş
            cout << endl << "Hatalı Giriş !\nLütfen Yeniden Giriniz !" << endl;
            menü();
            break;

    }

     cout << "Konum girişleri SayıHarf şeklinde olmalıdır! ( Örnek : 1a)" << endl;

}

void kazananyaz(){

    switch(kazanan){

        case beyaz:
            cout << "Beyaz";
            break;
        case siyah:
            cout << "Siyah";
            break;
        case berabere:
            cout << "Berabere";
            break;
        case yok:
            cout << "Oyun Daha Bitmedi";
            break;
        case başlamadı:
            cout << "Yok\nOyun Bitirildi" << endl;
            break;

    }

    cout << endl;

}

void oyuncuyaz(oyuncular oyuncu){

    switch(oyuncu){

        case beyaz:
            cout << "Beyaz";
            break;
        case siyah:
            cout << "Siyah";
            break;
        default:
            cout << "Yok\nOyun Bitirildi" << endl;
            break;

    }

}

int harftosayi(char harf){

    return ((int)harf-96);

}

bool oynanacakyerkntl(string konum){

    return (tahta[konum[0] - 48][harftosayi(konum[1])] == "   ");

}

bool taşyerikntrl(string konum){

    return (tahta[konum[0] - 48][harftosayi(konum[1])] != "   ");

}

void oyna(oyuncular oyuncu){

    oyun: // Goto sil

    cout << "Oyun Sırası: ";
    oyuncuyaz(oyuncu);
    cout << "\nOynayacağınız Taşın Konumunu Giriniz: ";

    cin >> konum;

    cout << "\nTaşı Oynayacağınız Konumu Giriniz: ";

    cin >> oynanacakyer;

    if(!((oynanacakyerkntl(oynanacakyer)) && (taşyerikntrl(konum)))) {
        cout << "Hatalı Giriş!" << endl << endl;
        system("Onu Oraya Oynayamazsın !   üf    . sılak");
        goto oyun;
    }

    string tmp = (tahta[konum[0] - 48][harftosayi(konum[1])]);

    // Hatırlatma: Oyuncu için 0 = Beyaz Oyuncu VE 1 = Siyah Oyuncu

    if(!((tmp[0] == 'b' && oyuncu == 0) || (tmp[0] == 's' && oyuncu == 1))) {
        cout << "Oyun Sırası Sende Değil!" << endl << endl;
        system("say Oyun Sırası Sende Değil!   üf    . sılak");
        goto oyun;
    }

    if(!(kurallarkntrl(tmp, konum, oynanacakyer))){
        cout << "Oraya Oynayamazsın !" << endl << endl;
        system("Onu Oraya Oynayamazsın !   üf    . sılak");
        goto oyun;
    }

    tahta[konum[0] - 48][harftosayi(konum[1])] = "   ";

    tahta[oynanacakyer[0] - 48][harftosayi(oynanacakyer[1])] = tmp;

}

bool kurallarkntrl(string taş,string olduğuYer, string  oynanacakyer){

    switch(taş[1]){

        case 'P':
            return (piyonOynamaYeriKntrl(taş, olduğuYer, oynanacakyer));
            break;

            // Diğer karakterler ve kuralları.

        default:
            cout << "Kayıtlı Olmayan Karakter !" << endl;
            break;
    }

    return true;
}

// Karakter Kuralları :

bool piyonOynamaYeriKntrl(string taş, string olduğuYer, string  oynanacakyer){

    char renk = taş[0];

    if(renk == 'b'){
        // Beyaz Renkli Taş İçin Geçerli :

        if(olduğuYer[0] == '2'){

            if(oynanacakyer[0] == '4' || oynanacakyer[0] == '3') {


                bool stunKntrl = (oynanacakyer[1] == olduğuYer[1]);
                if(stunKntrl){

                    return true;

                }else{

                    if()
                    // Bir çaprazı(eğer siyah taş varsa) true döner.

                }
            }
        }else{

            // Bir önü ya da çaprazı(eğer siyah taş varsa) true döner.

        }

    }

    return false;
}

void yzileoyna(){

    // Yapay Zeka İle Oyun:

    cout << "Oyunun Yapay Zeka Bölümü Hazırlık Aşamasındadır !" << endl;

    kazanan = başlamadı;
}
*/
