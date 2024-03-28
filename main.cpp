#include <iostream>
#include "TransportationSystem.h"

int main() {
    unsigned int N, M;
    std::cin >> N >> M;
    TransportationSystem mat_(N);

    for (int i = 0; i < M; ++i) {
        unsigned int u, v, k;
        std::cin >> u >> v >> k;
        mat_.add_street(u, v, k);
    }
    mat_.Floyd_Warshall();
    /* unsigned int k, A;
     std::cin >> k >> A;
     std::vector<unsigned int> destinations(k);
     for (int i = 0; i < k; ++i) {
         std::cin >> destinations[i];
     }
     std::pair<int, int> result = mat_.add_buss(k, A, destinations);
     std::cout << result.first << " " << result.second << std::endl;
     */
    mat_.print();
    return 0;
  
}