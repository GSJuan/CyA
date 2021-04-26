/**
 * @file dfa2g.cpp
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief Program that interpretates a given DFA ang evaluates given chains
 * @version 0.1
 * @date 2020-11-28
 * SUBJECT: CyA
 * PRACTICE: N.9
 * 
 * @copyright Copyright (c) 2020
 * 
 * COMPILATION: make
 * EXECUTION: ./dfa2g input.df output.gra
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib> 
#include <string>
#include <ctype.h>

#include "dfa.cc"

using namespace std;

const std::string kHelp = "--help";
const std::string kH = "-h";


int main(int argc, char** argv) {

  if (argv[1] == NULL) {
    cout << "Modo de empleo: ./dfa2g input.dfa output.gra" << endl;
    cout << "Pruebe ’dfa2g --help’ para mas informacion." << endl;
  }
  else if((argv[1] == kH) || (argv[1] == kHelp)) {
    cout << "Given a DFA via file with format *dfa , an imput *txt file with a number of chains and an output *txt file," << endl; 
    cout << "this program evaluates the chains and determines whther they are accepted by the DFA or not." << endl;
    cout << "It also outputs the results into the output file." << endl;
    cout << "Usage: ./dfa2g input.dfa output.gra" << endl;
  }
  else if(argv[2] == NULL) {
    cout << "Modo de empleo: ./dfa2g input.dfa output.gra" << endl;
    cout << "Pruebe ’dfa2g --help’ para mas informacion." << endl;
  }
  else {
    const char* input_dfa = argv[1];
    const char* output_gra = argv[2];

    ifstream dfa_input;
    ofstream gra_output;
    dfa_input.open(input_dfa);
    gra_output.open(output_gra);
    Grammar gr;
    Dfa dfa;
    if (dfa_input.is_open()){
      dfa_input >> dfa;
      gr = dfa.ConvertToGrammar();
      gra_output << gr;
    }
    else cout << "Error en la apertura de los ficheros" << endl;
    dfa_input.close();
    gra_output.close();
  }
  return 0;
}