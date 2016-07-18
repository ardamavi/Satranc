// Arda Mavi - ardamavi.com

#ifndef SAH_H
#define SAH_H

#include "Tas.h"

class Sah : public Tas{

    public:
    Sah(takım, int, int);

    double mesafeKare(pair <int, int> , pair <int, int>);

    bool sahaYakınMı(vector<Tas*>, pair <int, int>);

    bool yolKntrl(vector<Tas*>, pair <int, int>);

};

#endif
