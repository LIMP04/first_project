#include <algorithm> 
#include <iostream> 
#include <vector> 
#include <queue> 


const int INF = 1e9; 

class TransportationSystem { 
private: 
  unsigned int N_; 
  std::vector<std::vector<unsigned int>> matrix_; 
  std::vector<std::pair<unsigned int, std::vector<unsigned int>>> buses_; 

public: 
  TransportationSystem(unsigned int N) 
      : N_(N), matrix_(N, std::vector<unsigned int>(N, INF)) { 
    for (int i = 0; i < N; ++i) { 
      matrix_[i][i] = 0; 
    } 
  } 
  void add_street(unsigned int u, unsigned int v, unsigned int k) { 
    matrix_[u][v] = k; 
  } 

  const std::vector<std::pair<unsigned int, std::vector<unsigned int>>> & 
  getBuses() const { 
    return buses_; 
  } 

  void Floyd_Warshall() { 
    for (int i = 0; i < N_; ++i) { 
      for (int j = 0; j < N_; ++j) { 
        for (int v = 0; v < N_; ++v) { 
          if (matrix_[j][i] != INF && matrix_[i][v] != INF && 
              matrix_[j][v] > matrix_[j][i] + matrix_[i][v]) { 
            matrix_[j][v] = matrix_[j][i] + matrix_[i][v]; 
          } 
        } 
      } 
    } 
  } 

  /*void print() { 
    for (int i = 0; i < N_; ++i) { 
      for (int j = 0; j < N_; ++j) { 
        std::cout << matrix_[i][j] << " "; 
      } 
      std::cout << " " << std::endl; 
    } 
    std::cout << std::endl; 
  }*/ 

  std::pair<unsigned int, unsigned int> 
  shortest_path(unsigned int A, const std::vector<unsigned int> &destinations) { 
    unsigned int closest_Bi_N = destinations[0]; 
    unsigned int min_time = INF; 
    for (unsigned int i : destinations) { 
      if (matrix_[A][i] < min_time && matrix_[A][i] != 0) { 
        min_time = matrix_[A][i]; 
        closest_Bi_N = i; 
      } 
    } 
    return std::make_pair(closest_Bi_N, min_time); 
  } 

  std::pair<unsigned int, unsigned int> 
  add_bus(unsigned int A, const std::vector<unsigned int> &destinations) { 
    buses_.push_back(std::make_pair(A, destinations)); 
    return shortest_path(A, destinations); 
  } 

  void construct_crossroad(const std::vector<unsigned int> &s, 
                           const std::vector<unsigned int> &out_s) { 

    for (unsigned int i = 0; i < N_; ++i) { 
      matrix_[i].push_back(INF); 
    } 
    matrix_.push_back(std::vector<unsigned int>(N_ + 1, INF)); 
    ++N_; 
    matrix_[matrix_.size() - 1][matrix_.size() - 1] = 0; 

    for (unsigned int i = 0; i < s.size(); i += 2) { 
      unsigned int u = s[i]; 
      unsigned int c = s[i + 1]; 
      matrix_[u][matrix_.size() - 1] = c; 
    } 

    for (unsigned int i = 0; i < out_s.size(); i += 2) { 
      unsigned int U = out_s[i]; 
      unsigned int C = out_s[i + 1]; 
      matrix_[matrix_.size() - 1][U] = C; 
    } 
  } 

 std::vector<unsigned int> Dijkstra(unsigned int start) { 
        std::vector<unsigned int> dist(N_, INF); 
        dist[start] = 0; 
        std::priority_queue<std::pair<unsigned int, unsigned int>, 
                            std::vector<std::pair<unsigned int, unsigned int>>, 
                            std::greater<std::pair<unsigned int, unsigned int>>> pq; 
        pq.push({0, start}); 

        while (!pq.empty()) { 
            unsigned int u = pq.top().second; 
            unsigned int d_u = pq.top().first; 
            pq.pop(); 

            if (d_u > dist[u]) 
                continue; 

            for (unsigned int v = 0; v < N_; ++v) { 
                if (matrix_[u][v] != INF) { 
                    unsigned int weight = matrix_[u][v]; 
                    if (dist[v] > dist[u] + weight) { 
                        dist[v] = dist[u] + weight; 
                        pq.push({dist[v], v}); 
                    } 
                } 
            } 
        } 

        return dist; 
    } 

