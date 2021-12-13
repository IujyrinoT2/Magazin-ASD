#include "Meniu.h"

int main()
{
    Meniu *test = new Meniu;
    cout<<test->GenereazaAfisaj()<<endl;
    test->Dispatcher();
    delete test;
    return 0;
}
