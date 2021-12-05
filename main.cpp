#include <iostream>
#include <string>
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

void AfisareProduse(){
    //Parcurgem lista de produse.
    //Afisam informatiile produselor intr-un tabel.
};


Produs* CautareProdus(int codProdus){
    //Va gasi produsul cautat (dupa cod produs)
    //Va returna produsul.

}
void AfisareDetaliiProdus(Produs* produsCautat){
    //Va afisa toate campurile din structura produs
}
void CumparareProdus(int codProdus){
    // Vom cere cantitate cumparata (citita la tastatura) - tip int
    // Chemam validareStoc(int cantitateCumparata, CautareProdus(int codProdus)) -
    // Vom scadea cantitatea produsului cu cantitatea cumparata
    // Verificam daca stocul ajunge la 0, daca da, chemam StergeProdus(int codProdus)

}

bool ValidareStoc(int cantitateCumparata, Produs* produsCurent){
    // Verificam daca cantitateCumparata > cantitateProdus
}


void AdaugareProdus(){
    //Citim numeProdus, pretProdus, cantitateProdus
    //Verificam daca exista produsul. Daca exista, doar vom creste cantitatea.
    //codProdus va lua valoarea lui codProdusCounter.
    //Incrementam codProdusCounter.
}

void StergeProdus(int codProdus){
    //Chemam CautareProdus(codProdus)
    //Stergem produsul si refacem legaturile listei inlantuite
}


int main(){
    //Aici vom face meniul.
}
