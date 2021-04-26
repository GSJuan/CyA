/**
 * @file tsp_greedy.cc
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief Main program, given a graph via file input, it output the solution for the Travelling Merchant Problem. 
 * @version 0.1
 * @date 2021-01-10
 * SUBJECT: CyA
 * PRACTICE: N.12
 * 
 * @copyright Copyright (c) 2021
 * 
 */

using namespace std;
#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include "node.h"


/**
 * @brief Algoritmo greedy para resolver el problema del comerciante viajero para grafos dirigidos
 * 
 * @param arch_list numero de arcos(caminos entre ciudades)
 * @param city_num numero de nodos(ciudades)
 * @param initial nodo inicial de donde parte (por defecto es 1, pero he dejado abierta la posibilidad de implementar una opcion para cambiar el origen)
 * @return vector <int> 
 */

vector <int> 
DGreedy (vector <Node>& arch_list, unsigned int city_num, int initial){
  //Inicializamos 
  vector <int> solution; ///conjunto de la solución
  int current_node = initial, next_node, temp_sol; ///valores temporales
  float total_weight = 0; ///objetivo a minimizar, el coste del camino

while(solution.size() != city_num) {
  float min = 9999;
  for(size_t i = 0; i < arch_list.size(); i++) {
    if(arch_list[i].GetInit() == current_node) {/// si el nodo origen se corresponde con el nodo en el que "estamos situados" virtualmente
      if ((arch_list[i].GetWeight() < min) && (find(solution.begin(), solution.end(), arch_list[i].GetEnd()) == solution.end())) { ///si el peso de ese arco es minimo y si el destino no está en el conjunto solución
        //incluimos el nodo origen a la solucion y establecemos el nodo destino como el siguiente nodo a evaluar
        temp_sol = arch_list[i].GetInit();
        min = arch_list[i].GetWeight();
        next_node = arch_list[i].GetEnd();
      }
      else if((city_num-1 == solution.size()) && (arch_list[i].GetEnd() == initial)) { ///caso único que solo se da al añadir el último nodo a la solución
        temp_sol = arch_list[i].GetInit();
        min = arch_list[i].GetWeight();
        next_node = arch_list[i].GetEnd();
      }
    }
  }
  // se establecen oficialmente los valorees temporales, añadiendo el peso del arco, el nodo origen a la solucion, y estableciendo el proximo nodo como el nodo actual(avanzamos a la siguiente ciudad)
  current_node = next_node;
  solution.push_back(temp_sol);
  total_weight += min;
}
cout << total_weight << "Kms" << endl;
solution.push_back(initial);//finalmente, aunque se haya tendio en cuenta el peso y el resto de detalles, es necesario añadir manualmente al nodo inicial de nuevo en el campo de soluciones
return solution;
}


//puesto que el algoritmo que he diseñado solo funciona con grafos dirigidos, esta funcion transforma cualquier grafo no dirigido en una especie de grafo dirigido
vector <Node> 
Transform_to_directed (vector <Node>& arch_list){
  int size = arch_list.size();
  vector <Node> solution;
  for(int i = 0; i < size; i++) {
    Node reverse;
    //basicamente crea un vector de nodos en el que se almacenan los arcos del grafo original, además de los arcos en sentido inverso
    reverse.SetInit(arch_list[i].GetEnd());
    reverse.SetWeight(arch_list[i].GetWeight());
    reverse.SetEnd(arch_list[i].GetInit());

    solution.push_back(arch_list[i]);
    solution.push_back(reverse);
  }
  return solution;
}

//Función main que recibe un fichero de entrada y evalua el grafo llamando a la funcion DGreedy
int 
main(int argc, char** argv) {
  
string kHelp = "--help";
string kh = "-h";
  if (argv[1] == NULL) {
    cout << "Usage: ./Tsp input.txt" << endl;
    cout << "Try ´tsp --help O -h´ for further information." << endl;
  }
  else if((argv[1] == kHelp) || (argv[1] == kh)) {
    cout << "Given a Graph via file with format .txt ," << endl; 
    cout << "this program solves the Travelling Merchant Problem." << endl;
    cout << "It also outputs the results into the output file.(This is only activated whe you uncomment some code in the main function)" << endl;
    cout << "Usage: ./Tsp input.txt (and only when done uncommenting the main function) output.txt" << endl;
  }
  else {
    const char* input_txt = argv[1];
    //const char* output_txt = argv[2];
    int initial = 1;
    vector <Node> archs;

    ifstream text_input;
    //ofstream output;
    text_input.open(input_txt);
    //output.open(output_txt);

   int city_num;
    int origin, destination, bit;
    float weight;
    
    if (text_input.is_open()){
      text_input >> bit;
      text_input >> city_num;

      while (!text_input.eof()){

        text_input >> origin;
        text_input >> destination;
        text_input >> weight;
        Node temp(origin, weight, destination);
        archs.push_back(temp);
      }
    }

    else{
      cout << "Error en la apertura de los ficheros" << endl;
      return 1;
    } 

    vector <int> solution;
    if(bit == 0) // si es no dirigido
    archs = Transform_to_directed(archs);

    solution = DGreedy(archs, city_num, initial);

    cout << "S = {";
    for (size_t i = 0; i < solution.size(); i++)
    {
      cout << solution[i];
      if(i < solution.size() - 1)
      cout << ", ";
    }
    cout  << "}" << endl;
    text_input.close();
    // output.close();
  }
  return 0;
}

