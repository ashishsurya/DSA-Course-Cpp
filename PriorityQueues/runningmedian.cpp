#include<iostream>
#include<vector>
#include<cstdlib>
#include<queue>

using namespace std;

void findMedian(int *arr, int n) {
    priority_queue<int> maxHeap;
    priority_queue<int , vector<int> , greater<int> > minHeap;
    

    for (int i = 0; i < n;i++) {
    // insert first element into max heap
      if(i==0) {
        maxHeap.push(arr[i]);
        cout << arr[i] << " ";
      }
      else
      {
        if(arr[i] < maxHeap.top()) {
          maxHeap.push(arr[i]);
        } else {
          minHeap.push(arr[i]);
        }
        int sizeDiff = maxHeap.size() - minHeap.size();
        if (abs(sizeDiff) > 1)
        {
          if(maxHeap.size() > minHeap.size()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
          } else if(minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
          }
        }

        if(maxHeap.size() > minHeap.size()) {
          cout << maxHeap.top() << " ";
        }
        else if (minHeap.size() > maxHeap.size())
        {
          cout << minHeap.top() << " ";

        } else {
          cout << (maxHeap.top() + minHeap.top()) / 2 << " ";
        }
      }
    }
}

int main() {
  return 0;
}
