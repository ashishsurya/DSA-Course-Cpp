#include<iostream>
using namespace std;

void heapsort(int arr[], int n) {
  // build the heap from the given array
  for (int i = 1; i < n;i++) {
    int childIndex = i;

/*
Starting from index 1 insert eache element on after the other and build the heap.
*/

    while(childIndex > 0) {
    int parentIndex = (childIndex - 1) / 2;
      if (arr[childIndex] < arr[parentIndex]) {
        int temp = arr[childIndex];
        arr[childIndex] = arr[parentIndex];
        arr[parentIndex] = temp;

      } else
        break;

      childIndex = parentIndex;
    }
  }

  // Remove elements

  int size = n;
  while(size > 1) {
    int temp = arr[0];
  arr[0] = arr[size - 1];
  arr[size - 1] = temp;

  size--;

  int parentIndex = 0;
    int leftChildIndex = 2 * parentIndex + 1;
    int rightChildIndex = 2 * parentIndex + 2;

    // the condition for the while loop is it should have atleast one child.
    while(leftChildIndex < size) {
      int minIndex = parentIndex;
      if (arr[minIndex] > arr[leftChildIndex])
      {
        minIndex = leftChildIndex;
      }

      // before comparing with rightChild making sure whether there is a right child.
      if(rightChildIndex < size && arr[minIndex] > arr[rightChildIndex]) {
        minIndex = rightChildIndex;
      }

      // if parent index and minIndex then break the loop all the conditions are satisfied.
      if (parentIndex == minIndex){
        break;
      }

      int temp = arr[minIndex];
      arr[minIndex] = arr[parentIndex];
      arr[parentIndex] = temp;

      parentIndex = minIndex;
      leftChildIndex = 2 * parentIndex + 1;
      rightChildIndex = 2 * parentIndex + 2;
    }
  }
}

int main() {

  int arr[] = {0,1,5,8,2};

  heapsort(arr,5);

  for (int i = 0; i < 5; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
