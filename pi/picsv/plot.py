import csv
import os
from matplotlib.pyplot import figure
import numpy as np
import matplotlib.pylab as plt
  
# definiamo i possibili valori per i numeri da generare, il range e l'offset
numeri= [100, 1000, 5000, 20000, 50000, 1000000, 1000000];
range = [10, 50, 100, 500, 1000, 10000, 50000, 100000, 10000000];
offset = [100, 500, 1000];

# iterazione su tutti i possibili valori
for n in numeri:
  nReal = n
  for r in range:
    rReal = r
    for o in offset:
      oReal = o

      # definiamo il nome del file
      fileName = "pi" + str(nReal) + "-" + str(rReal) + "-" + str(oReal)
      # controlliamo se il file esiste
      if os.path.isfile("./img/" + fileName + ".img"):
        print(fileName + " exists")
      # se non esiste, calcolare: 
      else:
        print(fileName)
        # aprire file per leggerlo
        with open("./csv/" + fileName + ".csv") as csvFile:

          csvReader = csv.reader(csvFile, delimiter=",")
          lineCount = 0

          # definire le list per creare il grafico:
          iterations = [] # asse x, corrisponde al numero di iterazione, alla quantità di numeri calcolati
          numeriInUso = [] # asse y, valore del numero calcolato

          for row in csvReader:
            if lineCount == 0:
              print("Colum names")
              lineCount += 1

            else:
              iterations.append(row[0])
              numeriInUso.append(row[1])
                # print(numeriInUso)
              lineCount += 1

        # creare grafico
        finalFigure = plt.figure()
        plt.scatter(iterations, numeriInUso)
        plt.xlabel("Iterazioni") # titolo asse x
        plt.xscale("linear") # scala asse x
        plt.ylabel("Numero") # titolo asse y
        plt.yscale("linear") # scala assse y
        # plt.show()
        finalFigure.savefig("./img/" + fileName + ".png") # salvare immagine