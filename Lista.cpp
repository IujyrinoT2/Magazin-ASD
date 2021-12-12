#include "Lista.h"

Lista::Lista()
{
    this->_HEAD = new Produs;
    this->_vectcodProd = vector(899, 0);
}

Produs *Lista::GetHead()
{
    return this->_HEAD;
}

void Lista::SetHead(Produs *noulHead)
{
    this->_HEAD = noulHead;
}

void Lista::AdaugaProdus()
{  //poate fi un produs nou sau unul existent caz in care creste valoarea stocului
    int optiune;
    int codNou;
    string numeProdusNou;
    float pretProdusNou;
    int cantitateProdusNou;

    cout << "Pentru adaugare produs nou, apasati tasta 1." << endl;
    cout << "Pentru un produs deja existent apasati tasta 2." << endl;
    cin >> optiune;
    Produs *p = new Produs;
    if (optiune == 1)
    {
        //generam codProdusNou pe baza listei de coduri vectcodProd
        for (int i = 0; i <= 899; i++)
        {
            if (this->_vectcodProd[i] == 0)
            {
                this->_vectcodProd[i] = i + 100;
                codNou = this->_vectcodProd[i];
                p->SetCodProdus(codNou);
                break;
            }
        }
        //Citim numeProdus, pretProdus, cantitateProdus
        cout << "Introudceti numele produsului: " << endl;
        cin >> numeProdusNou;
        p->SetNumeProdus(numeProdusNou);
        cout << "Introudceti pretul produsului: " << endl;
        cin >> pretProdusNou;
        p->SetPretProdus(pretProdusNou);
        cout << "Introudceti cantitatea produsului: " << endl;
        cin >> cantitateProdusNou;
        p->SetCantitateProdus(cantitateProdusNou);
        if (this->_HEAD == nullptr)
        {
            this->_HEAD = p;
            p->SetNext(nullptr);
            cout << endl << "Noul produs a fost adaugat cu succes! ";
            return;
        }
        p->SetNext(this->_HEAD);
        this->_HEAD = p;
        cout << endl << "Noul produs a fost adaugat cu succes! ";
        return;
    } else if (optiune == 2)
    {
        //aici actualizam stocul unui produs existen
        //utilizatorul trebuie sa vada lista cu produse deja existente / check sa nu fie goala
        //alege un cod - este verificat daca exista in lista si apoi se actualizeaza stocul
        return;
    }
    cout << "Optiune invalida." << endl;
    return;
}

void Lista::StergeProdus(int codProdus)
{
    Produs *p = CautaProdus(codProdus);

    if (p == nullptr)
    {                                              //  Cand nu s-a gasit produsul, functia se opreste
        cout << "Produsul nu s-a gasit";
        return;
    }

    Produs *p_aux = p;

    if (this->_HEAD == p)
    {                                                 // Stergerea cand produsul este primul element
        p = p->GetNext();
        this->_HEAD = p;
        delete p_aux;
        return;
    }

    int codProdusAnterior = codProdus - 1;
    while ((p = CautaProdus(codProdusAnterior)) ==
           nullptr)       // Gasirea produsului anterior care are cod valid in caz
        codProdusAnterior--;                                      // ca au mai fost facute stergeri
    p->SetNext(p->GetNext()->GetNext());                           // Stergerea produsului in celelalte cazuri
    delete p_aux;                                                  // si refacearea legaturilor
}

