#include "Lista.h"
#include <cstring>
Lista::Lista()
{
    this->_HEAD = new Produs;
    this->_coduriProdus = vector<int>(899, 0);
}

void Lista::AdaugaProdus()
{
    string numeProdusNou;
    int cantitateProdusNou;
    float pretProdusNou;

    cout << "Introduceti denumirea noului produs: ";
    cin.clear();
    cin.sync();
    getline(cin, numeProdusNou);
    cout << endl;
    cout << "Introduceti pretul noului produs: ";
    cin >> pretProdusNou;
    cout << endl;
    cout << "Introduceti cantitatea noului produs: ";
    cin >> cantitateProdusNou;
    cout << endl;

    std::cout.setstate(std::ios_base::failbit); //Opresc bufferul pt output ca functia sa nu mai afiseze text
    Produs* numeExistent = CautaProdus(numeProdusNou);
    std::cout.clear();//Repornesc bufferul pt output
     if(numeExistent != NULL)
     {
         std::cout<<"Produsul deja exista, doriti sa ii cresteti stocul ? (Y/N) "<<endl;
         char optiune;
         std::cin>>optiune;
         switch (optiune) {
             case 'Y':
             case 'y':
                 numeExistent->SetCantitateProdus(numeExistent->GetCantitateProdus()+cantitateProdusNou);//setez cantitatea produsului existent cu cantitatea sa + cantitate noua


             break;

             case'N':
             case'n':
                std::cout<<"Cantitatea produsului original a ramas neschimbata";
             break;
         }
     }else{
         Produs* produsNou = new Produs;
         produsNou->SetCodProdus(GenereazaCodProdus());
         produsNou->SetNumeProdus(numeProdusNou);
         produsNou->SetPretProdus(pretProdusNou);
         produsNou->SetCantitateProdus(cantitateProdusNou);
         produsNou->SetNext(NULL);

         if (this->_HEAD != NULL)
         {
             Produs *produsCurent = this->_HEAD;
             while (produsCurent->GetNext() != NULL)
             {
                 produsCurent = produsCurent->GetNext();
             }
             produsCurent->SetNext(produsNou);
         } else
         {
             this->_HEAD = produsNou;
         }
    }


}

void Lista::StergeProdus(int codProdus) {
    Produs *p = CautaProdus(codProdus);
    if (p == NULL) {
        cout << "Produsul nu a fost gasit";
        return;
    }
    for (int i = 0; i < 899; i++) {
        if (_coduriProdus[i] == codProdus) {
            _coduriProdus[i] = 0;
        }
    }
    if (this->_HEAD->GetNext() == p) {
        this->_HEAD->SetNext(p->GetNext());
        delete p;
    } else {
        Produs *p_aux = this->_HEAD;
        while (p_aux->GetNext() != p) {
            p_aux = p_aux->GetNext();
        }
        p_aux->SetNext(p->GetNext());
        delete p;
    }
}

void Lista::AfiseazaProdus(Produs *produsCautat) {
    if (produsCautat == NULL) {
        return;
    }

    Table afisareElement;
    char pretProdus[20];
    sprintf(pretProdus, "%.2f", produsCautat->GetPretProdus());
    afisareElement.add_row({"COD PRODUS", "DENUMIRE PRODUS", "CANTITATE", "PRET"});
    afisareElement.add_row({to_string(produsCautat->GetCodProdus()), produsCautat->GetNumeProdus(),
                            to_string(produsCautat->GetCantitateProdus()), pretProdus});
    cout << afisareElement << endl;
}

void Lista::CumparaProdus(int codProdus) {
    Produs *p = CautaProdus(codProdus);
    if (p == NULL) {
        cout << "Nu s-a gasit produsul" << endl;
        return;
    }
    int cantitateCumparata;
    cout << "Introduceti cantitatea cumparata: ";
    cin >> cantitateCumparata;
    cout << endl;

    while (cantitateCumparata < 0) {
        cout << "Introduceti o cantitate cumparata valida: ";
        cin >> cantitateCumparata;
        cout << endl;
    }

    if (!ValideazaStoc(cantitateCumparata, CautaProdus(codProdus))) {
        cout << "Stoc insuficient" << endl;
        return;
    }

    p->SetCantitateProdus(p->GetCantitateProdus() - cantitateCumparata);

    if (!p->GetCantitateProdus()) {
        cout << "Cantitatea acestui produs a ajuns la 0." << endl;
        StergeProdus(codProdus);
    }
}

Produs *Lista::CautaProdus(int codCautat) {
    Produs *cod = this->_HEAD;
    if (this->_HEAD == NULL) {
        std::cout << "Nu exista produse pe stoc" << std::endl;
        return NULL;
    }
    while (cod->GetNext() != NULL && cod->GetCodProdus() != codCautat) {
        cod = cod->GetNext();
    }
    if (cod->GetNext() == NULL && cod->GetCodProdus() != codCautat) {
        std::cout << "Codul cautat nu a fost gasit" << std::endl;
        return NULL;
    }
    return cod;
}

