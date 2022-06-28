#include <bits/stdc++.h>
using namespace std;



int staircase(int n, int dp[])
{
  if (n == 0)
    return 1;
  if (n == 1 || n == 2)
    return n;
  if (dp[n] != -1)
    return dp[n];
  
  dp[n] = staircase(n - 1, dp) + staircase(n - 2, dp) + staircase(n - 3, dp);
  return dp[n];
}

int main()
{



  // write your code here
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;
    int dp[n + 1];
    for (int i = 0; i < n + 1;i++) {
      dp[i] = -1;
    }
      cout << staircase(n, dp) << endl;
  }
  return 0;
}