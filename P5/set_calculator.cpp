/**
 * @file main.cpp
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief Este programa lee operaciones de conjuntos desde un fichero e imprime sus resultados en otro fichero.
 * @version 0.1
 * @date 2020-10-28
 * SUBJECT: CyA
 * PRACTICE: N.5
 * 
 * @copyright Copyright (c) 2020
 * 
 * COMPILATION: make
 * EXECUTION: ./main input.txt output.txt (example)
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include "set.cc"
#include<ctype.h>

using namespace std;

/**
 * @brief Programa principal que maneja la lectura y escritura de ficheros respecto a conjuntos
 * NOTA: respecto el formato del fichero de entrada, siempre debe haber espacios entre: 
 * un corchete y un numero, entre dos corchetes  entre coma y siguiente numero, y entre operaciones y corchetes.
 * Use de ejemplo visual las siguientes operaciones entre conjuntos:
 * ! { 57, 67 } + { 4, 5, 6 } * ! { 7, 8, 9 } 
 * ! { } - { 3, 7, 73, 48, 89 } 
 * Esto significa: 1) el primer conjunto negado + (el segundo conjunto * (el tercer conjunto negado)) 
 * 2) el conjunto vacío negado - el segundo conjunto.
 * @param argc 
 * @param argv 
 * @return int
 */

int main(int argc, char* argv[]) {

  string help = "--help";

  if (argv[1] == NULL) {
  cout << "Error; Usage: ./palindrome_prod digit[int > 0] output.txt" << endl;
  }
  else if(argv[1] == help) {
    cout << "Given a sequence of words, this program identifies whether the words are considered Fibonacci words or not" << endl;
  }
  else {
    const char* file_input = argv[1];
    const char* file_output = argv[2];

    ifstream input;
    ofstream output;
    input.open(file_input);
    output.open(file_output);
    vector <Set> A(4, Set(100));

      if(input.is_open()){
        while(input >> A){
          output << A;
        }
      }
    input.close();
    output.close();
  }
return 0;
}