Produs *Lista::CautaProdus(string numeCautat)
{
    Produs *nume = this->_HEAD;
    if (this->_HEAD == NULL)
    {
        std::cout << "Nu exista produse pe stoc" << std::endl;
        return NULL;
    }
    while (nume->GetNext() != NULL && nume->GetNumeProdus().find(numeCautat) == std::string::npos)
    {
        nume = nume->GetNext();
    }
    if (nume->GetNext() == NULL && nume->GetNumeProdus().find(numeCautat) == std::string::npos)
    {
        std::cout << "Numele cautat nu a fost gasit" << std::endl;
        return NULL;
    }
    return nume;

}

bool Lista::ValideazaStoc(int cantitateCumparata, Produs *produsCurent)
{
    return 0 <= produsCurent->GetCantitateProdus() - cantitateCumparata;
}

Table Lista::GenereazaLista()
{
    Table listaProduse;
    listaProduse.format()
            .font_align(FontAlign::center);
    listaProduse.add_row(
            {"COD PRODUS", "DENUMIRE PRODUS", "CANTITATE", "PRET"});
    Produs *nodCrt = this->_HEAD->GetNext();
    while (nodCrt != NULL)
    {
        char codProdus[3];
        char numeProdus[20];
        char cantitateProdus[20];
        char pretProdus[20];
        sprintf(codProdus, "%d", nodCrt->GetCodProdus());
        strcpy(numeProdus, nodCrt->GetNumeProdus().c_str());
        sprintf(cantitateProdus, "%d", nodCrt->GetCantitateProdus());
        sprintf(pretProdus, "%.2f", nodCrt->GetPretProdus());
        listaProduse.add_row({codProdus, numeProdus, cantitateProdus, pretProdus});
        nodCrt = nodCrt->GetNext();
    }
    return listaProduse;
}

int Lista::GenereazaCodProdus() {
    for (int i = 0; i < 899; i++) {
        if (_coduriProdus[i] == 0) {
            _coduriProdus[i] = i + 100;
            return _coduriProdus[i];
        }
    }
    return -1;
}

void Lista::ImportStoc() {
    string numeProdus, linie, cuvant;
    float pretProdus;
    int cantitateProdus, nrElem, cod;
    string trashCan;
    string src;
    cout << "Introduceti calea catre fisierul din care se importa: ";
    cin.clear();
    cin.sync();
    getline(cin, src);
    if(src.empty()) {
        cout << "Nici-o sursa primita\n";
        return;
    }
    ifstream fin(src);

    if (!fin)
        cout << "Eroare la deschiderea fisierului " << src << endl << " Asigurati-va ca fiserul este inchis!\n";

    getline(fin, linie);

    while (getline(fin, linie)) {
        Produs *produsNou = new Produs;

        nrElem = -1;
        for (int i = 0; i < linie.size() + 1; i++) {
            if (linie[i] != ',' && i < linie.size()) {
                cuvant.push_back(linie[i]);
            } else {
                nrElem++;
                if (nrElem == 0) {
                    cod = stoi(cuvant, nullptr, 10);
                    produsNou->SetCodProdus(cod);

                    this->_coduriProdus[cod - 100] = cod;

                    cuvant.erase();
                } else if (nrElem == 1) {
                    numeProdus = cuvant;
                    cuvant.erase();
                } else if (nrElem == 2) {
                    cantitateProdus = stoi(cuvant, nullptr, 10);
                    cuvant.erase();
                } else if (nrElem == 3) {
                    pretProdus = stof(cuvant, nullptr);
                    cuvant.erase();
                }
            }
        }

        produsNou->SetNumeProdus(numeProdus);
        produsNou->SetPretProdus(pretProdus);
        produsNou->SetCantitateProdus(cantitateProdus);
        produsNou->SetNext(NULL);
        if (this->_HEAD != NULL) {
            Produs *produsCurent = this->_HEAD;
            while (produsCurent->GetNext() != NULL) {
                produsCurent = produsCurent->GetNext();
            }
            produsCurent->SetNext(produsNou);
        } else {
            this->_HEAD = produsNou;
        }
    }

    fin.close();
}

void Lista::ExportStoc() {
    string src;
    cout << "Introduceti calea catre fisierul catre care se exporta: ";
    cin.clear();
    cin.sync();
    getline(cin, src);
    if(src.empty()) {
        cout << "Nici-o sursa primita\n";
        return;
    }
    ofstream fout(src);
    if (!fout)
        cout << "Eroare la deschiderea fisierului " << src << endl << " Asigurati-va ca fiserul este inchis!\n";

    fout << "Cod produs" << "," << "Denumire produs" << "," << "Cantitate produs" << "," << "Pret produs" << endl;
    Produs *p = this->_HEAD->GetNext();
    while (p != NULL) {
        fout << p->GetCodProdus() << "," << p->GetNumeProdus() << "," << p->GetCantitateProdus() << ","
             << p->GetPretProdus() << endl;
        p = p->GetNext();
    }
    fout.close();
    cout << "\n Fisier exportat cu succes\n";
}

Lista::~Lista() {
    Produs *n = NULL;
    Produs *c = this->_HEAD;
    while (c != NULL) {
        n = c->GetNext();
        delete c;
        c = n;
    }
    _coduriProdus.clear();
}