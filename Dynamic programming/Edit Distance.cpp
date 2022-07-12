#include <bits/stdc++.h>
using namespace std;

int editDistance_TD(string s, string t, vector<vector<int>> &dp)
{
  
  int r = s.size();
  int c = t.size();
  if (r == 0 || c == 0)
  {
    return max(r, c);
  }

  if (dp[r][c] != -1)
  {
    return dp[r][c];
  }

  if (s[0] == t[0])
  {
    dp[r][c] = editDistance_TD(s.substr(1) , t.substr(1),dp);
    return dp[r][c];
  }
  else
  {
    int x = 1 + editDistance_TD(s , t.substr(1) , dp);
    int y = 1 + editDistance_TD(s.substr(1) , t , dp);
    int z = 1 + editDistance_TD(s.substr(1) , t.substr(1) , dp);

    dp[r][c] = min(x, min(y, z));

    return dp[r][c];
  }
}

int editDistance_TD(string s, string t)
{
  vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
  return editDistance_TD(s, t, dp);
}

int editdistance(string s, string t)
{
  if (s.size() == 0)
    return t.size();
  if (t.size() == 0)
  {
    return s.size();
  }

  if (s[0] == t[0])
  {
    return editdistance(s.substr(1), t.substr(1));
  }

  // INSERT
  int x = 1 + editdistance(s.substr(1), t);

  // DELETE
  int y = 1 + editdistance(s, t.substr(1));

  // UPDATE
  int z = 1 + editdistance(s.substr(1), t.substr(1));

  return min(x, min(y, z));
}

int main()
{
  string s, t;
  cin >> s >> t;
  cout << editdistance(s, t) << endl;
  cout << editDistance_TD(s, t) << endl;
  return 0;
}
