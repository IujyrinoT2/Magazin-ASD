#include "Lista.h"


Lista::Lista()
{
    this->_HEAD = new Produs;
    this->_coduriProdus = vector<int>(899, 0);
}

void Lista::AdaugaProdus()
{
    string numeProdusNou = ValideazaNume();
    int cantitateProdusNou = ValideazaCantitate();
    float pretProdusNou = ValideazaPret();


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
    bool codOK=true,
    numeOK =true ,
    pretOK = true,
    cantitateOK = true;
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
                    try
                    {
                        cod = stoi(cuvant);
                        if(cod <100 || cod>999)
                        {
                            cout<<"Codul a avut prea multe sau prea putine cifre"<<endl;
                            codOK = false;
                        }else
                        {
                            produsNou->SetCodProdus(cod);
                            this->_coduriProdus[cod - 100] = cod;
                        }
                    }
                    catch(...)
                    {
                        cout<<"Codul nu a fost format doar din cifre"<<endl;
                        codOK = false;
                    }

                    cuvant.erase();
                } else if (nrElem == 1) {
                    numeProdus = cuvant;
                    if(numeProdus.size() > 255){
                        cout<<"Numele produsului a fost prea mare"<<endl;
                        numeOK= false;
                    }
                    cuvant.erase();
                } else if (nrElem == 2) {
                    try
                    {
                        cantitateProdus = stoi(cuvant, nullptr, 10);
                        if(cantitateProdus < 0){
                            cout<<"Cantitatea produsului nu poate fi negativa"<<endl;
                            cantitateOK= false;
                        }
                    }
                    catch (...)
                    {
                        cout<<"Cantitatea trebuie sa fie formata doar din cifre"<<endl;
                        cantitateOK = false;
                    }
                    cuvant.erase();
                } else if (nrElem == 3) {
                    try
                    {
                        pretProdus = stof(cuvant);
                        if(pretProdus < 0){
                            cout<<"Pretul nu poate fi negativ"<<endl;
                            pretOK = false;
                        }
                    }
                    catch (...)
                    {
                        cout<<"Pretul trebuie sa fie format doar din cifre"<<endl;
                        pretOK = false;
                    }
                    cuvant.erase();
                }
            }
        }
        if(codOK !=true || numeOK != true || cantitateOK != true || pretOK != true)
        {
            codOK=true;
            numeOK =true;
            pretOK = true;
            cantitateOK = true;
        }
        else{
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


string Lista::ValideazaNume()
{
    string numeProdus;
    cout<<"Introduceti numele produsului :";
    cin.clear();
    cin.sync();
    getline(cin,numeProdus);
    cout<<endl;
    if(numeProdus.size()>255){
        cout<<"Numele este invalid !"<<endl;
        ValideazaNume();
    }
    return numeProdus;


}

int Lista::ValideazaCantitate()
{
    string cantitateProdus;
    cout<<"Cantitatea produsului este: ";
    cin>>cantitateProdus;
    cout<<endl;
    int aux = TryGetCantitate(cantitateProdus);
    if(aux < 0)
    {
         cout<<"Cantitate nu poate fi negativa !"<<endl;
         return ValideazaCantitate();
    }
    return aux;
}

int Lista::TryGetCantitate(string cantitateProdus) {
    try
    {
        return stoi(cantitateProdus);
    }
    catch(...)
    {
        cout<<"Cantitatea nu poate fi formata din litere sau este prea mare !"<<endl;
        return ValideazaCantitate();
    }
}

float Lista::ValideazaPret()
{
    string pretProdus;
    cout<<"Pretul produsului este: ";
    cin>>pretProdus;
    cout<<endl;
    int aux = TryGetPret(pretProdus);
    if(aux < 0)
    {
        cout<<"Pretul nu poate fi negativ !"<<endl;
        return ValideazaPret();
    }
    return aux;
}

float Lista::TryGetPret(string pretProdus) {
    try
    {
        return stof(pretProdus);
    }
    catch(...)
    {
        cout<<"Pretul nu poate fi format din litere sau este prea mare !"<<endl;
        return ValideazaPret();
    }
}


Lista::~Lista() 
{
    Produs *n = NULL;
    Produs *c = this->_HEAD;
    while (c != NULL) 
    {
        n = c->GetNext();
        delete c;
        c = n;
    }
    _coduriProdus.clear();
}