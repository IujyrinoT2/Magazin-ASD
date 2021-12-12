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
    void StergeProdus(int codProdus);
    void AfiseazaProdus(Produs *produsCautat);
    void CumparaProdus(int codProdus);
    Produs* CautaProdus(int codProdus);
    bool ValideazaStoc(int cantitateCumparata, Produs *produsCurent);
    void AfiseazaLista();
};


#endif //MAIN_CPP_LISTA_H
