#include <bits/stdc++.h>
using namespace std;

int lcs_dp(string s, string t)
{
  vector<vector<int>> output(s.size() + 1, vector<int>(t.size() + 1));

  // fill the 1st column
  for (int i = 0; i < s.size() + 1; i++)
  {
    output[i][0] = 0;
  }

  // fill the 1st row
  for (int i = 0; i < s.size() + 1; i++)
  {
    output[0][i] = 0;
  }

  // fill the remaining matrix
  for (int i = 1; i < s.size() + 1;i++){
    for (int j = 1; j < t.size()+1; j++)
    {
      if(s[s.size() - i] == t[t.size()-j]) {
        output[i][j] = 1 + output[i - 1][j - 1];
      } else {
        output[i][j] = max(output[i - 1][j - 1], max(output[i - 1][j], output[i][j - 1]));
      }
    }
    
  }

  return output[s.size()][t.size()];
}

int lcs_memo(string s, string t, vector<vector<int>> &dp)
{
  int r = s.size();
  int c = t.size();
  if (s.size() == 0 || t.size() == 0)
  {
    return 0;
  }

  // check if ans already exits.
  if (dp[r][c] != -1)
  {
    return dp[r][c];
  }

  if (s[0] == t[0])
  {
    dp[r][c] = 1 + lcs_memo(s.substr(1), t.substr(1), dp);
    return dp[r][c];
  }
  else
  {
    int x = lcs_memo(s, t.substr(1), dp);
    int y = lcs_memo(s.substr(1), t, dp);
    int z = lcs_memo(s.substr(1), t.substr(1), dp);

    dp[r][c] = max(x, max(y, z));

    return dp[r][c];
  }
}

int lcs_memo(string s, string t)
{
  vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));

  return lcs_memo(s, t, dp);
}

int lcs(string s, string t)
{
  // base case
  if (s.size() == 0 || t.size() == 0)
  {
    return 0;
  }

  if (s[0] == t[0])
  {
    return 1 + lcs(s.substr(1), t.substr(1));
  }
  else
  {
    int x = lcs(s, t.substr(1));
    int y = lcs(s.substr(1), t);
    int z = lcs(s.substr(1), t.substr(1));

    return max(x, max(y, z));
  }
}

int main()
{

  string s, t;
  cin >> s >> t;

  cout << lcs(s, t) << endl;
  cout << lcs_memo(s, t) << endl;
  cout << lcs_dp(s, t) << endl;

  return 0;
}
