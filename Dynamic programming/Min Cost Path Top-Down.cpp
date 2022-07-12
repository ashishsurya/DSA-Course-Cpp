#include <bits/stdc++.h>
using namespace std;

int minCostPath_TD(int **input, int m, int n, int r, int c, vector<vector<int>> &dp)
{
  if (r == m - 1 && c == n - 1)
  {
    return input[r][c];
  }

  if(r >= m || c >= n) {
    return INT_MAX;
  }

  // check if value already computed
  if(dp[r][c] != -1) {
    return dp[r][c];
  }

  int x = minCostPath_TD(input, m, n, r, c + 1 , dp);

  int y = minCostPath_TD(input, m, n, r + 1, c + 1, dp);

  int z = minCostPath_TD(input, m, n, r + 1, c , dp);

  dp[r][c] = input[r][c] + min(x, min(y, z));
  return dp[r][c];
}

int minCostPath(int **input, int m, int n)
{
  // Write your code here
  vector<vector<int>> dp(m, vector<int>(n, -1));
  return minCostPath_TD(input, m, n, 0, 0 , dp);
}