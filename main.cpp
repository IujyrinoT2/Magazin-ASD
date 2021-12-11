#include "Produs.h"

Produs *HEAD; // Va pointa catre capul de lista
int codProdusCounter = 1; // Pe asta il vom incrementa inainte sa adaugam un produs nou si il vom asigna catre codProdus pentru produsul nou.

//generam un vector cu 999 pozitii pentru toate codurile de produs de 3 cifre pe care le putem genere 
const int n = 899;
vector<int> vectcodProd(n, 0);

void AdaugareProdus()
{  //poate fi un produs nou sau unul existent caz in care creste valoarea stocului
    int optiune;
    int codNou;
    string numeProdusNou;
    double pretProdusNou;
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
            if (vectcodProd[i] == 0)
            {
                vectcodProd[i] = i + 100;
                codNou = vectcodProd[i];
                p->codProdus = codNou;
                break;
            }
        }
        //Citim numeProdus, pretProdus, cantitateProdus
        cout << "Introudceti numele produsului: " << endl;
        cin >> numeProdusNou;
        p->numeProdus = numeProdusNou;
        cout << "Introudceti pretul produsului: " << endl;
        cin >> pretProdusNou;
        p->pretProdus = pretProdusNou;
        cout << "Introudceti cantitatea produsului: " << endl;
        cin >> cantitateProdusNou;
        p->cantitateProdus = cantitateProdusNou;
        if (HEAD == nullptr)
        {
            HEAD = p;
            p->next = nullptr;
            cout << endl << "Noul produs a fost adaugat cu succes! ";
            return;
        }
        p->next = HEAD;
        HEAD = p;
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
    char numeProdus[20];
    char cantitateProdus[20];
    char pretProdus[20];
    itoa(produsCautat->codProdus, codProdus, 10);
    strcpy(numeProdus, produsCautat->numeProdus.c_str());
    itoa(produsCautat->cantitateProdus, cantitateProdus, 10);
    sprintf(pretProdus, "%.2f", produsCautat->pretProdus);
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

void AfisareProduse()
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
    Produs *nodCrt = HEAD;
    int counter = 1;
    while (nodCrt != NULL)
    {
        char codProdus[3];
        char numeProdus[20];
        char cantitateProdus[20];
        char pretProdus[20];
        itoa(nodCrt->codProdus, codProdus, 10);
        strcpy(numeProdus, nodCrt->numeProdus.c_str());
        itoa(nodCrt->cantitateProdus, cantitateProdus, 10);
        sprintf(pretProdus, "%.2f", nodCrt->pretProdus);
        listaProduse.add_row({codProdus, numeProdus, cantitateProdus, pretProdus});
        if (nodCrt->cantitateProdus == 0)
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
        nodCrt = nodCrt->next;
        counter++;
    }

    cout << listaProduse << endl;
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
                cin >> codProdus;
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
    tabelMeniu.add_row({"ID", "OPTIUNE"});
    tabelMeniu.add_row({"1", "Adaugare un produs"});
    tabelMeniu.add_row({"2", "Stergere un produs"});
    tabelMeniu.add_row({"3", "Afisare detalii pentru un produs"});
    tabelMeniu.add_row({"4", "Cumparare un produs"});
    tabelMeniu.add_row({"5", "Afisare lista produse"});
    tabelMeniu.add_row({"0", "Iesire din program"});
    tabelMeniu[0].format()
            .font_color(Color::green)
            .font_align(FontAlign::center)
            .border_top("~")
            .border_bottom("~")
            .border_left("|")
            .border_right("|")
            .border_left_color(Color::cyan)
            .border_right_color(Color::cyan)
            .border_top_color(Color::cyan)
            .border_bottom_color(Color::cyan)
            .corner_top_left("*")
            .corner_top_right("*")
            .corner_bottom_left("*")
            .corner_bottom_right("*")
            .corner_top_left_color(Color::red)
            .corner_top_right_color(Color::red)
            .corner_bottom_left_color(Color::red)
            .corner_bottom_right_color(Color::red);
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
    AfisareMeniu();
    return 0;
}