    std::vector<unsigned int> common_streets(unsigned int i, unsigned int j) { 
        std::vector<unsigned int> streets; 

        std::vector<unsigned int> dist_i = Dijkstra(buses_[i].first); 
        std::vector<unsigned int> dist_j = Dijkstra(buses_[j].first); 

        for (unsigned int u = 0; u < N_; ++u) { 
            for (unsigned int v = 0; v < N_; ++v) { 
                if (matrix_[u][v] != INF && dist_i[u] + matrix_[u][v] + dist_j[v] == dist_i[buses_[j].first]) { 
                    streets.push_back(v); 
                } 
            } 
        } 

        return streets; 
    } 

}; 

int main() { 
  unsigned int N, M; 
  std::cout << "Enter the number of crossroads: "; 
  std::cin >> N; 

  while (true) { 
    std::cout << "Enter the number of streets (the number should not exceed " 
              << N * (N - 1) << "): "; 
    std::cin >> M; 
    if (M <= N * (N - 1)) { 
      break; 
    } else { 
      std::cerr << "Too many streets" << std::endl; 
    } 
  } 
  TransportationSystem mat_(N); // 

  for (int i = 0; i < M; ++i) { 
    unsigned int u, v, k; 
    std::cin >> u >> v >> k; 
    mat_.add_street(u, v, k); 
  } 

  int operation = 0; 
  do { 
    std::cout << "Select the operation number: (To exit the loop, enter : -1)" << std::endl; 
    std::cin >> operation; 

    if (operation == 1) { 

      unsigned int k, A; 
      std::cout << "Enter the number of destinations:" << std::endl; 
      std::cin >> k; 
      std::cout << "Enter the crossroad from which the route will start:" 
                << std::endl; 
      std::cin >> A; 
      mat_.Floyd_Warshall(); 

      std::vector<unsigned int> destinations(k); 
      std::cout << "Enter the destinations:" << std::endl; 
      for (int i = 0; i < k; ++i) { 
        std::cin >> destinations[i]; 
      } 
      std::pair<unsigned int, unsigned int> res = mat_.add_bus(A, destinations); 
      std::cout << "Closest crossroad: " << res.first 
                << ", min time: " << res.second << std::endl; 

    } else if (operation == 2) { 
      unsigned int k, m; 
      std::cout << "Enter the number of crossroads that are heading to the new " 
                   "crossroad:" 
                << std::endl; 
      ; 
      std::cin >> k; 

      std::vector<unsigned int> s(2 * k); 
      for (int i = 0; i < 2 * k; ++i) { 
        std::cin >> s[i]; 
      } 

      std::cout << "Enter the number of crossroads that the new crossroad is " 
                   "heading to:" 
                << std::endl; 
      ; 
      std::cin >> m; 

      std::vector<unsigned int> o_s(2 * m); 
      for (int i = 0; i < 2 * m; ++i) { 
        std::cin >> o_s[i]; 
      } 
      mat_.construct_crossroad(s, o_s); 

      mat_.Floyd_Warshall(); 

      const std::vector<std::pair<unsigned int, std::vector<unsigned int>>> 
          &buses = mat_.getBuses(); 

      for (int i = 0; i < buses.size(); ++i) { 
        unsigned int crossroad = buses[i].first; 
        const auto &destinations = 
            buses[i].second;  

        std::pair<unsigned int, unsigned int> result = 
            mat_.shortest_path(crossroad, destinations); 
        std::cout << "Bus number: " << i 
                  << "  closest crossroad: " << result.first 
                  << "  min time: " << result.second << std::endl; 
      } 
    }else if (operation == 3) { 
      unsigned int i, j; 
      std::cout << "Enter the bus numbers (i and j): "; 
      std::cin >> i >> j; 

      const std::vector<unsigned int> &common_streets = mat_.common_streets(i, j); 

      std::cout << "Common streets between bus " << i << " and bus " << j << ": "; 
      for (unsigned int street : common_streets) { 
        std::cout << street << " "; 
      } 
      std::cout << std::endl; 
    } 
  } while (operation != -1); 

  return 0; 
}