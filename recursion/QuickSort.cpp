#include <iostream>
using namespace std;

int partition(int a[], int si, int ei)
{
  int pivot = a[si]; // chooosing pivot.
  int smallerCount = 0;
  for (int i = si + 1; i <= ei; i++)
  {
    if (a[i] <= pivot)
    {
      smallerCount++;
    }
  }
  int pi = si + smallerCount; // calculating pivot index.

  int temp = a[si];
  a[si] = a[pi];
  a[pi] = pivot;

  int i = si, j = ei;
  while (i <= pi && j >= pi)
  {
    while (a[i] <= pivot)
    {
      i++;
    }
    while (a[j] > pivot)
    {
      j--;
    }
    if (i < pi && j > pi)
    {
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
      i++;
      j--;
    }
  }

  return pi;
}

void quickSort(int a[], int si, int ei)
{
  if (si >= ei)
  {
    return;
  }

  int pi = partition(a, si, ei);
  quickSort(a, si, pi - 1);
  quickSort(a, pi + 1, ei);
}

int main()
{
  int a[] = {5, 3, 8, 7, 2, 1};
  quickSort(a, 0, 5);
  for (int i = 0; i < 6; i++)
  {
    cout << a[i] << endl;
  }
  return 0;
}