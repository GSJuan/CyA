// AUTHOR: Juan García Santos
// DATE: 15/10/2020
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 1.0
// SUBJECT: CyA
// PRACTICE Nº: 3
//Compilation: make
//Execution: ./palindrome_prod 2 output.txt (example)

//Given an integer n > 0 and a file name, this program finds the spiky numbers 
//resulting from multiplying two numbers of n digits each. Every spiky number
//is then printed into the file 

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include "palindrome_prod.h"

using namespace std;

int main(int argc, char* argv[]) {
  if (argv[1] == NULL || argv[2] == NULL) {
    cout << "Error; Usage: ./palindrome_prod digit[int > 0] output.txt" << endl;
  }
  else {
    int digit_number = atoi(argv[1]);
    const char* file_name = argv[2];
    Palindrome_Prod(digit_number, file_name);
  }
return 0;
}

bool
CheckPalindrome (long int number) {
  long int n = number, digit, reverse = 0;
  do {
    digit = number % 10;
    reverse = (reverse * 10) + digit;
    number = number / 10;
  } while (number != 0);

  bool palindrome;
  (n == reverse) ? palindrome = true : palindrome = false;

  return palindrome;
}

long int 
MaxInterval (int digit_number) {
  long int maximum = 0;
  for(int i = 0; i < digit_number; i++) {
    maximum = maximum + ((pow (10, i)) * 9) ;
  }
  return maximum;
}

long int 
MinInterval (int digit_number) {
  long int minimum;
  if(digit_number <= 0)
  minimum = 0;
  else
  minimum = pow (10, (digit_number - 1));
  return minimum;
}

void 
Palindrome_Prod (int digits, const char* file_name) {

  long int max_interval = MaxInterval(digits), min_interval = MinInterval(digits), palindrome;  
  ofstream myfile;
  myfile.open(file_name);
  
  for(int i = min_interval; i <= max_interval; i++){
    for(int j = min_interval; j <= max_interval; j++){
      palindrome = i * j;
      if(CheckPalindrome(palindrome) == true){
        myfile <<  palindrome << " = " << i << " * " << j << endl;
      }
    }
  }
  myfile.close();
}