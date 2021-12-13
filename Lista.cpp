#include "Lista.h"

Lista::Lista() {
    this->_HEAD = new Produs;
    this->_coduriProdus = vector<int>(899, 0);
}

void Lista::AdaugaProdus() {
    Produs *produsNou = new Produs;

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

    produsNou->SetCodProdus(GenereazaCodProdus());
    produsNou->SetNumeProdus(numeProdusNou);
    produsNou->SetPretProdus(pretProdusNou);
    produsNou->SetCantitateProdus(cantitateProdusNou);
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
    afisareElement[0][0].format()
            .corner_top_left("*")
            .corner_top_right("*")
            .corner_bottom_left("*")
            .corner_bottom_right("*")
            .corner_top_left_color(Color::red)
            .corner_top_right_color(Color::red)
            .corner_bottom_left_color(Color::red)
            .corner_bottom_right_color(Color::red)
            .font_align(FontAlign::center)
            .font_color(Color::green)
            .border_top("~")
            .border_bottom("~")
            .border_left("|")
            .border_right("|")
            .border_left_color(Color::cyan)
            .border_right_color(Color::cyan)
            .border_top_color(Color::cyan)
            .border_bottom_color(Color::cyan);
    afisareElement[0][1].format()
            .corner_top_left("*")
            .corner_top_right("*")
            .corner_bottom_left("*")
            .corner_bottom_right("*")
            .corner_top_left_color(Color::red)
            .corner_top_right_color(Color::red)
            .corner_bottom_left_color(Color::red)
            .corner_bottom_right_color(Color::red)
            .font_align(FontAlign::center)
            .font_color(Color::green)
            .border_top("~")
            .border_bottom("~")
            .border_left("|")
            .border_right("|")
            .border_left_color(Color::cyan)
            .border_right_color(Color::cyan)
            .border_top_color(Color::cyan)
            .border_bottom_color(Color::cyan);
    afisareElement[0][2].format()
            .corner_top_left("*")
            .corner_top_right("*")
            .corner_bottom_left("*")
            .corner_bottom_right("*")
            .corner_top_left_color(Color::red)
            .corner_top_right_color(Color::red)
            .corner_bottom_left_color(Color::red)
            .corner_bottom_right_color(Color::red)
            .font_align(FontAlign::center)
            .font_color(Color::green)
            .border_top("~")
            .border_bottom("~")
            .border_left("|")
            .border_right("|")
            .border_left_color(Color::cyan)
            .border_right_color(Color::cyan)
            .border_top_color(Color::cyan)
            .border_bottom_color(Color::cyan);
    afisareElement[0][3].format()
            .corner_top_left("*")
            .corner_top_right("*")
            .corner_bottom_left("*")
            .corner_bottom_right("*")
            .corner_top_left_color(Color::red)
            .corner_top_right_color(Color::red)
            .corner_bottom_left_color(Color::red)
            .corner_bottom_right_color(Color::red)
            .font_align(FontAlign::center)
            .font_color(Color::green)
            .border_top("~")
            .border_bottom("~")
            .border_left("|")
            .border_right("|")
            .border_left_color(Color::cyan)
            .border_right_color(Color::cyan)
            .border_top_color(Color::cyan)
            .border_bottom_color(Color::cyan);

    afisareElement.add_row({to_string(produsCautat->GetCodProdus()), produsCautat->GetNumeProdus(),
                            to_string(produsCautat->GetCantitateProdus()), pretProdus});
    afisareElement.format()
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

bool Lista::ValideazaStoc(int cantitateCumparata, Produs *produsCurent) {
    return 0 <= produsCurent->GetCantitateProdus() - cantitateCumparata;
}

void Lista::AfiseazaLista() {
    Table listaProduse;
    listaProduse.add_row(
            {"COD PRODUS", "DENUMIRE PRODUS", "CANTITATE", "PRET"});
    listaProduse[0][0].format()
            .font_style({FontStyle::bold})
            .font_align(FontAlign::center);
    listaProduse[0][1].format()
            .font_style({FontStyle::bold})
            .font_align(FontAlign::center);
    listaProduse[0][2].format()
            .font_style({FontStyle::bold})
            .font_align(FontAlign::center);
    listaProduse[0][3].format()
            .font_style({FontStyle::bold})
            .font_align(FontAlign::center);
    Produs *nodCrt = this->_HEAD->GetNext();
    int counter = 1;
    while (nodCrt != NULL) {
        char codProdus[3];
        char numeProdus[20];
        char cantitateProdus[20];
        char pretProdus[20];
        sprintf(codProdus, "%d", nodCrt->GetCodProdus());
        strcpy(numeProdus, nodCrt->GetNumeProdus().c_str());
        sprintf(cantitateProdus, "%d", nodCrt->GetCantitateProdus());
        sprintf(pretProdus, "%.2f", nodCrt->GetPretProdus());
        listaProduse.add_row({codProdus, numeProdus, cantitateProdus, pretProdus});
        if (nodCrt->GetCantitateProdus() == 0) {
            listaProduse[counter][0].format()
                    .font_style({FontStyle::bold})
                    .font_align(FontAlign::center);
            listaProduse[counter][1].format()
                    .font_style({FontStyle::bold})
                    .font_align(FontAlign::center);
            listaProduse[counter][2].format()
                    .font_style({FontStyle::bold})
                    .font_color(Color::red)
                    .font_align(FontAlign::center);
            listaProduse[counter][3].format()
                    .font_style({FontStyle::bold})
                    .font_align(FontAlign::center);
        } else {
            listaProduse[counter][0].format()
                    .font_style({FontStyle::bold})
                    .font_align(FontAlign::center);
            listaProduse[counter][1].format()
                    .font_style({FontStyle::bold})
                    .font_align(FontAlign::center);
            listaProduse[counter][2].format()
                    .font_style({FontStyle::bold})
                    .font_color(Color::green)
                    .font_align(FontAlign::center);
            listaProduse[counter][3].format()
                    .font_style({FontStyle::bold})
                    .font_align(FontAlign::center);
        }
        nodCrt = nodCrt->GetNext();
        counter++;
    }
    cout << listaProduse << endl;
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

    this->~Lista();
    this->_coduriProdus = vector<int>(899, 0);

    ifstream fin("Stoc.csv");

    if (!fin)
        cout << "Eroare la deschiderea fisierului Stoc.csv\n Asigurati-va ca fiserul este inchis!\n";

    getline(fin, linie);

    while (getline(fin, linie)) {
        Produs *produsNou = new Produs;
        cout << "###Test linie: " << linie << "###\n";

        nrElem = -1;
        for (int i = 0; i < linie.size() + 1; i++) {
            if (linie[i] != ',' && i < linie.size()) {
                cuvant.push_back(linie[i]);
            } else {
                nrElem++;
                if (nrElem == 0) {
                    cod = stoi(cuvant, nullptr, 10);
                    produsNou->SetCodProdus(cod);
                    cout << "\nTest cod: " << cod << endl;
                    cout << "\nTest codString: " << cuvant << endl;

                    this->_coduriProdus[cod - 100] = cod;

                    cuvant.erase();
                } else if (nrElem == 1) {
                    numeProdus = cuvant;
                    cout << "\nTest nume: " << cuvant << endl;
                    cuvant.erase();
                } else if (nrElem == 2) {
                    cantitateProdus = stoi(cuvant, nullptr, 10);
                    cout << "\nTest cantitate:" << cuvant << endl;
                    cuvant.erase();
                } else if (nrElem == 3) {
                    pretProdus = stof(cuvant, nullptr);
                    cout << "\nTest pret:" << cuvant << endl;
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
    ofstream fout("Stoc.csv");
    if (!fout)
        cout << "Eroare la deschiderea fisierului Stoc.csv\n Asigurati-va ca fiserul este inchis!\n";

    fout << "Cod produs" << "," << "Denumire produs" << "," << "Cantitate produs" << "," << "Pret produs" << endl;
    Produs *p = this->_HEAD->GetNext();
    while (p != NULL) {
        fout << p->GetCodProdus() << "," << p->GetNumeProdus() << "," << p->GetCantitateProdus() << ","
             << p->GetPretProdus() << endl;
        p = p->GetNext();
    }
    fout.close();
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