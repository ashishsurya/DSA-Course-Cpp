#include<iostream>
#include "MinPriorityQueue.h"
using namespace std;

int main() {

  MinPriorityQueue pq;
  pq.insert(100);
  pq.insert(10);
  pq.insert(15);
  pq.insert(4);
  pq.insert(17);
  pq.insert(21);
  pq.insert(67);

  pq.print();

  return 0;
}
