#include "City.h"

const int INF = 1e9;
City::City(unsigned N) : N_(N), matrix_(N, std::vector<unsigned int>(N, INF)){
  for(int i = 0; i < N; ++i){
    matrix_[i][i] = 0;
  }
}

void City:: add_street(unsigned int u, unsigned int v ,unsigned int k){
  matrix_[u][v] = std::min(matrix_[u][v], k); //навсякий , потом может надо убрать std::min, может не понадобится 
}
void City:: Dijkstra(){
  
}


void City:: Floyd_Warshall(){
  for(int i = 0; i < N_; ++i){
    for(int j = 0; j < N_; ++j){
      for(int v = 0; v < N_; ++v){
        if(matrix_[j][i] != INF && matrix_[i][v] != INF && matrix_[j][v] > matrix_[j][i] + matrix_[i][v]){
          matrix_[j][v] = matrix_[j][i] + matrix_[i][v];
        }
      }

    }  
  }
} // млм ей надо передать матрицу?
