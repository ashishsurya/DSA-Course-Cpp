#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int si, int ei)
{
  int size = ei - si + 1;
  int mid = (si + ei) / 2;

  // create a new array to merge elements into it
  int *b = new int[size];

  int i = si, j = mid + 1;
  int k = 0;
  while (i <= mid && j <= ei)
  {
    if (arr[i] < arr[j])
    {
      b[k] = arr[i];
      i++;
      k++;
    }
    else
    {
      b[k] = arr[j];
      j++;
      k++;
    }
  }

  while (i <= mid)
  {
    b[k] = arr[i];
    i++;
    k++;
  }

  while (j <= ei)
  {
    b[k] = arr[j];
    j++;
    k++;
  }
  int m = 0;
  for (int x = si; x <= ei; x++)
  {
    arr[x] = b[m];
    m++;
  }
}

void mergeSort(int arr[], int si, int ei)
{
  if (si >= ei)
    return;

  // calculate mid;
  int mid = (si + ei) / 2;
  // calling mergesort on left part
  mergeSort(arr, si, mid);
  // callling mergesort on right part
  mergeSort(arr, mid + 1, ei);

  // merging both left and right parts
  merge(arr, si, ei);
}

int main()
{
  int arr[] = {1, 3, 5, 6, 2};

  mergeSort(arr, 0, 4);
  for (int i = 0; i < 5; i++)
  {
    cout << arr[i] << endl;
  }

  return 0;
}
