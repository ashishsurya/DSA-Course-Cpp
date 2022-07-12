#include <bits/stdc++.h>
using namespace std;

int helper(int **input, int m, int n, int r, int c)
{
  if (r == m - 1 && c == n - 1)
  {
    return input[r][c];
  }

  if(r >= m || c >= n) {
    return INT_MAX;
  }

  int x = helper(input, m, n, r, c + 1);

  int y = helper(input, m, n, r + 1, c + 1);

  int z = helper(input, m, n, r + 1, c);

  return input[r][c] + min(x, min(y, z));
}

int minCostPath(int **input, int m, int n)
{
  // Write your code here
  return helper(input, m, n, 0, 0);
}