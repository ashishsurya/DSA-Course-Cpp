#include<iostream>
using namespace std;

int lastIndex(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
  if (size == 0)
    return -1;

  int ans = lastIndex(input + 1, size - 1, x);
  if (ans == -1) {
    if (input[0] == x) {
      return 0;
    } else {
      return -1;
    }
  } else {
    return ans + 1;
  }
}

int main(int argc, char const *argv[])
{
  int a[] = {1, 3, 3, 1, 5};

  cout << lastIndex(a, 5, 1) << endl;

  return 0;
}
