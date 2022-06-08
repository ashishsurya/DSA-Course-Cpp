#include<vector>
using namespace std;


class MinPriorityQueue {
  vector<int> pq;
  public : 
  MinPriorityQueue() {

  }

  void print() {
    for (int i = 0; i < getSize();i++ ) {
      cout << pq[i] << " ";
    }
    cout << endl;
  }

  bool isEmpty() {
    return pq.size() == 0;
  }

// no of elements present
  int getSize() {
    return pq.size();
  }

  int getMin() {
    if(isEmpty())
      return 0; // priority queue is empty...
    return pq[0];
  }

  void insert(int element) {
    pq.push_back(element);

    // to maintain the heap order property we need to check this element with it's parent.

// UP_HEAPIFY 
    int childIndex = pq.size() - 1;

    while(childIndex > 0) {
    int parentIndex = (childIndex - 1) / 2;
      if (pq[childIndex] < pq[parentIndex]) {
        int temp = pq[childIndex];
        pq[childIndex] = pq[parentIndex];
        pq[parentIndex] = temp;

      } else
        break;

      childIndex = parentIndex;
    }
  }

  int removeMin() {
    if(isEmpty()) {
      return 0;
    }

    int ans = pq[0];

    pq[0] = pq[pq.size() - 1];
    pq.pop_back();

    // down-heapify

    int parentIndex = 0;
    int leftChildIndex = 2 * parentIndex + 1;
    int rightChildIndex = 2 * parentIndex + 2;

    // the condition for the while loop is it should have atleast one child.
    while(leftChildIndex < pq.size()) {
      int minIndex = parentIndex;
      if (pq[minIndex] > pq[leftChildIndex])
      {
        minIndex = leftChildIndex;
      }

      // before comparing with rightChild making sure whether there is a right child.
      if(rightChildIndex < pq.size() && pq[minIndex] > pq[rightChildIndex]) {
        minIndex = rightChildIndex;
      }

      // if parent index and minIndex then break the loop all the conditions are satisfied.
      if (parentIndex == minIndex){
        break;
      }

      int temp = pq[minIndex];
      pq[minIndex] = pq[parentIndex];
      pq[parentIndex] = temp;

      parentIndex = minIndex;
      leftChildIndex = 2 * parentIndex + 1;
      rightChildIndex = 2 * parentIndex + 2;
    }

    return ans;
  }
};
