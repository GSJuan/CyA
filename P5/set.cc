/**
 * @file main.cpp
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2020-10-28
 * SUBJECT: CyA
 * PRACTICE: N.5
 * 
 * @copyright Copyright (operator) 2020
 * 
 * COMPILATION: make
 * EXECUTION: ./main input.txt output.txt (example)
 */

#include "set.h"

using namespace std;

/**
 * @brief Constructor por defecto
 * 
 */
Set::Set(void){ 
  set_size = 8 * sizeof(long);
  index = 1;
  vector <long> a(index);
  set = a;
  cardinality = 0;
  op = 0;
}

/**
 * @brief Constructor con valor de tamaño
 * 
 * @param max_elements 
 */
Set::Set(int max_elements){
  set_size = max_elements;
  index = (set_size / 64);
  vector <long> a(index);
  set = a;
  cardinality = 0;
  op = 0;
}

/**
 * @brief Constructor de copia
 * 
 * @param a 
 */
Set::Set(const Set& a){
  set_size = a.set_size;
  index = a.index;
  cardinality = a.cardinality;
  vector <long> b(index);
  b = a.set;
  set = b;
  op = a.op;
}

/**
 * @brief Destructor
 * 
 */
Set::~Set(void){
}

/**
 * @brief Establece el tamaño del conjunto
 * 
 * @param size 
 */
void Set::SetSize(int size){
  set_size = size;
  index = (set_size / 64);
  vector <long> a(index);
  set = a;
}

/**
 * @brief Establece el operando del conjunto
 * 
 * @param a 
 */
void Set::SetOp(char a){
  op = a;
}

/**
 * @brief Establece la cardinalidad del conjunto
 * 
 * @param a 
 */
void Set::SetCardinality(int a){
  cardinality = a;
}

/**
 * @brief Muestra el tamaño del conjunto
 * 
 * @return int 
 */
int Set::GetSize(void){
  return set_size;
}

/**
 * @brief Muestra el indice del vector de conjunto
 * 
 * @return int 
 */
int Set::GetIndex(void){
  return index;
}

/**
 * @brief Devuelve el conjunto almacenado en el vector con índice a
 * 
 * @param a 
 * @return long 
 */
long Set::GetSet(int a){
  return set[a];
}

/**
 * @brief Devuelve la cardinalidad del conjunto
 * 
 * @return int 
 */
int Set::GetCardinality(void){
  return cardinality;
}

/**
 * @brief Devuelve el operando asociado al conjunto
 * 
 * @return char 
 */
char Set::GetOp(void){
  return op;
}

/**
 * @brief Incluye en el conjunto el bit que se pase como argumento
 * 
 * @param n 
 */
void Set::SetBit(int n){
  int a = (n / (64));
  int m = n - (63 * a); 
  if(n <= set_size)
   set[a] |= 1UL << m;
  else cout << "Given number does not fit in the set. Please, enter a number within the set´s range: n <= " << set_size << endl;
}

/**
 * @brief Elimina del conjunto el numero que se pase como argumento
 * 
 * @param n 
 */
void Set::ClearBit(int n){
  int a = (n / (64));
  int m = n - (63 * a); 
  set[a] &= ~(1UL << m);
}

/**
 * @brief Vacia un conjunto entero
 * 
 */
void Set::ClearSet(void){
  for(int i = 0 ; i <= GetSize(); i++ ) {
    ClearBit(i);
  }
}

/**
 * @brief Comprueba si un conjunto tiene algun elemento.
 * 
 * @return true si está en uso
 * @return false si está vacio
 */
bool Set::CheckSet(void){
  int in_use = 0;
  for(int i = 0 ; i <= GetSize(); i++) {
    if(CheckBit(i) == true)
      in_use++; 
  }
if (in_use > 0)
  return true;
else 
  return false;
}

/**
 * @brief Combrueba si el numero n está dentro del conjunto
 * 
 * @param n ees el numero a comprobar
 * @return true si el numero esta en el conjunto 
 * @return false si el numero no esta en el conjunto
 */
bool Set::CheckBit(long n){
  int bit;
  int a = (n / (64));
  int m = n - (63 * a); 
  bit = (set[a] >> m) & 1U;
  if(bit == 1)
    return true;
  else 
    return false;  
}

/**
 * @brief Invierte el valor de un bit.
 * 
 * @param n es el bit a invertir
 * @param a calcula el inddice del vector en el que esta el bit
 */
void Set::TogglingBit(int n){ 
  int a = (n / (64));
  int m = n - (63 * a); 
  set[a] ^= 1UL << m;
}

/**
 * @brief sobrecarga del operador +
 * 
 * @param a es el conjunto que se va a sumar
 * @return Set que es el resultado
 */
Set Set::operator+(const Set& a){

  int max = a.set_size;
  if (set_size > max)
    max = set_size;

  Set b(max);
  for(int i = 0; i <= b.index; i++)
  b.set[i] = a.set[i] | set[i];
  return b;

}

/**
 * @brief sobrecarga de operador -
 * 
 * @param a es el segundo operando de la resta
 * @return Set que es el resultado
 */
Set Set::operator-(const Set& a){
  int max = a.set_size;
  if (set_size > max)
    max = set_size;

  Set b(max);
  vector <long> c = a.set;
  for(int i = 0; i <= a.set_size; i++){
    int a = (i / (64));
    int m = i - (63 * a); 
    c[a] ^= 1UL << m;
  }
  for(int i = 0; i <= b.index; i++)
    b.set[i] = set[i] & c[i];
  return b;
}

