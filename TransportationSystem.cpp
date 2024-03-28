#include "TransportationSystem.h"

const int INF = 1e9;
TransportationSystem::TransportationSystem(unsigned N) : N_(N), matrix_(N, std::vector<unsigned int>(N, INF)){
  for(int i = 0; i < N; ++i){
    matrix_[i][i] = 0;
  }
}

void TransportationSystem:: add_street(unsigned int u, unsigned int v ,unsigned int k){
  matrix_[u][v] = std::min(matrix_[u][v], k); //навсякий , потом может надо убрать std::min, может не понадобится 
}
void TransportationSystem::TransportationSystem(){
  
}


/*void TransportationSystem::Floyd_Warshall() {
  for(int i = 0; i < N_; ++i){
    for(int j = 0; j < N_; ++j){
      for(int v = 0; v < N_; ++v){
        if(matrix_[j][i] != INF && matrix_[i][v] != INF && matrix_[j][v] > matrix_[j][i] + matrix_[i][v]){
          matrix_[j][v] = matrix_[j][i] + matrix_[i][v];
        }
      }

    }  
  }
}*/

void TransportationSystem::print() {
    for (int i = 0; i < N_; ++i) {
        for (int j = 0; j < N_; ++j) {
            std::cout << matrix_[i][j] << " ";
        }
        std::cout << " " << std::endl;
    }

}

std::pair<unsigned int, unsigned int> TransportationSystem:: add_buss(unsigned int k, unsigned int A, std::vector<unsigned int>& busses) {

    Floyd_Warshall();
    print();
    unsigned int closest_Bi_N = busses[0];
    int min_time = matrix_[A][busses[0]];
    for (int i = 0; i < k; ++i) {
        if (matrix_[A][busses[i]] < min_time) {
            min_time = matrix_[A][busses[i]];
            closest_Bi_N = busses[i];

        }
    }
    return std::make_pair(closest_Bi_N, min_time);
}
};
