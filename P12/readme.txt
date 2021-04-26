-Compilación: g++ -std=c++11 -Wall -o tsp tsp_greedy.cc node.cc

-Ejecución: ./tsp city_directed.txt
	    ./tsp city_non_directed.txt

-Formato de salida:

X Kms (coste del viaje)
S = {X, Y, Z,..., W} (conjunto de la solución)

-Formato de entrada: (ojo porque hay un cambio respecto del enunciado)

1 o 0                          // Bit para indicar si es se trata de un grafo dirigido(1) o si no lo es(0)
3                              // Número de ciudades
1 2 3.4                        // Ciudad_origen Ciudad_destino Peso
1 3 4.5                        // Ciudad_origen Ciudad_destino Peso
2 3 5.6                        // Ciudad_origen Ciudad_destino Peso
