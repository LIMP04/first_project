#ifndef CITY_H
#define CITY_H

#include <vector>

class City { //название норм надо взять кончено
private:
  std::vector<std::vector<unsigned int>> matrix_;
  unsigned int N_;

public:
  City(unsigned N);
  void add_street(unsigned int u, unsigned int v, unsigned int k);
  void Dijkstra();
  void Floyd_Warshall();
};

#endif