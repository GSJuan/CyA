/**
 * @file Node.cc
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief Node class headers
 * @version 0.1
 * @date 2020-11-14
 * SUBJECT: CyA
 * PRACTICE: N.7
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef _Node_H_
#define _Node_H_

#include <string>
#include <vector>

using namespace std;

class Node{
  private:
      string init_;
      string symbol_;
      string end_;
  public:
  ///Constructores y destructor
    Node();
    Node(string, string, string);
    ~Node();

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