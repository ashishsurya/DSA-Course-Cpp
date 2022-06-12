#include<iostream>
#include<queue>
using namespace std;

int buyTicket(int arr[], int n, int k) {
  int T = 0;
  queue<int> indicies;
  priority_queue<int> maxHeap;

  for (int i = 0; i < n; i++)
  {
    indicies.push(i);
    maxHeap.push(arr[i]);
  }

  while(!indicies.empty()) {
    if(arr[indicies.front()] == maxHeap.top()) {
      if(indicies.front() == k) {
        T++;
        break;
      } else {
        T++;
        maxHeap.pop();
        indicies.pop();
      }
    } else if(arr[indicies.front()] < maxHeap.top()) {
      int top = indicies.front();
      indicies.pop();
      indicies.push(top);
    }
  }
  return T;
}

int main() {
  
  return 0;
}
