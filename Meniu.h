#ifndef MAIN_CPP_MENIU_H
#define MAIN_CPP_MENIU_H

#include "Lista.h"

class Meniu
{
private:
    Lista *_stocProduse;
public:
    Meniu();
    void Dispatcher();
    Table GenereazaMeniuOptiuni();
    Table GenereazaAfisaj();
    ~Meniu();
};


#endif //MAIN_CPP_MENIU_H