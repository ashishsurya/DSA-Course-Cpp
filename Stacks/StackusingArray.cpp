#include<iostream>
using namespace std;
class Stack
{
  int *data;
  int nextindex;
  int capacity;

public:
  Stack(int totalSize)
  {
    data = new int[totalSize];
    nextindex = 0;
    capacity = totalSize;
  }

  int size() {
    return nextindex;
  }

  bool isEmpty() {
    return nextindex == 0;
  }

  void push(int element) {
    if(capacity == nextindex) {
      cout << "Stack is full" << endl;
      return;
    }

    data[nextindex] = element;
    nextindex++;
  }

  int pop() {
    if(isEmpty()) {
      cout << "Stack is empty" << endl;
      return INT16_MIN;
    }
    nextindex--;
    return data[nextindex];
  }

  int top(){
    if(isEmpty()){
      return INT16_MIN;
    }
    return data[nextindex - 1];
  }
};


int main(int argc, char const *argv[])
{
  Stack s(5);

  s.push(20);
  s.push(20);
  s.push(20);
  s.push(20);
  s.push(20);

  cout << s.top() << endl;

  return 0;
}
