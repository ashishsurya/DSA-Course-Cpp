#include<iostream>
using namespace std;

void merge(int a[], int si, int ei) {
  int size = ei - si + 1;
  int *b = new int[size];
  int mid = (si + ei) / 2;
  int i = si, j = mid + 1;
  int k = 0;


  while(i <= mid && j <=ei) {
    if (a[i] < a[j]){
      b[k] = a[i];
      i++;
      k++;
    } else {
      b[k] = a[j];
      j++;
      k++;
    }
  }

  while(i<=mid) {
    b[k] = a[i];
    k++;
    i++;
  }
  while(j<=ei) {
  b[k] = a[j];
  k++;
  j++;
  }

  int m = 0;
  for (int x = si; x <= ei;x++){
    a[x] = b[m];
    m++;
  }
  delete [] b;
}

void mergeSort(int a[], int si, int ei) {
  if(si>=ei)
    return;

  int mid = (ei + si) / 2;

  mergeSort(a, si, mid);
  mergeSort(a, mid + 1, ei);
  merge(a, si, ei);
}

int main(int argc, char const *argv[])
{
  /* code */

  int a[] = {5, 4, 3, 2, 1};
  // for(int i:a)
  //   cout << i << endl;
  mergeSort(a, 0,4);
  for (int i = 0; i < 5;i++) {
    cout << a[i] << endl;
  }
    return 0;
}
