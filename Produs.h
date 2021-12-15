#ifndef MAIN_CPP_PRODUS_H
#define MAIN_CPP_PRODUS_H

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "single_include/tabulate/tabulate.hpp"

using namespace std;
using namespace tabulate;


class Produs
{
private:
    string _numeProdus;
    int _codProdus;
    float _pretProdus;
    int _cantitateProdus;
    Produs *_next;
public:
    Produs();
    void SetNumeProdus(string noulNumeProdus);
    void SetCodProdus(int noulCodProdus);
    void SetPretProdus(float noulPretProdus);
    void SetCantitateProdus(int nouaCantitateProdus);
    void SetNext(Produs* noulNext);
    string GetNumeProdus();
    int GetCodProdus();
    float GetPretProdus();
    int GetCantitateProdus();
    Produs* GetNext();
};


#endif //MAIN_CPP_PRODUS_H
