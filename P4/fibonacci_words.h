// AUTHOR: Juan García Santos
// DATE: 22/10/2020
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 1.0
// SUBJECT: CyA
// PRACTICE Nº: 4

 #ifndef __Fibonacci_H__
 #define __Fibonacci_H__
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <math.h>

using namespace std;


class Fibonacci {
  private:
    string a;
    string b;
  public:
 // Constructores
    Fibonacci(void);
 // Setters
    void SetA(string);
    void SetB(string);
 // Getters
    string GetA(void);
    string GetB(void);
//Fibonacci
    void FibonacciWords (const char*, const char*);
//Check fibonacci
    bool CheckFibonacci (string);
};
#endif