#include "Lista.h"

Lista::Lista()
{
   this->_HEAD = new Produs;
   this->_vectcodProd = vector(899,0);
}

Produs *Lista::GetHead()
{
    return this->_HEAD;
}

void Lista::SetHead(Produs* noulHead)
{
  this->_HEAD = noulHead;
}

void Lista::AdaugaProdus()
{  //poate fi un produs nou sau unul existent caz in care creste valoarea stocului
    int optiune;
    int codNou;
    string numeProdusNou;
    float pretProdusNou;
    int cantitateProdusNou;

    cout << "Pentru adaugare produs nou, apasati tasta 1." << endl;
    cout << "Pentru un produs deja existent apasati tasta 2." << endl;
    cin >> optiune;
    Produs *p = new Produs;
    if (optiune == 1)
    {
        //generam codProdusNou pe baza listei de coduri vectcodProd
        for (int i = 0; i <= 899; i++)
        {
            if (this->_vectcodProd[i] == 0)
            {
                this->_vectcodProd[i] = i + 100;
                codNou = this->_vectcodProd[i];
                p->SetCodProdus(codNou);
                break;
            }
        }
        //Citim numeProdus, pretProdus, cantitateProdus
        cout << "Introudceti numele produsului: " << endl;
        cin >> numeProdusNou;
        p->SetNumeProdus(numeProdusNou);
        cout << "Introudceti pretul produsului: " << endl;
        cin >> pretProdusNou;
        p->SetPretProdus(pretProdusNou);
        cout << "Introudceti cantitatea produsului: " << endl;
        cin >> cantitateProdusNou;
        p->SetCantitateProdus(cantitateProdusNou);
        if (this->_HEAD == nullptr)
        {
            this->_HEAD = p;
            p->SetNext(nullptr);
            cout << endl << "Noul produs a fost adaugat cu succes! ";
            return;
        }
        p->SetNext(this->_HEAD);
        this->_HEAD = p;
        cout << endl << "Noul produs a fost adaugat cu succes! ";
        return;
    } else if (optiune == 2)
    {
        //aici actualizam stocul unui produs existen
        //utilizatorul trebuie sa vada lista cu produse deja existente / check sa nu fie goala
        //alege un cod - este verificat daca exista in lista si apoi se actualizeaza stocul
        return;
    }
    cout << "Optiune invalida." << endl;
    return;
}






