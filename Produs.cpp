#include "Produs.h"

Produs::Produs()
{
    this->_numeProdus = "Nume produs";
    this->_codProdus = -100;
    this->_pretProdus = -100;
    this->_cantitateProdus = -100;
    this->_next = NULL;
}

void Produs::SetNumeProdus(string noulNumeProdus)
{
    this->_numeProdus = noulNumeProdus;
}

void Produs::SetCodProdus(int noulCodProdus)
{
    this->_codProdus = noulCodProdus;
}

void Produs::SetPretProdus(float noulPretProdus)
{
    this->_pretProdus = noulPretProdus;
}

void Produs::SetCantitateProdus(int nouaCantitateProdus)
{
    this->_cantitateProdus = nouaCantitateProdus;
}

void Produs::SetNext(Produs *noulNext)
{
   this->_next = noulNext;
}

string Produs::GetNumeProdus()
{
    return this->_numeProdus;
}

int Produs::GetCodProdus()
{
    return this->_codProdus;
}

float Produs::GetPretProdus()
{
    return this->_pretProdus;
}

int Produs::GetCantitateProdus()
{
    return this->_cantitateProdus;
}

Produs *Produs::GetUrmatorulProdus()
{
    return this->_next;
}

Produs::~Produs()
{
    cout << "Destructor: Produsul a fost sters cu succes." << endl;
}





