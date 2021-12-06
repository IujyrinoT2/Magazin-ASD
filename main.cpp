#include <iostream>
#include <string>
#include <iomanip> //Folosit pentru afisare sub forma de tabel
using std::string;
struct Produs {
    string numeProdus;
    int codProdus;
    double pretProdus;
    int cantitateProdus;
    Produs* next;
};

Produs* HEAD; // Va pointa catre capul de lista

int codProdusCounter = 1; // Pe asta il vom incrementa inainte sa adaugam un produs nou si il vom asigna catre codProdus pentru produsul nou.


Produs* CautareProdus(int CodCautat) {
    Produs *cod = HEAD;
    if(HEAD == nullptr){
        std::cout<<"Nu exista produse pe stoc"<<std::endl;
        return nullptr;
    }
    while (cod->next != NULL && cod->codProdus != CodCautat) {
        cod = cod->next;
    }
    if(cod->next == NULL && cod->codProdus != CodCautat){
        std::cout<<"Codul cautat nu a fost gasit"<<std::endl;
        return nullptr;
    }
    return cod;
}
void AfisareDetaliiProdus(Produs* produsCautat){
    if(produsCautat == nullptr){
        return ; //Testeaza daca produsul dat ca argument nu este null
    }
    const char separator = ' ';
    const int lungimeCategorie = 20; //Asta este numarul maxim de caractere care va fi afisat (include spatiile)
    //Numele coloanelor VV
    std::cout<< std::left <<std::setw(lungimeCategorie)<<std::setfill(separator) << "Cod Produs";
    std::cout<< std::left <<std::setw(lungimeCategorie)<<std::setfill(separator) << "Nume Produs";
    std::cout<< std::left <<std::setw(lungimeCategorie)<<std::setfill(separator) << "Cantitate Produs";
    std::cout<< std::left <<std::setw(lungimeCategorie)<<std::setfill(separator) << "Pret Produs"<<std::endl;

    //Continutul liniei VV
    std::cout<< std::left <<std::setw(lungimeCategorie)<<std::setfill(separator) << produsCautat->codProdus;
    std::cout<< std::left <<std::setw(lungimeCategorie)<<std::setfill(separator) << produsCautat->numeProdus;
    std::cout<< std::left <<std::setw(lungimeCategorie)<<std::setfill(separator) << produsCautat->cantitateProdus;
    std::cout<< std::left <<std::setw(lungimeCategorie)<<std::setfill(separator) << produsCautat->pretProdus<<std::endl;
}

int main()
{

}
