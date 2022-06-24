#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int si, int ei)
{
  int pi = si;
  int pivot_element = arr[ei]; // choosing the right most element as pivot element.

  for (int i = si; i < ei; i++)
  {
    if (arr[i] <= pivot_element)
    {
      swap(arr[i], arr[pi]);
      pi++;
    }
  }
  swap(arr[ei], arr[pi]);

  return pi;
}

void quickSort(int arr[], int si, int ei)
{
  cout << "started" << endl;
  if (si >= ei)
    return;

  // getting the partition index from partition func.
  int pi = partition(arr, si, ei);
  cout << pi << endl;

  // calling quicksort on left and right part of pivot index.
  quickSort(arr, si, pi-1);
  quickSort(arr, pi + 1, ei);
}

int main()
{

  int arr[] = {1, 3, 5, 6, 2};

  quickSort(arr, 0, 4);
  for (int i = 0; i < 5; i++)
  {
    cout << arr[i] << endl;
  }
  return 0;
}
