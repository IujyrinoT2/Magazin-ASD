#include "Meniu.h"

int main()
{
    Meniu *test = new Meniu;
    test->GetStocProduse()->InitializareLista();
    test->AfisareMeniu();
    return 0;
}
