#include <bits/stdc++.h>
using namespace std;

int helper(int n, int dp[])
{
  // Write your code here
  if (n <= 3)
    return n;

  if (dp[n] != INT_MAX)
  {
    return dp[n];
  }

  for (int i = 1; i * i <= n; i++)
  {
    dp[n] = min(dp[n], 1 + helper(n - i * i, dp));
  }

  return dp[n];
}


int minCount(int n)
{
  int dp[n + 1];
  for (int i = 0; i < n + 1; i++)
  {
    dp[i] = INT_MAX;
  }
  return helper(n, dp);
}


int main()
{
  int n;
  cin >> n;
  cout << minCount(n) << endl;
  return 0;
}
