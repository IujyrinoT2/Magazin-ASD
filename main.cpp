#include <iostream>
#include <string>
#include <iomanip> //Folosit pentru afisare sub forma de tabel

using namespace std;

struct Produs
{
    string numeProdus;
    int codProdus;
    double pretProdus;
    int cantitateProdus;
    Produs *next;
};

Produs *HEAD; // Va pointa catre capul de lista
int codProdusCounter = 1; // Pe asta il vom incrementa inainte sa adaugam un produs nou si il vom asigna catre codProdus pentru produsul nou.


Produs *CautareProdus(int CodCautat)
{
    Produs *cod = HEAD;
    if (HEAD == nullptr)
    {
        std::cout << "Nu exista produse pe stoc" << std::endl;
        return nullptr;
    }
    while (cod->next != NULL && cod->codProdus != CodCautat)
    {
        cod = cod->next;
    }
    if (cod->next == NULL && cod->codProdus != CodCautat)
    {
        std::cout << "Codul cautat nu a fost gasit" << std::endl;
        return nullptr;
    }
    return cod;
}

void AfisareDetaliiProdus(Produs *produsCautat)
{

    if (produsCautat == nullptr)
    {
        return; //Testeaza daca produsul dat ca argument nu este null
    }
    const char separator = ' ';
    const int lungimeCategorie = 20; //Asta este numarul maxim de caractere care va fi afisat (include spatiile)
    //Numele coloanelor VV
    std::cout << std::left << std::setw(lungimeCategorie) << std::setfill(separator) << "Cod Produs";
    std::cout << std::left << std::setw(lungimeCategorie) << std::setfill(separator) << "Nume Produs";
    std::cout << std::left << std::setw(lungimeCategorie) << std::setfill(separator) << "Cantitate Produs";
    std::cout << std::left << std::setw(lungimeCategorie) << std::setfill(separator) << "Pret Produs" << std::endl;

    //Continutul liniei VV
    std::cout << std::left << std::setw(lungimeCategorie) << std::setfill(separator) << produsCautat->codProdus;
    std::cout << std::left << std::setw(lungimeCategorie) << std::setfill(separator) << produsCautat->numeProdus;
    std::cout << std::left << std::setw(lungimeCategorie) << std::setfill(separator) << produsCautat->cantitateProdus;
    std::cout << std::left << std::setw(lungimeCategorie) << std::setfill(separator) << produsCautat->pretProdus
              << std::endl;
}

bool ValidareStoc(int cantitateCumparata, Produs *produsCurent)
{
    // Verificam daca cantitateCumparata > cantitateProdus
}

void StergeProdus(int codProdus)
{
    Produs *p = CautareProdus(codProdus);

    if (p == nullptr)
    {                                              //  Cand nu s-a gasit produsul, functia se opreste
        cout << "Produsul nu s-a gasit";
        return;
    }

    Produs *p_aux = p;

    if (HEAD == p)
    {                                                 // Stergerea cand produsul este primul element
        p = p->next;
        HEAD = p;
        delete p_aux;
        return;
    }

    int codProdusAnterior = codProdus - 1;
    while ((p = CautareProdus(codProdusAnterior)) ==
           nullptr)       // Gasirea produsului anterior care are cod valid in caz
        codProdusAnterior--;                                       // ca au mai fost facute stergeri

    p->next = (p->next)->next;                                     // Stergerea produsului in celelalte cazuri
    delete p_aux;                                                  // si refacearea legaturilor
}

void CumparareProdus(int codProdus)
{
    Produs *p = CautareProdus(codProdus);
    if (p == nullptr)
    {
        cout << "Nu s-a gasit produsul" << endl;
        return;
    }
    // Vom cere cantitate cumparata (citita la tastatura) - tip int
    int cantitateCumparata;

    do
    {
        cout << "Ce cantitate doriti sa cumparati? ";
        cin >> cantitateCumparata;
        if (cantitateCumparata <= 0)
            cout << "Introduceti o cantitate valida" << endl;
    } while (cantitateCumparata <= 0);
    // Chemam validareStoc(int cantitateCumparata, CautareProdus(int codProdus))
    if (!ValidareStoc(cantitateCumparata, CautareProdus(codProdus)))
    {
        cout << "Stoc insuficient" << endl;
        return;
    }
    // Vom scadea cantitatea produsului cu cantitatea cumparata
    p->cantitateProdus -= cantitateCumparata;
    // Verificam daca stocul ajunge la 0, daca da, chemam StergeProdus(int codProdus)
    if (!p->cantitateProdus)
        StergeProdus(codProdus);
}

void AdaugareProdus()
{
    //Citim numeProdus, pretProdus, cantitateProdus
    //Verificam daca exista produsul. Daca exista, doar vom creste cantitatea.
    //codProdus va lua valoarea lui codProdusCounter.
    //Incrementam codProdusCounter.
}

void AfisareProduse()
{

}

void AfisareMeniu()
{
    int userInput;
    cout << "Optiuni: " << endl;
    cout << "1. Adaugare produs." << endl;
    cout << "2. Stergere produs." << endl;
    cout << "3. Afisare detalii produs." << endl;
    cout << "4. Cumparare produs." << endl;
    cout << "5. Afisare produse." << endl;
    cout << "0. Iesire din program." << endl;
    cout << "Introduceti numarul actiunii dorite: " << endl;
    cin >> userInput;

    switch (userInput)
    {
        case 1: //Adaugare produs
        {
            AdaugareProdus();
            cout << endl;
            AfisareMeniu();
        }
            break;
        case 2: //Stergere produs
        {
            int codProdus;
            cout << "Introduceti codul produsului pe care doriti sa il stergeti: " << endl;
            cin >> codProdus;
            StergeProdus(codProdus);
            cout << endl;
            AfisareMeniu();
        }
            break;
        case 3: //Afisare detalii produs
        {
            int codProdus;
            cout << "Introduceti codul produsului pentru care doriti afisarea detaliilor: " << endl;
            cin >> codProdus;
            AfisareDetaliiProdus(CautareProdus(codProdus));
            cout << endl;
            AfisareMeniu();
        }
            break;
        case 4: //Cumparare produs
        {
            int codProdus;
            cout << "Introduceti codul produsului pe care doriti sa il achizitionati:  " << endl;
            CumparareProdus(codProdus);
            cout << endl;
            AfisareMeniu();
        }
            break;
        case 5: //Afisare produse
        { ;
            AfisareProduse();
            cout << endl;
            AfisareMeniu();
        }
            break;
        case 0: //Iesire din program
        {
            cout << "La revedere!" << endl;
        }
            break;
        default:
        {
            cout << "Valoarea introdusa este invalida." << endl;
            AfisareMeniu();
        }
    }
}

int main()
{

    cout <<"Buna ziua!"<<endl;
    AfisareMeniu();
    return 0;

}
