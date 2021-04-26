// AUTHOR: Juan García Santos
// DATE: 15/10/2020
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 1.0
// SUBJECT: CyA
// PRACTICE Nº: 4
//Compilation: make
//Execution: ./palindrome_prod 2 output.txt (example)


#include "fibonacci_words.h"
using namespace std;

//Constructor por defecto
Fibonacci::Fibonacci(void){
  a = "a";
  b = "b";
}
//Constructor general


void Fibonacci::SetA(string prim){
  a = prim;
}

void Fibonacci::SetB(string sec){
  b = sec;
}

string Fibonacci::GetA(void){
  return a;
}

string Fibonacci::GetB(void){
  return b;
}

bool Fibonacci::CheckFibonacci (string cadena){
  string F[10]; 
  F[0] = GetA();
  F[1] = GetB();

  if(cadena.size() >= 2){
    for(int n = 2; n < 10 ; n++){
      F[n] = F[n-2] + F[n-1];
      if(cadena == F[n])
        return true;
    }
    return false;
  }
  else return true;
}  

void Fibonacci::FibonacciWords (const char* file_input, const char* file_output ) {
  ifstream input;
  ofstream output;
  output.open(file_output);
  input.open(file_input);
  int k = 1;
  string line;
  if(input.is_open()){
    for(string line = ""; getline(input, line);){
      if(CheckFibonacci(line)== true){
        output << line << " is the word number " << k << endl;
      }
      else {
        output << line << " is not a fibonacci word" << endl;
      }
      k++;
    }
  }
  input.close();
  output.close();
}
