#ifndef MAIN_CPP_LISTA_H
#define MAIN_CPP_LISTA_H

#include "Produs.h"

class Lista
{
private:
    Produs* _HEAD;
    vector<int> _coduriProdus;
public:
    Lista();
    void AdaugaProdus();
    void StergeProdus(int codProdus);
    void AfiseazaProdus(Produs *produsCautat);
    void CumparaProdus(int codProdus);
    Produs* CautaProdus(int codProdus);
    Produs* CautaProdus(string numeProdus);
    bool ValideazaStoc(int cantitateCumparata, Produs *produsCurent);
    Table GenereazaLista();
    int GenereazaCodProdus();

    void ImportStoc();
    void ExportStoc();

    bool ValideazaCod(int codProdus);
    string ValideazaNume();
    int ValideazaCantitate();
    float ValideazaPret();

    int TryGetCantitate(string cantitateProdus);
    float TryGetPret(string pretProdus);



    ~Lista();
};


#endif //MAIN_CPP_LISTA_H
