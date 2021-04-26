/**
 * @file dfa.cc
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief DFA class designed to read from file a DFA an evaluate given chains
 * @version 0.1
 * @date 2020-11-28
 * SUBJECT: CyA
 * PRACTICE: N.9
 * 
 * @copyright Copyright (c) 2020
 * 
 * COMPILATION: make
 * EXECUTION: ./dfa_simulation input.df input.txt output.txt
 */

#ifndef _Dfa_CC_
#define _Dfa_CC_

#include "dfa.h"

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

///constructor por defecto
Dfa::Dfa() {
  alphabet_.resize(0);
}

Dfa::Dfa(istream& is) {
  Dfa dfa;
    is >> dfa;
}
///destructor
Dfa::~Dfa() {}

///Establece un simbolo como parte del alfabeto 
void Dfa::SetAlphabet (string symbol) {
  alphabet_.push_back(symbol);

}

///Establece un estado del Dfa
void Dfa::SetStates (string state) {
  states_.push_back(state);
}

///Establece el Estado de arranque
void Dfa::SetInitial (string initial_state) {
  initial_ = initial_state;
}

///Establece un estado como de aceptación si ese estado esta previamente incluido en el conjunto de los estados
void Dfa::SetAcceptanceStates (string state) {
  vector <string> temp = GetStates();
  for(unsigned int i = 0; i <= temp.size(); i++){
    if(temp[i] == state)
      accept_states_.push_back(state);
  }
}

///Establece una transicion solo si los estados y el simbolo han sido previamente añadidos a sus respectivos conjuntos
void Dfa::SetTransition (vector<string> transition) {
  if((IsItAState(transition[0])) && (IsItAState(transition[2])) && (IsItAlphabet(transition[1]))){
    Transition a(transition[0],transition[1],transition[2]);
    transitions_.push_back(a);
  }
  else cout << "la transicion no esta contemplada en el DFA" << endl;
}

///Devuelve el alfabeto asociado al Dfa
vector <string> Dfa::GetAlphabet(){
  return alphabet_;
}

///Devuelve todos los estados del Dfa
vector <string> Dfa::GetStates(){
return states_;
}

///Devuelve el estado de arranque
string Dfa::GetStart(){
  return initial_;
}

///Devuelve los estados de aceptacion
vector <string> Dfa::GetAcceptanceStates(){
  return accept_states_;
}

///Devuelve las transiciones
vector <string> Dfa::GetTransition(int i){
  vector <string> a = transitions_[i].GetInfo();
  return a;
}

///Devuelve el numero de transiciones del dfa
int Dfa::GetTransitionsSize(void){
  return transitions_.size();
}

///dada una string (estado), comprueba si pertenece al conjunto de estados
bool Dfa::IsItAState(string a){
  vector <string> b = GetStates();
  bool condition = false;
  for(unsigned int i = 0; i <= b.size(); i++){
    if(a == b[i])
      condition = true;
  }
return condition;
}

///dada una string (simbolo), comprueba que pertenezca al alfabeto
bool Dfa::IsItAlphabet(string a){
  vector <string> b = GetAlphabet();
  bool condition = false;
  for(unsigned int i = 0; i <= b.size(); i++){
    //cout << b[i] << " " << a << endl;
    if(a == b[i])
      condition = true;
  }
return condition;
}

///dada una string (estado), comprueba que sea de aceptacion
bool Dfa::IsItAcceptance(string a){
vector <string> b = GetAcceptanceStates();
  bool condition = false;
  for(unsigned int i = 0; i <= b.size(); i++){
    if(a == b[i])
      condition = true;
  }
return condition;
}



/**
 * @brief evalua si una cadena es aceptada por el dfa
 * 
 * @return true si la cadena es aceptada
 * @return false si no es aceptada por el dfa
 */
bool Dfa::Evaluate(string cadena){

bool accepted = false;
string state = GetStart();
vector <string> transition;

for(unsigned int i = 0; i < cadena.size(); i++){
  string symbol;
  symbol.push_back(cadena[i]);
  if(IsItAlphabet(symbol)){
    for(int j = 0; j < GetTransitionsSize(); j++){
      transition = GetTransition(j);
      if((transition[0] == state) && (transition[1] == symbol)){
        state = transition[2];
        break;
      }
    }
  }
  else {
    cout << "El simobolo " << symbol << ", no pertenece al alfabeto. " ;
    cout << "Por tanto, cadena rechazada" << endl;
    state = GetStart(); ///lo lleva a un estado de muerte virtual
    break;
  }
}

if (IsItAcceptance(state))
  accepted = true; 
return accepted; 
}

string NoComment(string a){
string line = a;
const string kcomment = "//";
line.substr(0, line.find(kcomment));
return line;
}

///Sobrecarga del operador de entrada
istream& operator>> (istream& is, Dfa& A) {
  string line;
  string comment = "//";

  /**
   * @brief leemos el alfabeto
   * 
   */
 
 do{ getline(is, line);
 }while(line.substr(0,2) == comment);

  int alphabet_size = stoi(line);
  for(int i = 0; i < alphabet_size; i++) {
    getline(is,line);
    A.SetAlphabet(line);
  }  

  /**
   * @brief leemos los estados
   * 
   */
  getline(is,line);
  int states_size = stoi(line);
  for(int i = 0; i < states_size; i++) {
    getline(is,line);
    A.SetStates(line); 
  }

  /**
   * @brief almacenamos el estado de inicio
   * 
   */
  getline(is,line);
  A.SetInitial(line);

  /**
   * @brief almacenamos los estados de aceptación 
   * 
   */
  getline(is,line);
  int acceptance_size = stoi(line);
  for(int i = 0; i < acceptance_size;i++){
    getline(is,line);
    A.SetAcceptanceStates(line);
  }
  /**
   * @brief almacenamos las transiciones
   * 
   */
  getline(is, line);
  int transitions_size = stoi(line);
  for(int i = 0; i < transitions_size; i++){
    getline(is,line);
    vector <string> transition;
    istringstream iss(line);
    string temp;
    while(iss >> temp){
      transition.push_back(temp);
    }
    A.SetTransition(transition);
  }
 return is;
}
///Conversion del dfa a una gramatica regular
Grammar Dfa::ConvertToGrammar(void){
  Grammar grammar;
  grammar.SetInitial(GetStart());
  grammar.SetTerminal(GetAlphabet());
  grammar.SetNonTerminal(GetStates());
  grammar.SetAcceptance(GetAcceptanceStates());
  for(int i = 0; i < GetTransitionsSize(); i++){
    grammar.SetProduction(GetTransition(i));
  }
  return grammar;
}

#endif