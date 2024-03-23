#include <iostream>
#include "Bus.h"
#include "City.h"

int main() {
  unsigned int N, M;
  std::cin>> N >> M;
  City mat_(N);   //тут получается у нас уже есть матрица , где диагональные = 0\

  for(int i = 0; i < M; ++i){
    unsigned int u, v, k;
    std::cin>> u >> v >> k; //но тут у нас получается с 0 начинаем вершины отсчитывать или с 1, как лучше?
    mat_.add_street(u, v, k);
  }
  std::cout << "Hello World!\n";
  
}