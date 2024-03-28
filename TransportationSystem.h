#ifndef TRANSPORTATION_SYSTEM_H
#define TRANSPORTATION_SYSTEM_H

#include <vector>

class TransportationSystem { 
private:
  std::vector<std::vector<unsigned int>> matrix_;
  unsigned int N_;

public:
  TransportationSystem(unsigned N);
  void add_street(unsigned int u, unsigned int v, unsigned int k);
 
  //void Floyd_Warshall();

  void print() 
};

#endif