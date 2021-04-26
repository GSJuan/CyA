/**
 * @file grammar.h
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief Headers of the Grammar class
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
#ifndef _Grammar_H_
#define _Grammar_H_

#include <string>
#include <vector>

#include "production.cc"

using namespace std;

class Grammar {
private:
  ///Atributos
  vector <string> non_terminal; ///dfa estados
  vector <string> terminal; ///dfa alfabeto
  vector <string> acceptance; ///dfa aceptacion
  string initial; ///dfa start
  vector <Production> production; ///dfa transiciones

public:
  ///Constructores y destructor
  Grammar();
  ~Grammar();

  ///Setters
  void SetNonTerminal (string);
  void SetNonTerminal(vector <string>);

  void SetTerminal (string);
  void SetTerminal(vector <string>);

  void SetAcceptance(vector<string>);

  void SetInitial (string);

  void SetProduction (vector<string>);

  ///Getters
  vector <string> GetNonTerminal(void);
  vector <string> GetTerminal(void);
  vector <string> GetAcceptance(void);
  string GetInitial(void);
  Production GetProduction(int);
  vector<Production> GetAllProductions(void);

  ///Metodos
  bool IsItTerminal(string);
  bool IsItNonTerminal(string);
  bool IsItAcceptance(string);
  Grammar operator=(Grammar);
  friend ostream &operator<<( ostream&, Grammar&);
};

#endif