#include "Meniu.h"

Meniu::Meniu()
{
  this->_stocProduse = new Lista;
}

void Meniu::AfisareMeniu()
{
    int userInput=5000;
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
                cout << endl;
            }
                break;
            case 2: //Stergere produs
            {
                int codProdus;
                cout << "Introduceti codul produsului pe care doriti sa il stergeti: " << endl;
                cin >> codProdus;
                this->_stocProduse->StergeProdus(codProdus);
                cout << endl;
            }
                break;
            case 3: //Afisare detalii produs
            {
                int codProdus;
                cout << "Introduceti codul produsului pentru care doriti afisarea detaliilor: " << endl;
                cin >> codProdus;
                this->_stocProduse->AfiseazaProdus(this->_stocProduse->CautaProdus(codProdus));
                cout << endl;
            }
                break;
            case 4: //Cumparare produs
            {
                int codProdus;
                cout << "Introduceti codul produsului pe care doriti sa il achizitionati:  " << endl;
                cin >> codProdus;
                this->_stocProduse->CumparaProdus(codProdus);
                cout << endl;
            }
                break;
            case 5: //Afisare produse
            { ;
                this->_stocProduse->AfiseazaLista();
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