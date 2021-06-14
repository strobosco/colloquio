#include <iostream>
#include <stdio.h>    
#include <math.h> 
#include <iomanip>

// Definizione costante PI,
// utilizzata per convertire l'argomento
// della funzione cos() in radianti
#define PI 3.14159265

// Definizioni costanti calcolate nella risposta
// al quesito numero 4, in seguito alla definizione
// dell'equazione 4
#define omega 1.535e10
#define k 51.166
#define Eeff 6.137
#define c 3e8

using namespace std;

// Definizione della funzione integranda
double f(double t){
	return Eeff * cos(((k * t * c) - (omega * t)) * PI / 180.0) + Eeff;
}   

// Definizione funzione del metodo di Cavalieri-Simpson
double cavalieriSimpson(double a, double b, int n){
	double h, s, sum, x;
  int j;

	h = (b - a) / n;
	s = h / 2;
	sum = f(a) + f(b) + 4 * f(a + s);
	x = a + h;

	for(j = 1; j < n; j++){
		sum = sum + 2 * f(x) + 4 * f(x + s);
		x += h;
	}
	return sum * (h / 6);
}

// Funzione main che verrà usata dal compilatore
// come punto d'ingresso 
int main(int argc, char** argv) {

	// variabili che corrispondono all'estremo
	// inferiore (a) e all'estremo superiore (b)
	double a, b;
	cout << endl;
	cout << "Inserire i seguenti dati:" << endl << endl;
	cout << "Inserire limite a dell'integrale: ";
	cin >> a;
	cout << endl;
	cout << "\nInserire limite b dell'intergale: ";
	cin >> b;
	cout << endl;	

	// Costanti che verranno usate per rendere la tabella finale ordinata
	const char separator = ' '; // Separatore tra le caselle
  const int wordWidth = 18; // Larghezza di ogni casella contente una stringa (testo)
	const int width = 18; // Larghezza di ogni casella contente un numero (int/double)

	// Definizione array che contiene gil intervalli che verranno usati
	int n[7] = {10, 50, 100, 500, 1000, 5000, 10000};

	// Stampa della tabella
	// Intestazione
	cout << "I risultati ottenuti sono i seguenti:" << endl << endl;
  cout << left << setw(wordWidth) << setfill(separator) << "Intervalli"; // Iterazioni svolte
  cout << left << setw(wordWidth) << setfill(separator) << "Valore approssimato"; // Math.sqrt()
  cout << endl;

	// Risultati
	for (int i = 0; i < 7; i++) {
		cout << left << setw(width) << setfill(separator) << n[i];
		cout << left << setw(width) << setfill(separator) << cavalieriSimpson(a, b, n[i]);
		cout << endl;
	}

	return 0;
}