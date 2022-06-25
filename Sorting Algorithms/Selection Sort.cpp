#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int min_index = i;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[min_index] > arr[j])
      {
        min_index = j;
      }
    }
    swap(arr[i], arr[min_index]);
  }
}

int main()
{
  int arr[] = {1, 3, 5, 6, 2};

  selectionSort(arr, 5);
  for (int i = 0; i < 5; i++)
  {
    cout << arr[i] << endl;
  }
  return 0;
}
