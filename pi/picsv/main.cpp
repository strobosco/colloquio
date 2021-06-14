#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <math.h>
#include <cmath>
#include <fstream>
using namespace std;

int main() {

  // definiamo i possibili valori per i numeri da generare, il range e l'offset
  int numeri[7] = {100, 1000, 5000, 20000, 50000, 1000000, 1000000};
  int range [9] = {10, 50, 100, 500, 1000, 10000, 50000, 100000, 10000000};
  int offset[3] = {100, 500, 1000};

  // definiamo la lunghezza degli array
  int sizeNumeri = sizeof(numeri) / sizeof(numeri[0]);
  int sizeRange = sizeof(range) / sizeof(range[0]);
  int sizeOffset = sizeof(offset) / sizeof(offset[0]);

  // i 3 for permettono di creare file .csv con ogni combinazione di numeri, range e offset
  for (int a = 0; a < sizeNumeri; a++){
    int numeriReal = numeri[a];
    for (int b = 0; b < sizeRange; b++) {
      int rangeReal = range[b];
      for (int c = 0; c < sizeOffset; c++){
        int offsetReal = offset[c];

        // apriamo un ifstream per controllare se la combinazione è già stata calcolata
        ifstream checkFile("./csv/pi" + to_string(numeriReal) + "-" + to_string(rangeReal) + "-" + to_string(offsetReal) + ".csv");

        // se il file esiste non fare niente
        if(checkFile) {
          cout << "";
        // se il file non esiste, calcolare:
        } else {
          // creare il file
          ofstream myFile("./csv/pi" + to_string(numeriReal) + "-" + to_string(rangeReal) + "-" + to_string(offsetReal) + ".csv");
          // inserire i titoli delle colonne
          myFile << "Iterazione" << "," << "Numero\n";

          srand(time(NULL));
          int n;

          // calcolare i numeri necessari
          for(int i = 0; i < numeriReal; i++){
            n = rand() % rangeReal + offsetReal;
            myFile << i + 1 << "," << n << "\n"; // e inserirli nel file .csv
          };

          // chiudere il file .csv
          myFile.close();
        }  
      };
    };
  };
}