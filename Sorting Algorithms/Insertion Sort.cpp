#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
  for (int i = 1; i < n; i++)
  {
    int value = arr[i];
    int index = i-1;
    while (index >= 0 && arr[index] > value)
    {
      arr[index + 1] = arr[index];
      index--;
    }
    arr[index + 1] = value;
  }
}

int main()
{
  int arr[] = {1, 3, 5, 6, 2};
  int n = 5;
  insertionSort(arr, n);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << endl;
  }

  return 0;
}
