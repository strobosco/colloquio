## Nomenclatura immagini

Le immagini hanno la seguente nomenclatura:

```pi<NUMERI GENERATI><RANGE><OFFSET>.png ```

- Numeri Generati: 100, 1000, 5000, 20000, 50000, 1000000, 1000000
- Range: 10, 50, 100, 500, 1000, 10000, 50000, 100000
- Offset: 100, 500, 1000

## Calcolo

Per ogni campo sono state calcolate tutte le possibili combinazioni. Osservando le immagini con oltre 20000 numeri risulta che il range è troppo ristretto per consentire una dispersione adeguata. Usando un range più ampio è probabile che i numeri si sarebbero dispersi in maggiore quantità. Questo è evidente nei casi in cui il range è ristretto poiché si sono create delle linee orizzontali che occupano tutta la larghezza del grafico.

## Struttura

```
Numeri pseudo-casuali
  +-- img // cartella contenente le immagini .png
  |   |   ...
  |    
  +-- csv // cartella contenente i file .csv (Comma-Separated-Values)
  |   |   ...
  |    
  +-- main.cpp // file C++ usato per creare i file .csv
  +-- main.exe // .exe del file main.cpp
  +-- plot.py // file Python usato per creare e salvare i grafici .png

```