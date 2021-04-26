/**
 * @file Transition.cc
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief Transition class, created to store DFA transitions
 * @version 0.1
 * @date 2020-11-28
 * SUBJECT: CyA
 * PRACTICE: N.9
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef _Transition_CC_
#define _Transition_CC_

#include "transition.h"
///constructor por defecto
Transition::Transition() {}

///constructor de transicion
Transition::Transition(string init, string symbol, string end){
init_ = init;
symbol_ = symbol;
end_ = end;
}

///destructor
Transition::~Transition() {}

///devuelve el estado inicial de la transicion
string Transition::GetInit(){
  return init_;
}

///devuelve el simbolo de la transicion
string Transition::GetSymbol(){
  return symbol_;
}

/// devuelve el estado final de la transicion
string Transition::GetEnd(){
  return end_;
}

///devuelve la transición almacenada en el nodo
vector <string> Transition::GetInfo(){
  vector <string> a;
  a.push_back(GetInit());
  a.push_back(GetSymbol());
  a.push_back(GetEnd());
  return a;
}

///establece el estado inicial de la transicion
void Transition::SetInit(string a){
  init_ = a;
}

///establece el valor de la transicion
void Transition::SetSymbol(string a){
  symbol_ = a;
}

///establece el nodo final de la transicion
void Transition::SetEnd(string a){
  end_ = a;
}

#endif