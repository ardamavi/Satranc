// Arda Mavi - ardamavi.com

#ifndef FİL_H
#define  FİL_H

#include "Tas.h"

class Fil : public Tas{

    public:
        Fil(takım, int, int);

    bool yolKntrl(vector<Tas*>, pair <int, int>);

};

#endif
