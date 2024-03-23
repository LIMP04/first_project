#ifndef BUS_H
#define BUS_H

#include <vector>
struct Bus{
int num_;
int start_;
std::vector<int> stops_;
Bus(int num, int start, std::vector<int> stops);
}; //надо ли?

#endif