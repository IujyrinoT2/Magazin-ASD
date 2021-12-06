#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

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

bool ValidareStoc(int cantitateCumparata, Produs* produsCurent){
    // Verificam daca cantitateCumparata > cantitateProdus
}

void StergeProdus(int codProdus){
    Produs *p = CautareProdus(codProdus);

    if(p == nullptr) {                                              //  Cand nu s-a gasit produsul, functia se opreste
        cout << "Produsul nu s-a gasit";
        return;
    }

    Produs* p_aux = p;

    if(HEAD == p) {                                                 // Stergerea cand produsul este primul element
        p = p->next;
        HEAD = p;
        delete p_aux;
        return;
    }

    int codProdusAnterior = codProdus - 1;
    while((p = CautareProdus(codProdusAnterior)) == nullptr)       // Gasirea produsului anterior care are cod valid in caz
        codProdusAnterior--;                                       // ca au mai fost facute stergeri

    p->next = (p->next)->next;                                     // Stergerea produsului in celelalte cazuri
    delete p_aux;                                                  // si refacearea legaturilor
}

void CumparareProdus(int codProdus){
    Produs *p = CautareProdus(codProdus);
    if(p == nullptr){
        cout << "Nu s-a gasit produsul" << endl;
        return;
    }
                                                                                    // Vom cere cantitate cumparata (citita la tastatura) - tip int
    int cantitateCumparata;

    do {
        cout << "Ce cantitate doriti sa cumparati? ";
        cin >> cantitateCumparata;
        if(cantitateCumparata <= 0)
            cout << "Introduceti o cantitate valida" << endl;
    }while(cantitateCumparata <= 0);
                                                                                    // Chemam validareStoc(int cantitateCumparata, CautareProdus(int codProdus))
    if(!ValidareStoc(cantitateCumparata, CautareProdus(codProdus))) {
        cout << "Stoc insuficient" << endl;
        return;
    }
                                                                                    // Vom scadea cantitatea produsului cu cantitatea cumparata
    p->cantitateProdus -= cantitateCumparata;
                                                                                    // Verificam daca stocul ajunge la 0, daca da, chemam StergeProdus(int codProdus)
    if(!p->cantitateProdus)
        StergeProdus(codProdus);
}

void AdaugareProdus(){
    //Citim numeProdus, pretProdus, cantitateProdus
    //Verificam daca exista produsul. Daca exista, doar vom creste cantitatea.
    //codProdus va lua valoarea lui codProdusCounter.
    //Incrementam codProdusCounter.
}
void citireLista(int n) {
    Produs *q = new Produs;
    int codnou = 0;
    for(int i = 0; i < n; i++) {
        Produs *p = new Produs;
        p->codProdus = ++codnou;
        cout << "\nnume produs: ";
        cin >> p->numeProdus;
        cout << "\npret produs: ";
        cin >> p->pretProdus;
        cout << "\ncantitate produs: ";
        cin >> p->cantitateProdus;

        p->next= nullptr;
        if(HEAD == nullptr)
            HEAD = p;
        else
            q->next= p;
        q = p;
    }
}



int main(){
    //Aici vom face meniul.
    int n;
    cout << "n = ";
    cin >> n;

    citireLista(n);


    return 0;
}
