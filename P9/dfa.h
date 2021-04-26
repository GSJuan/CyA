/**
 * @file dfa.h
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief Headers of the DFA class
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

#ifndef _Dfa_H_
#define _Dfa_H_

#include <string>
#include <vector>

#include "transition.cc"
#include "grammar.cc"

using namespace std;
class Dfa {
      
  private:
  ///Atributos
    vector<string> alphabet_;
    vector<string> states_;
    string initial_;
    vector<string> accept_states_;
    vector<Transition> transitions_;

  public:
  ///constructor y destructor
    Dfa();
    Dfa(istream&);
   ~Dfa();

  ///Setters
    void SetAlphabet (string);
    void SetStates (string);
    void SetInitial (string);
    void SetAcceptanceStates (string);
    void SetTransition (vector<string>);

  ///Getters
    vector <string> GetAlphabet(void);
    vector <string> GetStates(void);
    string GetStart(void);
    vector <string> GetAcceptanceStates(void);
    vector <string> GetTransition(int);
    int GetTransitionsSize(void);
    
    ///Metodos
    bool IsItAState(string);
    bool IsItAlphabet(string);
    bool IsItAcceptance(string);
    bool Evaluate(string);
    friend string NoComment(string);
    friend istream &operator>>( istream&, Dfa&);
    Grammar ConvertToGrammar(void);
};
#endif