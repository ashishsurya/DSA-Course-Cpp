#include <bits/stdc++.h>
using namespace std;

int minCostPath_BU(int **input, int m, int n, vector<vector<int>> &dp)
{

  // fill the last element.
  dp[m - 1][n - 1] = input[m - 1][n - 1];

  // fil the last row (left to right).
  for (int j = n - 2; j >= 0; j--)
  {
    dp[m - 1][j] = dp[m - 1][j + 1] + input[m - 1][j];
  }

  // fill last column
  for (int i = m - 2; i >= 0; i--)
  {
    dp[i][n - 1] = dp[i + 1][n - 1] + input[i][n - 1];
  }

  // fill the remaining dp matrix
  for (int i = m - 2; i >= 0; i--)
  {
    for (int j = n - 2; j >= 0; j--)
    {
      dp[i][j] = min(dp[i + 1][j + 1], min(dp[i + 1][j], dp[i][j + 1]));
    }
  }

  return dp[0][0];
}

int minCostPath(int **input, int m, int n)
{
  // Write your code here
  vector<vector<int>> dp(m, vector<int>(n, -1));
  return minCostPath_BU(input, m, n, dp);
}