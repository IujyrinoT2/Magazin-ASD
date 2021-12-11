#ifndef MAIN_CPP_LISTA_H
#define MAIN_CPP_LISTA_H

#include "Produs.h"

class Lista
{
private:
    Produs* _HEAD;
    vector<int> _vectcodProd;

public:
    Lista();
    Produs* GetHead();
    void SetHead(Produs* noulHead);
    void AdaugaProdus();
    void StergeProdus();
    void AfiseazaProdus();
    void CumparaProdus();
    Produs* CautaProdus();
    void ValideazaStoc();
};


#endif //MAIN_CPP_LISTA_H
