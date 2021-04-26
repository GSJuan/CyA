// AUTHOR: Juan García Santos
// DATE: 15/10/2020
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 1.0
// SUBJECT: CyA
// PRACTICE Nº: 3

//Checks if a number is wether or not a palindrome
bool 
CheckPalindrome (long int number);

//Calculates the maximum number that can be written 
//with a length equal to a given digit
long int 
MaxInterval (int digit_number);

//Same as the previous method but calculates the minimum 
long int 
MinInterval (int digit_number);

//Given a digit and the name of a file, calculates a range of numbers 
//using the previous methods and multiplies all the numbers in that range 
//with each other. Then checks if each result is palindrome;
// if so, outputs that number to the file 
void 
Palindrome_Prod (int digits, const char* file);