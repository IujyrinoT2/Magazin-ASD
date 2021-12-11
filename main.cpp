#include <iostream>
#include <string>
#include <vector>
#include <iomanip> //Folosit pentru afisare sub forma de tabel
#include "single_include/tabulate/tabulate.hpp"

//Hey asta va fi main

using namespace std;
using namespace tabulate;

struct Produs
{
    string numeProdus;
    int codProdus;
    float pretProdus;//Era float dar arata urat la afisare
    int cantitateProdus;
    Produs *next;
};

Produs *HEAD; // Va pointa catre capul de lista
int codProdusCounter = 1; // Pe asta il vom incrementa inainte sa adaugam un produs nou si il vom asigna catre codProdus pentru produsul nou.

//generam un vector cu 999 pozitii pentru toate codurile de produs de 3 cifre pe care le putem genere 
const int n=899;
 vector<int> vectcodProd(n, 0);

void AdaugareProdus(){  //poate fi un produs nou sau unul existent caz in care creste valoarea stocului
    int optiune;
    int codNou;
    string numeProdusNou;
    double pretProdusNou;
    int cantitateProdusNou;

    cout<<"Pentru adaugare produs nou, apasati tasta 1. Pentru produs existent apasati tasta 2."<<endl;
    cin >> optiune;
    Produs *p = new Produs ;
    if (optiune == 1){
        //generam codProdusNou pe baza listei de coduri vectcodProd 
        for(int i = 0;i<=899;i++)
        {
        if(vectcodProd[i] == 0)   {
            vectcodProd[i] = i+100;
            codNou = vectcodProd[i];
            p->codProdus = codNou;
            break;
         }
        } 
         //Citim numeProdus, pretProdus, cantitateProdus
        cout << "Introudceti numele produsului: " << endl ;
        cin >> numeProdusNou;
        p -> numeProdus = numeProdusNou;
        cout << "Introudceti pretul produsului: " << endl ;
        cin >> pretProdusNou;
        p -> pretProdus = pretProdusNou;
        cout << "Introudceti cantitatea produsului: " << endl ;
        cin >> cantitateProdusNou;
        p -> cantitateProdus = cantitateProdusNou;
        if (HEAD == nullptr){
            HEAD = p;
            p->next = nullptr;
            cout << endl << "Noul produs a fost adaugat cu succes! "; 
            return;
        }
        p -> next = HEAD;
        HEAD = p;
        cout << endl << "Noul produs a fost adaugat cu succes! "; 
        return;
    }
    else if (optiune == 2){
        //aici actualizam stocul unui produs existen
        //utilizatorul trebuie sa vada lista cu produse deja existente / check sa nu fie goala
        //alege un cod - este verificat daca exista in lista si apoi se actualizeaza stocul
        return;
    }
    cout << "Optiune invalida." << endl;
    return;
}

void AfisareProduse(){
    //Parcurgem lista de produse.
    //Afisam informatiile produselor intr-un tabel.
    
    const char separator = ' ';
    const int lungimeCategorie = 20; //Asta este numarul maxim de caractere care va fi afisat (include spatiile)
    Produs *iter;
    cout << "Lista de produse este: " << endl;
    for (iter = HEAD; iter-> next != NULL; iter = iter->next)
    {
 
    //Numele coloanelor VV
    std::cout<< std::left <<std::setw(lungimeCategorie)<<std::setfill(separator) << "Cod Produs";
    std::cout<< std::left <<std::setw(lungimeCategorie)<<std::setfill(separator) << "Nume Produs";
    std::cout<< std::left <<std::setw(lungimeCategorie)<<std::setfill(separator) << "Cantitate Produs";
    std::cout<< std::left <<std::setw(lungimeCategorie)<<std::setfill(separator) << "Pret Produs"<<std::endl;

    //Continutul liniei VV
    std::cout<< std::left <<std::setw(lungimeCategorie)<<std::setfill(separator) << iter->codProdus;
    std::cout<< std::left <<std::setw(lungimeCategorie)<<std::setfill(separator) << iter->numeProdus;
    std::cout<< std::left <<std::setw(lungimeCategorie)<<std::setfill(separator) << iter->cantitateProdus;
    std::cout<< std::left <<std::setw(lungimeCategorie)<<std::setfill(separator) << iter->pretProdus<<std::endl;
    }
     //Numele coloanelor VV
    std::cout<< std::left <<std::setw(lungimeCategorie)<<std::setfill(separator) << "Cod Produs";
    std::cout<< std::left <<std::setw(lungimeCategorie)<<std::setfill(separator) << "Nume Produs";
    std::cout<< std::left <<std::setw(lungimeCategorie)<<std::setfill(separator) << "Cantitate Produs";
    std::cout<< std::left <<std::setw(lungimeCategorie)<<std::setfill(separator) << "Pret Produs"<<std::endl;

    //Continutul liniei VV
    std::cout<< std::left <<std::setw(lungimeCategorie)<<std::setfill(separator) << iter->codProdus;
    std::cout<< std::left <<std::setw(lungimeCategorie)<<std::setfill(separator) << iter->numeProdus;
    std::cout<< std::left <<std::setw(lungimeCategorie)<<std::setfill(separator) << iter->cantitateProdus;
    std::cout<< std::left <<std::setw(lungimeCategorie)<<std::setfill(separator) << iter->pretProdus<<std::endl;
     cout << "-> END. \n";
     for (int i =0; i<=899; i++){
         if (vectcodProd[i] != 0){
             cout << i << " " << vectcodProd[i] << endl;
         }
 
};

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

    //Continutul liniei VV
    Table afisareElement;
    char codProdus[3];
    char numeProdus[30];
    char cantitateProdus[6];
    char pretProdus[6];
    itoa(produsCautat->codProdus, codProdus, 10);
    strcpy(numeProdus, produsCautat->numeProdus.c_str());
    itoa(produsCautat->cantitateProdus, cantitateProdus, 10);
    sprintf(pretProdus, "%.2f", produsCautat->pretProdus);
    afisareElement.add_row({codProdus, numeProdus, cantitateProdus, pretProdus});

    afisareElement.format() //CULOOOOOOOOOOORI
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

    cout << afisareElement << endl;

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

void AdaugareProdus(){
    //Citim numeProdus, pretProdus, cantitateProdus
    //Verificam daca exista produsul. Daca exista, doar vom creste cantitatea.
    //codProdus va lua valoarea lui codProdusCounter.
    //Incrementam codProdusCounter.
}

int main(){
    //Aici vom face meniul.
    

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
    tabelMeniu.add_row({"2", "Stergere un produs", "Se introduce codul produsului pe care doriti sa il stergeti."});
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
