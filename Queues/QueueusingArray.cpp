#include<iostream>
using namespace std;
#include<queue>
template <typename T>

class QueueUsingArray {
  T *data;
  int nextindex;
  int firstindex;
  int size;
  int capacity;

public: 
  QueueUsingArray(int s) {
    data = new T[s];
    nextindex = 0;
    firstindex = -1;
    size = 0;
    capacity = s;
  }

  int getSize() {
    return size;
  }

  bool isEmpty() {
    return size == 0;
  }

  void enqueue(T element) {
    data[nextindex] = element;
  }
}

int main(int argc, char const *argv[])
{

  queue<int> q;
  return 0;
}


