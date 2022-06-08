#include<iostream>
using namespace std;

int subset(int a[], int size, int b[][20]) {
  if (size <= 0) {
    b[0][0] = 0;
    return 1;
  }



  int smallsize = subset(a + 1, size - 1, b);
  for (int i = 0; i < smallsize;i++) {
    int col = b[i][0] + 1;
    b[i + smallsize][0] = col;
    b[i + smallsize][1] = a[0];

    for (int j = 2; j < col+1;j++) {
      b[i + smallsize][j] = b[i][j - 1];
    }
  }

  return 2 * smallsize;
}

int main(int argc, char const *argv[])
{
  int b[35000][20];
  int a[] = {15, 20, 12};

  int size = subset(a, 3, b);

  for (int i = 0; i < size;i++) {
    for (int j = 1; j <= b[0][0];j++) {
      cout << b[i][j] << endl;
    }
  }

  cout << "gkg" << endl;
  return 0;
}
