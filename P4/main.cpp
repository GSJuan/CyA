// AUTHOR: Juan García Santos
// DATE: 15/10/2020
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 1.0
// SUBJECT: CyA
// PRACTICE Nº: 4
//Compilation: make
//Execution: ./main input.txt output.txt (example)


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include "fibonacci_words.cc"

using namespace std;

int main(int argc, char* argv[]) {

  string help = "--help";

  if (argv[1] == NULL) {
  cout << "Error; Usage: ./palindrome_prod digit[int > 0] output.txt" << endl;
  }
  else if(argv[1] == help) {
    cout << "Given a sequence of words, this program identifies whether the words are considered Fibonacci words or not" << endl;
  }
  else {
    const char* file_input = argv[1];
    const char* file_output = argv[2];

    Fibonacci palabreja;
    palabreja.FibonacciWords(file_input, file_output);
  }
return 0;
}