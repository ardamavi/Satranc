// Arda Mavi - ardamavi.com

#ifndef TAS_H
#define TAS_H

#include <iostream>
#include <vector>

using namespace std;

enum takım{

    beyaz = 1,
    siyah = -1

};

class Tas{
    private:
        takım renk;
        string adı;
        pair <int, int> konum;

    public:


        Tas(takım, string, int, int);

        string tasKisaltmasi();

        pair<int, int> getKonum();

        takım  getTakım();

        string getAdı();

        void setKonum(pair <int, int> );
};

#endif
