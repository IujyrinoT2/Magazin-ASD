#include <iostream>
#include <string>
#include <iomanip> //Folosit pentru afisare sub forma de tabel
#include "single_include/tabulate/tabulate.hpp"

using namespace std;
using namespace tabulate;

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
    cout << left << std::setw(lungimeCategorie) << setfill(separator) << "Cod Produs";
    cout << left << std::setw(lungimeCategorie) << setfill(separator) << "Nume Produs";
    cout << left << std::setw(lungimeCategorie) << setfill(separator) << "Cantitate Produs";
    cout << left << std::setw(lungimeCategorie) << setfill(separator) << "Pret Produs" << endl;

    //Continutul liniei VV
    cout << left << std::setw(lungimeCategorie) << std::setfill(separator) << produsCautat->codProdus;
    cout << left << std::setw(lungimeCategorie) << std::setfill(separator) << produsCautat->numeProdus;
    cout << left << std::setw(lungimeCategorie) << std::setfill(separator) << produsCautat->cantitateProdus;
    cout << left << std::setw(lungimeCategorie) << std::setfill(separator) << produsCautat->pretProdus << endl;
}

bool ValidareStoc(int cantitateCumparata, Produs *produsCurent)
{
    // Verificam daca cantitateCumparata > cantitateProdus
    return true; // Am pus asta temporar - pentru a nu mai vedea warningul
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
    Produs *nodCrt = HEAD;
    cout << "Produsele sunt: " << endl;
    while (nodCrt != NULL)
    {
        AfisareDetaliiProdus(nodCrt);
        nodCrt = nodCrt->next;
    }
}

void OptiuneUtilizator(int userInput)
{
    while (userInput)
    {
        cout << "Introduceti numarul actiunii dorite: ";
        cin >> userInput;
        cout << endl;
        switch (userInput)
        {
            case 1: //Adaugare produs
            {
                AdaugareProdus();
                cout << endl;
            }
                break;
            case 2: //Stergere produs
            {
                int codProdus;
                cout << "Introduceti codul produsului pe care doriti sa il stergeti: " << endl;
                cin >> codProdus;
                StergeProdus(codProdus);
                cout << endl;
            }
                break;
            case 3: //Afisare detalii produs
            {
                int codProdus;
                cout << "Introduceti codul produsului pentru care doriti afisarea detaliilor: " << endl;
                cin >> codProdus;
                AfisareDetaliiProdus(CautareProdus(codProdus));
                cout << endl;
            }
                break;
            case 4: //Cumparare produs
            {
                int codProdus;
                cout << "Introduceti codul produsului pe care doriti sa il achizitionati:  " << endl;
                CumparareProdus(codProdus);
                cout << endl;
            }
                break;
            case 5: //Afisare produse
            { ;
                AfisareProduse();
                cout << endl;
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
            }
        }
    }
}

void AfisareMeniu()
{
    int userInput;
    Table tabelMeniu;
    tabelMeniu.add_row({"ID", "OPTIUNE", "DESCRIERE OPTIUNE"});
    tabelMeniu.add_row({"1", "Adaugare un produs", "Vom adauga un produs. Codul produsul este generat automat."});
    tabelMeniu.add_row({"2", "Sergere un produs", "Se introduce codul produsului pe care doriti sa il stergeti."});
    tabelMeniu.add_row({"3", "Afisare detalii pentru un produs",
                        "Se introduce codul produsului al carui detalii va intereseaza."});
    tabelMeniu.add_row(
            {"4", "Cumparare un produs", "Se introduce codul produsului pe care doriti sa il achizitionati."});
    tabelMeniu.add_row({"5", "Afisare lista produse", "Se vor afisa toate produsele din stoc."});
    tabelMeniu.add_row({"0", "Iesire din program", "Se va iesi din program."});
    tabelMeniu.format()
            .corner_top_left("*")
            .corner_top_right("*")
            .corner_bottom_left("*")
            .corner_bottom_right("*")
            .corner_top_left_color(Color::red)
            .corner_top_right_color(Color::red)
            .corner_bottom_left_color(Color::red)
            .corner_bottom_right_color(Color::red)
            .font_align(FontAlign::center)
            .font_color(Color::cyan)
            .border_top("~")
            .border_bottom("~")
            .border_left("|")
            .border_right("|")
            .border_left_color(Color::cyan)
            .border_right_color(Color::cyan)
            .border_top_color(Color::cyan)
            .border_bottom_color(Color::cyan);
    cout << tabelMeniu << endl;
    OptiuneUtilizator(userInput);
}

int main()
{
    cout << "Buna ziua!" << endl;
    AfisareMeniu();
    return 0;
}
