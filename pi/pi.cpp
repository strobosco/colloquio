#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <cmath>
using namespace std;

//#define _USE_MATH_DEFINES
#define PI 3.14159265
#define N 10

void archimede(int latiMax){

    double raggio = 1.0;
    double lati = 6;

    cout << "Approssimazione usando il metodo di Archimede\n--------------------------------------------" << endl;
    cout << left << setw(18) << "Numero Lati" << "   |   " << setw(28) << "Valore appossimato" << endl;
    while(lati < latiMax) {
        cout << left << setw(18) << setprecision(18) << lati << "   |   " << setw(18) << setprecision(18) << lati*raggio/2.0 << endl;

        double h = raggio / 2.0;
        double z = sqrt(1.0 - h * h);
        raggio = sqrt(h * h + (1.0 - z) * (1.0 - z));
        lati *= 2;
    }
    
}

void ArchimedeProf() {
	
	int lati;
	
    cout << "\nInserisci il numero di lati del poligono regolare: " << endl;
	cin >> lati;

	double alfa = 180/lati;
    double result = (PI*alfa) / 180;
	double pigreco = lati*sin(result);

    cout << "Il pigreco vale: " << pigreco << endl;
	

}

void monteCarlo(int tanti) {

    int conta, dentro;
    float n, x, y, pi;
    cout.precision(20);

    dentro = 0;

    srand(time(NULL));
    for(conta = 0; conta < tanti; conta++) {

        n = rand();
        x = ((double)n) / RAND_MAX;

        n = rand();
        y = ((double)n) / RAND_MAX;

        if((x * x + y * y) < 1) {
            dentro++;
        }

    }

    pi = (4 * dentro) / (double)tanti;

    cout << "\nApprossimazione utilizzando il metodo Monte Carlo:\n---------------------------" << endl;
    cout << "Pigreco: " << pi << endl;
    cout << "Numeri generati: " << tanti << endl;

}

int main() {
    
    int lati, tanti;

    cout << "Inserire lati massimi della figura: ";
    cin >> lati;

    archimede(lati);

    cout << "\nUtilizzando il metodo della prof:" << endl;
    ArchimedeProf();

    cout << "\nQuanti numeri vuoi generare? ";
    cin >> tanti;
    monteCarlo(tanti);

}