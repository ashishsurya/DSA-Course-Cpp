#include<iostream>
using namespace std;

int firstIndex(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    
    if (input[0] == x) return 0;
    if (size == 0)
      return -1;

    int ans = firstIndex(input + 1, size - 1, x);
    if (ans == -1) {
      return ans;
    } else {
      return ans + 1;
    }
}


int main(int argc, char const *argv[])
{
  int a[] = {1, 3, 3, 1, 5};

  cout << firstIndex(a, 5, 1) << endl;

  return 0;
}