void Lista::AfiseazaProdus(Produs *produsCautat)
{
    if (produsCautat == nullptr)
    {
        return;
    }
    //Continutul liniei VV
    Table afisareElement;
    char codProdus[3];
    char numeProdus[20];
    char cantitateProdus[20];
    char pretProdus[20];
    itoa(produsCautat->GetCodProdus(), codProdus, 10);
    strcpy(numeProdus, produsCautat->GetNumeProdus().c_str());
    itoa(produsCautat->GetCantitateProdus(), cantitateProdus, 10);
    sprintf(pretProdus, "%.2f", produsCautat->GetPretProdus());
    afisareElement.add_row({"COD PRODUS", "DENUMIRE PRODUS", "CANTITATE", "PRET"});
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

void Lista::CumparaProdus(int codProdus)
{
    Produs *p = CautaProdus(codProdus);
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
    if (!ValideazaStoc(cantitateCumparata, CautaProdus(codProdus)))
    {
        cout << "Stoc insuficient" << endl;
        return;
    }
    // Vom scadea cantitatea produsului cu cantitatea cumparata
    p->SetCantitateProdus(p->GetCantitateProdus() - cantitateCumparata);
    // Verificam daca stocul ajunge la 0, daca da, chemam StergeProdus(int codProdus)
    if (!p->GetCantitateProdus())
        StergeProdus(codProdus);
}

Produs *Lista::CautaProdus(int codCautat)
{
    Produs *cod = this->_HEAD;
    if (this->_HEAD == nullptr)
    {
        std::cout << "Nu exista produse pe stoc" << std::endl;
        return nullptr;
    }
    while (cod->GetNext() != NULL && cod->GetCodProdus() != codCautat)
    {
        cod = cod->GetNext();
    }
    if (cod->GetNext() == NULL && cod->GetCodProdus() != codCautat)
    {
        std::cout << "Codul cautat nu a fost gasit" << std::endl;
        return nullptr;
    }
    return cod;
}

bool Lista::ValideazaStoc(int cantitateCumparata, Produs *produsCurent)
{
  return true;
}

void Lista::AfiseazaLista()
{
    Table listaProduse;
    listaProduse.add_row({"COD PRODUS", "DENUMIRE PRODUS", "CANTITATE", "PRET"});
    listaProduse[0][0].format()
            .corner_top_left("*")
            .corner_top_right("*")
            .corner_top_left_color(Color::red)
            .corner_top_right_color(Color::red)
            .font_style({FontStyle::bold})
            .font_color(Color::green)
            .font_align(FontAlign::center)
            .border_top("~")
            .border_bottom("~")
            .border_left("|")
            .border_right("|")
            .border_left_color(Color::cyan)
            .border_right_color(Color::cyan)
            .border_top_color(Color::cyan)
            .border_bottom_color(Color::cyan);
    listaProduse[0][1].format()
            .corner_top_left("*")
            .corner_top_right("*")
            .corner_top_left_color(Color::red)
            .corner_top_right_color(Color::red)
            .font_style({FontStyle::bold})
            .font_color(Color::green)
            .font_align(FontAlign::center)
            .border_top("~")
            .border_bottom("~")
            .border_left("|")
            .border_right("|")
            .border_left_color(Color::cyan)
            .border_right_color(Color::cyan)
            .border_top_color(Color::cyan)
            .border_bottom_color(Color::cyan);
    listaProduse[0][2].format()
            .corner_top_left("*")
            .corner_top_right("*")
            .corner_top_left_color(Color::red)
            .corner_top_right_color(Color::red)
            .font_style({FontStyle::bold})
            .font_color(Color::green)
            .font_align(FontAlign::center)
            .border_top("~")
            .border_bottom("~")
            .border_left("|")
            .border_right("|")
            .border_left_color(Color::cyan)
            .border_right_color(Color::cyan)
            .border_top_color(Color::cyan)
            .border_bottom_color(Color::cyan);
    listaProduse[0][3].format()
            .corner_top_left("*")
            .corner_top_right("*")
            .corner_top_left_color(Color::red)
            .corner_top_right_color(Color::red)
            .font_style({FontStyle::bold})
            .font_color(Color::green)
            .font_align(FontAlign::center)
            .border_top("~")
            .border_bottom("~")
            .border_left("|")
            .border_right("|")
            .border_left_color(Color::cyan)
            .border_right_color(Color::cyan)
            .border_top_color(Color::cyan)
            .border_bottom_color(Color::cyan);
    Produs *nodCrt = this->_HEAD;
    int counter = 1;
    while (nodCrt != NULL)
    {
        char codProdus[3];
        char numeProdus[20];
        char cantitateProdus[20];
        char pretProdus[20];
        itoa(nodCrt->GetCodProdus(), codProdus, 10);
        strcpy(numeProdus, nodCrt->GetNumeProdus().c_str());
        itoa(nodCrt->GetCantitateProdus(), cantitateProdus, 10);
        sprintf(pretProdus, "%.2f", nodCrt->GetPretProdus());
        listaProduse.add_row({codProdus, numeProdus, cantitateProdus, pretProdus});
        if (nodCrt->GetCantitateProdus() == 0)
        {
            listaProduse[counter][0].format()
                    .font_style({FontStyle::crossed})
                    .font_color(Color::red)
                    .corner_top_left("*")
                    .corner_top_right("*")
                    .corner_bottom_left("*")
                    .corner_bottom_right("*")
                    .corner_top_left_color(Color::red)
                    .corner_top_right_color(Color::red)
                    .corner_bottom_left_color(Color::red)
                    .corner_bottom_right_color(Color::red)
                    .font_align(FontAlign::center)
                    .border_top("~")
                    .border_bottom("~")
                    .border_left("|")
                    .border_right("|")
                    .border_left_color(Color::red)
                    .border_right_color(Color::red)
                    .border_top_color(Color::cyan)
                    .border_bottom_color(Color::cyan);
            listaProduse[counter][1].format()
                    .font_style({FontStyle::crossed})
                    .font_color(Color::red)
                    .corner_top_left("*")
                    .corner_top_right("*")
                    .corner_bottom_left("*")
                    .corner_bottom_right("*")
                    .corner_top_left_color(Color::red)
                    .corner_top_right_color(Color::red)
                    .corner_bottom_left_color(Color::red)
                    .corner_bottom_right_color(Color::red)
                    .font_align(FontAlign::center)
                    .border_top("~")
                    .border_bottom("~")
                    .border_left("|")
                    .border_right("|")
                    .border_left_color(Color::red)
                    .border_right_color(Color::red)
                    .border_top_color(Color::cyan)
                    .border_bottom_color(Color::cyan);
            listaProduse[counter][2].format()
                    .font_style({FontStyle::crossed})
                    .font_color(Color::red)
                    .corner_top_left("*")
                    .corner_top_right("*")
                    .corner_bottom_left("*")
                    .corner_bottom_right("*")
                    .corner_top_left_color(Color::red)
                    .corner_top_right_color(Color::red)
                    .corner_bottom_left_color(Color::red)
                    .corner_bottom_right_color(Color::red)
                    .font_align(FontAlign::center)
                    .border_top("~")
                    .border_bottom("~")
                    .border_left("|")
                    .border_right("|")
                    .border_left_color(Color::red)
                    .border_right_color(Color::red)
                    .border_top_color(Color::cyan)
                    .border_bottom_color(Color::cyan);
            listaProduse[counter][3].format()
                    .font_style({FontStyle::crossed})
                    .font_color(Color::red)
                    .corner_top_left("*")
                    .corner_top_right("*")
                    .corner_bottom_left("*")
                    .corner_bottom_right("*")
                    .corner_top_left_color(Color::red)
                    .corner_top_right_color(Color::red)
                    .corner_bottom_left_color(Color::red)
                    .corner_bottom_right_color(Color::red)
                    .font_align(FontAlign::center)
                    .border_top("~")
                    .border_bottom("~")
                    .border_left("|")
                    .border_right("|")
                    .border_left_color(Color::red)
                    .border_right_color(Color::red)
                    .border_top_color(Color::cyan)
                    .border_bottom_color(Color::cyan);
        } else
        {
            listaProduse[counter][0].format()
                    .font_color(Color::cyan)
                    .corner_top_left("*")
                    .corner_top_right("*")
                    .corner_bottom_left("*")
                    .corner_bottom_right("*")
                    .corner_top_left_color(Color::red)
                    .corner_top_right_color(Color::red)
                    .corner_bottom_left_color(Color::red)
                    .corner_bottom_right_color(Color::red)
                    .font_align(FontAlign::center)
                    .border_top("~")
                    .border_bottom("~")
                    .border_left("|")
                    .border_right("|")
                    .border_left_color(Color::cyan)
                    .border_right_color(Color::cyan)
                    .border_top_color(Color::cyan)
                    .border_bottom_color(Color::cyan);
            listaProduse[counter][1].format()
                    .font_color(Color::cyan)
                    .corner_top_left("*")
                    .corner_top_right("*")
                    .corner_bottom_left("*")
                    .corner_bottom_right("*")
                    .corner_top_left_color(Color::red)
                    .corner_top_right_color(Color::red)
                    .corner_bottom_left_color(Color::red)
                    .corner_bottom_right_color(Color::red)
                    .font_align(FontAlign::center)
                    .border_top("~")
                    .border_bottom("~")
                    .border_left("|")
                    .border_right("|")
                    .border_left_color(Color::cyan)
                    .border_right_color(Color::cyan)
                    .border_top_color(Color::cyan)
                    .border_bottom_color(Color::cyan);
            listaProduse[counter][2].format()
                    .font_color(Color::cyan)
                    .corner_top_left("*")
                    .corner_top_right("*")
                    .corner_bottom_left("*")
                    .corner_bottom_right("*")
                    .corner_top_left_color(Color::red)
                    .corner_top_right_color(Color::red)
                    .corner_bottom_left_color(Color::red)
                    .corner_bottom_right_color(Color::red)
                    .font_align(FontAlign::center)
                    .border_top("~")
                    .border_bottom("~")
                    .border_left("|")
                    .border_right("|")
                    .border_left_color(Color::cyan)
                    .border_right_color(Color::cyan)
                    .border_top_color(Color::cyan)
                    .border_bottom_color(Color::cyan);
            listaProduse[counter][3].format()
                    .font_color(Color::cyan)
                    .corner_top_left("*")
                    .corner_top_right("*")
                    .corner_bottom_left("*")
                    .corner_bottom_right("*")
                    .corner_top_left_color(Color::red)
                    .corner_top_right_color(Color::red)
                    .corner_bottom_left_color(Color::red)
                    .corner_bottom_right_color(Color::red)
                    .font_align(FontAlign::center)
                    .border_top("~")
                    .border_bottom("~")
                    .border_left("|")
                    .border_right("|")
                    .border_left_color(Color::cyan)
                    .border_right_color(Color::cyan)
                    .border_top_color(Color::cyan)
                    .border_bottom_color(Color::cyan);
        }
        nodCrt = nodCrt->GetNext();
        counter++;
    }
    cout << listaProduse << endl;
}