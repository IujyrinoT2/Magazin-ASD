#include "Meniu.h"

Meniu::Meniu()
{
    this->_stocProduse = new Lista;
    this->_stocProduse->ImportStoc();
}


void Meniu::Dispatcher()
{
    int userInput = 5000;
    while (userInput)
    {
        cout << "Introduceti numarul actiunii dorite: ";
        cin >> userInput;
        cout << endl;
        switch (userInput)
        {
            case 1: //Adaugare produs
            {
                this->_stocProduse->AdaugaProdus();
                system("cls");
                cout << GenereazaAfisaj() << endl;
            }
                break;
            case 2: //Stergere produs
            {
                int codProdus;
                cout << "Introduceti codul produsului pe care doriti sa il stergeti: " << endl;
                cin >> codProdus;
                this->_stocProduse->StergeProdus(codProdus);
                string continuam;
                do
                {
                    cout << "Continue?(y/n)";
                    cin >> continuam;
                } while (continuam != "y" && continuam != "Y");
                system("cls");
                cout << GenereazaAfisaj() << endl;
            }
                break;
            case 3: //Afisare detalii produs
            {
                int codProdus;
                cout << "Introduceti codul produsului pentru care doriti afisarea detaliilor: " << endl;
                cin >> codProdus;
                this->_stocProduse->AfiseazaProdus(this->_stocProduse->CautaProdus(codProdus));
                string continuam;
                do
                {
                    cout << "Continue?(y/n)";
                    cin >> continuam;
                } while (continuam != "y" && continuam != "Y");
                system("cls");
                cout << GenereazaAfisaj() << endl;
            }
                break;
            case 4: //Cumparare produs
            {
                int codProdus;
                cout << "Introduceti codul produsului pe care doriti sa il achizitionati:  " << endl;
                cin >> codProdus;
                this->_stocProduse->CumparaProdus(codProdus);
                string continuam;
                do
                {
                    cout << "Continue?(y/n)";
                    cin >> continuam;
                } while (continuam != "y" && continuam != "Y");
                system("cls");
                cout << GenereazaAfisaj() << endl;
            }
                break;
                /*   case 5: //Afisare produse
                   {
                       this->_stocProduse->GenereazaLista();
                       cout << endl;
                   }
                       break;
                */
            case 5: //Modificare denumire
            {
                Lista lista;
                int codProdus;
                string denumireProdus;
                cout << "Introduceti codul produsului pe care vreti sa il modificati: ";
                cin >> codProdus;
                cout << endl;
                string numeProdus = lista.ValideazaNume();
                Produs *produsCautat = this->_stocProduse->CautaProdus(codProdus);
                if (produsCautat == NULL)
                {
                    cout << "Eroare: Codul cautat nu a fost gasit." << endl;
                } else
                {
                    this->_stocProduse->CautaProdus(codProdus)->SetNumeProdus(numeProdus);
                    cout << "Produsul a fost actualizat cu succes." << endl;
                }
                string continuam;
                do
                {
                    cout << "Continue?(y/n)";
                    cin >> continuam;
                } while (continuam != "y" && continuam != "Y");
                system("cls");
                cout << GenereazaAfisaj() << endl;
            }
                break;
            case 6: //Modificare cantitate
            {
                Lista lista;
                int codProdus;
                cout << "Introduceti codul produsului pe care vreti sa il modificati: ";
                cin >> codProdus;
                cout << endl;
                int cantitateProdus = lista.ValideazaCantitate();
                Produs *produsCautat = this->_stocProduse->CautaProdus(codProdus);
                if (produsCautat == NULL)
                {
                    cout << "Eroare: Codul cautat nu a fost gasit." << endl;
                } else
                {
                    this->_stocProduse->CautaProdus(codProdus)->SetCantitateProdus(cantitateProdus);
                    cout << "Produsul a fost actualizat cu succes." << endl;
                }
                string continuam;
                do
                {
                    cout << "Continue?(y/n)";
                    cin >> continuam;
                } while (continuam != "y" && continuam != "Y");
                system("cls");
                cout << GenereazaAfisaj() << endl;
            }
                break;
            case 7: //Modificare pret
            {
                Lista lista;
                int codProdus;
                cout << "Introduceti codul produsului pe care vreti sa il modificati: ";
                cin >> codProdus;
                cout << endl;
                float pretProdus = lista.ValideazaPret();
                Produs *produsCautat = this->_stocProduse->CautaProdus(codProdus);
                if (produsCautat == NULL)
                {
                    cout << "Eroare: Codul cautat nu a fost gasit." << endl;
                } else
                {
                    this->_stocProduse->CautaProdus(codProdus)->SetPretProdus(pretProdus);
                    cout << "Produsul a fost actualizat cu succes." << endl;
                }
                string continuam;
                do
                {
                    cout << "Continue?(y/n)";
                    cin >> continuam;
                } while (continuam != "y" && continuam != "Y");
                system("cls");
                cout << GenereazaAfisaj() << endl;
            }
                break;
            case 8: //Importa stoc
            {
                this->_stocProduse->~Lista();
                this->_stocProduse = new Lista;
                this->_stocProduse->ImportStoc();
                system("cls");
                cout << GenereazaAfisaj() << endl;
            }
                break;
            case 9: //Exporta stoc
            {
                this->_stocProduse->ExportStoc();
                system("cls");
                cout << GenereazaAfisaj() << endl;
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

Table Meniu::GenereazaMeniuOptiuni()
{
    Table optiuni;
    optiuni.format().hide_border().font_align(FontAlign::left);
    optiuni.add_row({"OPTIUNI:"});
    optiuni.add_row({"1. Adaugare un produs"});
    optiuni.add_row({"2. Stergere un produs"});
    optiuni.add_row({"3. Afisare detalii pentru un produs"});
    optiuni.add_row({"4. Cumparare un produs"});
    optiuni.add_row({"5. Modificare denumire produs"});
    optiuni.add_row({"6. Modificare cantitate produs"});
    optiuni.add_row({"7. Modificare pret produs"});
    optiuni.add_row({"8. Importa produse"});
    optiuni.add_row({"9. Exporta stoc"});
    optiuni.add_row({"0. Iesire din program"});
    return optiuni;
}

Meniu::~Meniu()
{
    delete this->_stocProduse;
}

Table Meniu::GenereazaAfisaj()
{
    Table AFISAJ;
    AFISAJ.add_row({GenereazaMeniuOptiuni(), this->_stocProduse->GenereazaLista()});
    return AFISAJ;
}

