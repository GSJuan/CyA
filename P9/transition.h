/**
 * @file Transition.cc
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief Transition class headers
 * @version 0.1
 * @date 2020-11-28
 * SUBJECT: CyA
 * PRACTICE: N.9
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef _Transition_H_
#define _Transition_H_

#include <string>
#include <vector>

#pragma once

using namespace std;

class Transition{
  private:
  ///Atributos
      string init_;
      string symbol_;
      string end_;
  public:
  ///Constructores y destructor
    Transition();
    Transition(string, string, string);
    ~Transition();

  ///Getters
    string GetInit();
    string GetSymbol();
    string GetEnd();
    vector <string> GetInfo();

  ///Setters
    void SetInit(string);
    void SetSymbol(string);
    void SetEnd(string);
};

#endif