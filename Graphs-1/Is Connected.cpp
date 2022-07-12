#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<bool>> &edges, vector<bool> &visited, int sv)
{
  visited[sv] = true;
  for (int i = 0; i < edges.size(); i++)
  {
    if (i == sv)
    {
      continue;
    }
    if (edges[sv][i] && !visited[i])
    {
      visited[i] = true;
      dfs(edges, visited, i);
    }
  }
}

int main()
{

  int n, e;
  cin >> n >> e;
  vector<vector<bool>> edges(n, vector<bool>(n, false));

  for (int i = 0; i < e; i++)
  {
    int f, s;
    cin >> f >> s;
    edges[f][s] = true;
    edges[s][f] = true;
  }

  vector<bool> visited(n, false);

  dfs(edges, visited, 0);
  for (bool i : visited)
  {
    if (!i)
    {
      cout << "false" << endl;
      return 0;
    }
  }
  cout << "true" << endl;
  return 0;
}