/**
 * @brief Sobrecarga del operando *
 * 
 * @param a el segundo operando de la multiplicacion
 * @return Set 
 */
Set Set::operator*(const Set& a){
  int max = a.set_size;
  if(max < set_size)
    max = set_size;
  Set b(max); 
  for(int i = 0; i <=  b.index; i++)
  b.set[i] = set[i] & a.set[i];
  return b;
}

/**
 * @brief sobrecarga del operando ! (negacion)
 * 
 */
void Set::operator!(void){
  for(int i = 0; i <= set_size; i++)
    TogglingBit(i);
  cardinality = set_size - cardinality;
}

/**
 * @brief sobrecarga del operador =
 * 
 * @param a es el conjunto para igualar
 */
void Set::operator=(const Set& a){

  for (int i = 0; i <= index; i++){
    set[i] = a.set[i];
  }
  set_size = a.set_size;
  index = a.index;
  cardinality = a.cardinality;
  op = a.op;
}

/**
 * @brief sobrecarga del operador ==
 * 
 * @param a segundo operando de la comparacion
 * @return true si son iguales ambos conjuntos
 * @return false si son diferentes ambos conjuntos
 */
bool Set::operator==(const Set& a){
  return set == a.set;
}

/**
 * @brief metodo para escribir un determinado conjunto
 * 
 * @return string devuelve una cadena ya procesada con el formato de un conjunto
 */
string Set::Write(void){
  string output; 
  output.push_back('{');
  output.push_back(' ');
  ostringstream ostr;
  //for(int i )
  for(int i = 0; i <= set_size; i++){
    if(CheckBit(i) == true){
      if(i <= 9){
        output.push_back(' ');
        output.push_back(i + '0');
        output.push_back(',');
      }
      else{
        output.push_back(' ');
        ostr << i;
        output += ostr.str();
        ostr.str("");
        output.push_back(',');
      }
    }
  }   
  output.pop_back();
  output.push_back('}');
  return output;
}

/**
 * @brief sobrecarga del operador de entrada. Identifica la entrada linea a linea 
 * y luego subdivide cada linea en "palabras". Despues, comprueba cada palabra para ver que puede significar
 * (operador, entero, fin de conjunto } ...) y almacena cada dato en el objeto Set.
 * @param is es el flujo de entrada
 * @param A es el vector de conjuntos en el que se va a almacenar la lectura
 * @param i lleva el indice del vector de Set, cuando detecta }
 *  interpreta que es el finde un conjunto y salta al siguiente
 * @param k sirve para almacenar el numero que se recibe de la entrada
 * @param l almacena cuantos conjuntos se han negado
 * @param neg es un array de enteros que almacena el indice del vector 
 * que contiene al conjunto que ha sido negado
 * @param t lleva la cuenta de enteros almacenados, sirve para representar la cardinalidad
 * @return istream& 
 */

istream& operator>> (istream& is, vector <Set>& A) {
  int i = 0, k = 0, l = 0, t = 0;
  int neg[4];
  char operation;
  for (int i = 0; i <= 3; i++){
    A[i].ClearSet();
    A[i].SetOp(0);
  }
    string line = ""; 
    getline(is, line); 
    istringstream iss(line);
    string word;
    while (iss >> word){
      if(word == "}"){
        A[i].SetCardinality(t);
        i++;
      }
      else if(stringstream(word) >> k){
        A[i].SetBit(k);
        t++;
      } 
      else if(word == "!"){
        neg[l] = i;
        l++;
      }
      else if ((word != " ") && (word != "{" ) && (word != "\n") && (word != ",")){
        stringstream(word) >> operation;
        A[i].SetOp(operation);
      } 
    }   
  
  if(l > 0){ 
    for(int w = 0; w < l; w++){
      !A[neg[w]];
    }
  }
  if(i == 1){ /* Si solo hay un conjunto, da por hecho que la operacion que se le realiza es la negación*/
    A[0].SetOp('!');
  }
return is;
}

/**
 * @brief sobracarga del operador de salida. 
 * Interpreta el operador asociado a cada conjunto y tambien realiza las operaciones pertinentes
 * 
 * @param os es el flujo de salida
 * @param A el vector de conjuntos desde el que se lee la salida
 * @return ostream& 
 */
ostream& operator<< (ostream& os, vector <Set>& A) {

  for(int j = 1; j < 3; j++){
  if(A[j].GetOp() == '+'){
    if(A[3].CheckSet() == false){
      A[3] = A[j-1] + A[j]; 
    }
    else  A[3] = A[3] + A[j]; 
  }
  else if(A[j].GetOp() == '-'){
    if(A[3].CheckSet() == false){
      A[3] = A[j-1] - A[j]; 
    }
    else  A[3] = A[3] - A[j];
  }
  else if(A[j].GetOp() == '*'){
    if(A[3].CheckSet() == false){
      A[3] = A[j-1] * A[j];
    }
    else A[3] = A[3] * A[j];
  }
}
  if(A[0].GetOp() == '!'){
    !A[0];
    os << "!" << A[0].Write() << " = ";
    !A[0];
    os << A[0].Write() << endl;
  }
  else {
  os << A[0].Write() << " " << A[1].GetOp() << " " << A[1].Write();
  if(A[2].CheckSet() == true)
  os << " " << A[2].GetOp() << " " << A[2].Write();
  os << " = " << A[3].Write() << endl;
  }
 return os;
}
