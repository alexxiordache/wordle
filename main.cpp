#include <fstream>
#include <random>
#include <time.h>
#include <stdio.h>
#include <cstring>
#include <iostream>

using namespace std;
int n, right_idx;
char arr[11063][6];
#define RED "31"
#define GREEN "32"
#define YELLOW "33"   

void print(const char *s, char* culoare="37") { // alb
    printf("\033[1;%sm%s\033[0m", culoare, s);
}

void citire_cuvinte(const char* file) {
    ifstream fin(file);
    char s[6];
    while(fin >> s) {
        strncpy(arr[n++], s, 5);
        s[5] = 0;
    }
}

bool exista(char s[]) {
    int st = 0, dr = n - 1;
    while(st <= dr) {
        int mij = (st + dr) / 2;
        if(!strcmp(arr[mij], s))
            return true;
        if(strcmp(arr[mij], s) < 0)
            st = mij + 1;
        else dr = mij - 1;
    } 
    return false;
}

char verif_cuv(char *s) {
    // mai intai verific daca e unul pus bine, ca sa pot verifica ulterior daca trebuie sa mai fac ceva galben
    // daca aceeasi litera este introdusa de 2 ori intr-un cuvant, mai intai pe pozitia gresita
    // si dupa pe cea corecta, va face galbena prima aparitie si verde pe ultima, chiar daca in cuvantul corect exista doar o data
    // trebuie facuta galbena doar daca mai apare pe o alta pozitie
    bool guessed[6]={0};
    for(int i = 0; i < 5; i++)
        if(s[i] == arr[right_idx][i])
            guessed[i] = true;
    for(int i = 0; i < 5; i++) {
        char *col = RED;
        if(guessed[i])
            col = GREEN;
        else 
            for(int j = 0; j < 5; j++)
                if(arr[right_idx][j] == s[i] && !guessed[j])
                    col = YELLOW;
        char buffer[1];
        buffer[0] = s[i];
        print(buffer, col);
    }
    print("\n");
}

int main() {
    char s[256], buffer[256];
    srand(time(NULL));
    citire_cuvinte("words.txt");
    right_idx = rand() % n;
    // print(arr[right_idx], YELLOW);
    print("Introdu un cuvant de 5 litere\n", RED);
    int attempts = 0;
    char attempts_arr[6][6];
    while(attempts < 6) {
        cin.getline(s, 256);
        if(strlen(s) != 5)
        {
            print("Dimensiune gresita. Cuvantul trebuie sa aiba 5 litere.\n", RED);
            continue;
        }
        for(int i = 0; i < 5; i++)
            if(islower(s[i]))
                s[i] -= 32;
        bool found = false;
        for(int i = 0; i < attempts; i++)
            if(!strcmp(s, attempts_arr[i]))
            {
                print("Ai incercat deja acest cuvant.\n", RED);
                found = true;
                break;
            }
        if(found)
            continue;

        if(!exista(s)) {
            print("Cuvantul nu exista\n", RED);
            continue;
        }

        if(!strcmp(s, arr[right_idx])) {
            sprintf(buffer, "Ai ghicit cuvantul dupa %d incercari.", attempts);
            print(buffer, GREEN);
            return 0;
        }
        verif_cuv(s);
        strcpy(attempts_arr[attempts++], s);
            
    }
    sprintf(buffer, "Nu ai ghicit cuvantul. Acesta era %s\n", arr[right_idx]);
    print(buffer, RED);
    
}