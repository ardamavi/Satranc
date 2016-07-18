// Arda Mavi - ardamavi.com

#ifndef PİYON_H
#define PİYON_H

#include "Tas.h"

class Piyon: public Tas{
    public:
        Piyon(takım, int , int );

        bool vezirOlsunMu(takım ,pair <int, int> );

        bool yolKntrl(vector<Tas*> , pair<int, int> );
};

#endif
