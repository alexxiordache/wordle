# Wordle in Romana

Acest proiect reprezinta o implementare a popularului joc Wordle, scrisa in C++.

## Descriere
Scopul jocului este de a ghici un cuvant ascuns din 5 litere. Jucatorul are la dispozitie 6 incercari pentru a gasi cuvantul secret.
Dupa fiecare incercare, veti primi indicii pentru fiecare litera introdusa, pentru a vedea cat de aproape sunteti de solutia corecta.

Cuvintele valide pentru joc sunt preluate din fisierul `words.txt`, care contine un dictionar format din lista cuvintelor de litere in limba romana.

## Cum se ruleaza
Fisierul sursa este scris in C++. Pentru a il rula aveti nevoie de un compilator (precum g++ din GCC).

1. Deschideti terminalul.
2. Compilati codul sursa:
   ```bash
   g++ main.cpp -o wordle
3. Rulati fisierul
```bash
./wordle