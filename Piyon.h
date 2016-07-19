// Arda Mavi - ardamavi.com

#ifndef PİYON_H
#define PİYON_H

#include "Tas.h"

class Piyon: public Tas{
    public:
        Piyon(takim, int , int );

        bool vezirOlsunMu(takim ,pair <int, int> );

        bool yolKntrl(vector<Tas*> , pair<int, int> );
};

#endif
