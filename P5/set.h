/**
 * @file main.cpp
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2020-10-28
 * SUBJECT: CyA
 * PRACTICE: N.5
 * 
 * @copyright Copyright (c) 2020
 * 
 * COMPILATION: make
 * EXECUTION: ./main input.txt output.txt (example)
 */

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

/**
 * @brief Clase Set para manejar conjuntos
 * 
 */
class Set {

private:

  int set_size;
  vector <long> set;
  int index;
  int cardinality;
  char op;

public:
  /**
   * @brief Constructores
   * 
   */

  Set(void);
  Set(int);
  Set(const Set&);
  ~Set(void);

  /**
   * @brief Setters
   * 
   */

  void SetSize(int);
  void SetOp(char);
  void SetCardinality(int);

  /**
   * @brief Getters
   *  
   */

  int GetSize(void);
  int GetIndex(void);
  long GetSet(int);
  int GetCardinality(void);
  char GetOp(void);

  /**
   * @brief metodos
   * 
   */

  void SetBit(int);
  void ClearBit(int); 
  void ClearSet(void);
  bool CheckSet(void);
  bool CheckBit(long); 
  void TogglingBit(int);
  string Write (void);
  
  /**
   * @brief operadores sobrecargaddos
   * 
   *  
   */
  Set operator+(const Set&);
  Set operator-(const Set&);
  Set operator*(const Set&);
  void operator!(void);
  void operator=(const Set&);
  bool operator==(const Set& );
  friend istream &operator>>( istream&, Set&);
  friend ostream& operator<<(ostream&, Set&); 
};
