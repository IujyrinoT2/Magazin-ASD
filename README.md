# Magazin-ASD

## Să se scrie un program care simuleaza un magazine online, folosind ca implementare o lista simplu inlantuita.Fiecare produs din magazin va fi reprezentat printr-un nod in lista pentru care se cunoaste numele produsului,un cod de trei cifre al produsului, pretul pe bucata, numarul de bucati aflate pe stoc. Utilizatorul va trebui sa poata vizualiza toate produsele, sa poata cauta un produs in lista si sa afiseze pentru acest produs toate informatiile,sa poata cumpara un produs (numarul de bucati aflate pe stoc va fi scazut; daca se ajunge la 0 bucati,produsul respective trebuie sters din lista), sa poata introduce un produs in lista (cu toate informatiile).
### De facut:
- [x] void AfisareProduse()
- [x] Produs* CautareProdus(int codProdus)
- [x] void AfisareDetaliiProdus(Produs* produsCautat)
- [x] void CumparareProdus(int codProdus)
- [x] bool ValidareStoc(int cantitateCumparata, Produs* produsCurent)
- [x] void AdaugareProdus()
- [x] void StergeProdus(int codProdus)
- [x] int main() : meniu
### Bonus features:
- Afisare Tabelara
- Import, Export fisiere .csv
