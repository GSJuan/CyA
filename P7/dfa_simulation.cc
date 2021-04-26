/**
 * @file dfa_simulation.cpp
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief Program that interpretates a given DFA ang evaluates given chains
 * @version 0.1
 * @date 2020-11-14
 * SUBJECT: CyA
 * PRACTICE: N.7
 * 
 * @copyright Copyright (c) 2020
 * 
 * COMPILATION: make
 * EXECUTION: ./dfa_simulation input.df input.txt output.txt
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib> 
#include <string>
#include <ctype.h>

#include "mod.cc"

using namespace std;

const std::string kHelp = "--help";
const std::string kH = "-h";


int main(int argc, char** argv) {

  if (argv[1] == NULL) {
    cout << "Modo de empleo: ./dfa_simulation input.dfa input.txt output.txt" << endl;
    cout << "Pruebe ’dfa_simulation --help’ para mas informacion." << endl;
  }
  else if((argv[1] == kH) || (argv[1] == kHelp)) {
    cout << "Given a DFA via file with format *dfa , an imput *txt file with a number of chains and an output *txt file," << endl; 
    cout << "this program evaluates the chains and determines whther they are accepted by the DFA or not." << endl;
    cout << "It also outputs the results into the output file." << endl;
    cout << "Usage: ./dfa_simulation input.dfa input.txt output.txt" << endl;
  }
  else if(argv[2] == NULL) {
    cout << "Modo de empleo: ./dfa_simulation input.dfa input.txt output.txt" << endl;
    cout << "Pruebe ’dfa_simulation --help’ para mas informacion." << endl;
  }
  else if(argv[3] == NULL) {
    cout << "Modo de empleo: ./dfa_simulation input.dfa input.txt output.txt" << endl;
    cout << "Pruebe ’dfa_simulation --help’ para mas informacion." << endl;
  }
  else {
    const char* input_dfa = argv[1];
    const char* input_txt = argv[2];
    const char* output_txt = argv[3];

    ifstream dfa_input;
    ifstream text_input;
    ofstream output;
    dfa_input.open(input_dfa);
    text_input.open(input_txt);
    output.open(output_txt);
    Dfa dfa;
    string cadena;

      if ((dfa_input.is_open()) && (text_input.is_open())){
        dfa_input >> dfa;
        while (!text_input.eof()){
          text_input >> cadena;
          if (dfa.Evaluate(cadena))
            output << cadena << " --Si " << endl;
          else 
            output << cadena << " --No " << endl;
        }
      }
      else cout << "Error en la apertura de los ficheros" << endl;
    dfa_input.close();
    text_input.close();
    output.close();
  }
  return 0;
}