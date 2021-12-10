#include <iostream>
#include <string>
#include <vector>
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

int main(){
    //Aici vom face meniul.
    

    return 0;
}
