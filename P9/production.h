/**
 * @file Production.h
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief Production class headers
 * @version 0.1
 * @date 2020-11-28
 * SUBJECT: CyA
 * PRACTICE: N.9
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef _Production_H_
#define _Production_H_

#include <string>
#include <vector>

#pragma once

using namespace std;

class Production{
  private:
  ///Atributos
      vector <string> production;
  public:
  ///Constructores y destructor
    Production();
    Production(vector <string>);
    ~Production();

  ///Getters
    string GetInit();
    string GetProduced(void);
    vector <string> GetWholeProd();

  ///Setters
    void SetInit(string);
    void SetAProd(string, int);
};

#endif