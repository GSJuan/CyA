/**
 * @file node.cc
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief Node class, created to store DFA transitions (reused to store Graphs archs or transitions)
 * @version 0.1
 * @date 2021-01-10
 * SUBJECT: CyA
 * PRACTICE: N.12
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
Node::Node(int init, float weight, int end){
init_ = init;
weight_ = weight;
end_ = end;
}

///destructor
Node::~Node() {}

///devuelve el estado inicial de la transicion
int Node::GetInit(){
  return init_;
}

///devuelve el simbolo de la transicion
float Node::GetWeight(){
  return weight_;
}

/// devuelve el estado final de la transicion
int Node::GetEnd(){
  return end_;
}

///devuelve la transición almacenada en el nodo
vector <int> Node::GetInfo(){
  vector <int> a;
  a.push_back(GetInit());
  a.push_back(GetWeight());
  a.push_back(GetEnd());
  return a;
}

bool Node::GetVisited(){
  return visited;
}


///establece el estado inicial de la transicion
void Node::SetInit(int a){
  init_ = a;
}

///establece el valor de la transicion
void Node::SetWeight(float a){
  weight_ = a;
}

///establece el nodo final de la transicion
void Node::SetEnd(int a){
  end_ = a;
}

void Node::SetVisited(bool a){
  visited = a;
}

#endif