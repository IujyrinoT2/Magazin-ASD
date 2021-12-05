# Magazin-ASD

## Să se scrie un program care simuleaza un magazine online, folosind ca implementare o lista simplu inlantuita.Fiecare produs din magazin va fi reprezentat printr-un nod in lista pentru care se cunoaste numele produsului,un cod de trei cifre al produsului, pretul pe bucata, numarul de bucati aflate pe stoc. Utilizatorul va trebui sa poata vizualiza toate produsele, sa poata cauta un produs in lista si sa afiseze pentru acest produs toate informatiile,sa poata cumpara un produs (numarul de bucati aflate pe stoc va fi scazut; daca se ajunge la 0 bucati,produsul respective trebuie sters din lista), sa poata introduce un produs in lista (cu toate informatiile).
De facut:
- [ ] void AfisareProduse()
- [ ] Produs* CautareProdus(int codProdus)
- [ ] void AfisareDetaliiProdus(Produs* produsCautat)
- [ ] void CumparareProdus(int codProdus)
- [ ] bool ValidareStoc(int cantitateCumparata, Produs* produsCurent)
- [ ] void AdaugareProdus()
- [ ] void StergeProdus(int codProdus)
- [ ] int main() : meniu
