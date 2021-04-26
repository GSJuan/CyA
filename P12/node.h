/**
 * @file node.h
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief Node class headers (reused to store Graphs archs or transitions)
 * @version 0.1
 * @date 2021-01-10
 * SUBJECT: CyA
 * PRACTICE: N.12
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef _Node_H_
#define _Node_H_

#include <vector>

using namespace std;

class Node{
  private:
      int init_;
      float weight_;
      int end_;
      bool visited;
  public:
  ///Constructores y destructor
    Node();
    Node(int, float, int);
    ~Node();

  ///Getters
    int GetInit();
    float GetWeight();
    int GetEnd();
    vector <int> GetInfo();
    bool GetVisited();

  ///Setters
    void SetInit(int);
    void SetWeight(float);
    void SetEnd(int);
    void SetVisited(bool);
};

#endif