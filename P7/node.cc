/**
 * @file Node.cc
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief Node class, created to store DFA transitions
 * @version 0.1
 * @date 2020-11-14
 * SUBJECT: CyA
 * PRACTICE: N.7
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef _Node_CC_
#define _Node_CC_

#include "node.h"
///constructor por defecto
Node::Node() {}

///constructor de transicion
Node::Node(string init, string symbol, string end){
init_ = init;
symbol_ = symbol;
end_ = end;
}

///destructor
Node::~Node() {}

///devuelve el estado inicial de la transicion
string Node::GetInit(){
  return init_;
}

///devuelve el simbolo de la transicion
string Node::GetSymbol(){
  return symbol_;
}

/// devuelve el estado final de la transicion
string Node::GetEnd(){
  return end_;
}

///devuelve la transición almacenada en el nodo
vector <string> Node::GetInfo(){
  vector <string> a;
  a.push_back(GetInit());
  a.push_back(GetSymbol());
  a.push_back(GetEnd());
  return a;
}

///establece el estado inicial de la transicion
void Node::SetInit(string a){
  init_ = a;
}

///establece el valor de la transicion
void Node::SetSymbol(string a){
  symbol_ = a;
}

///establece el nodo final de la transicion
void Node::SetEnd(string a){
  end_ = a;
}

#endif