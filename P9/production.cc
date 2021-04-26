/**
 * @file Production.cc
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief Production class, created to store DFA Productions
 * @version 0.1
 * @date 2020-11-28
 * SUBJECT: CyA
 * PRACTICE: N.9
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef _Production_CC_
#define _Production_CC_

#include "production.h"

///constructor por defecto
Production::Production() {
}

///constructor de transicion
Production::Production(vector <string> prod){
production = prod;
}

///destructor
Production::~Production() {}

///devuelve el Simbolo productor
string Production::GetInit(){
  return production[0];
}

///devuelve lo que es producido 
string Production::GetProduced(void){
  string temp;
  temp = production[1] + production[2];
  return temp;
}

///devuelve la produccion integra
vector <string> Production::GetWholeProd(){
  return production;
}

///establece el simbolo que produce
void Production::SetInit(string a){
  production[0] = a;
}

///añade producciones a una produccion ya existente
void Production::SetAProd(string a, int i){
  production[i] = a;
}

#endif