#include <bits/stdc++.h>
using namespace std;

void getPath(vector<vector<bool>> &edges, int start, int end, vector<bool> &visited, vector<int> &path)
{

  // BASE CASE.
  if (start == end)
  {
    path.push_back(start);
    return;
  }
  visited[start] = true;
  for (int i = 0; i < edges.size(); i++)
  {
    if (edges[start][i] && !visited[i])
    {
      getPath(edges, i, end, visited, path);
      if (path.size() > 0)
      {
        path.push_back(start);
        return;
      }
    }
  }
  return;
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

  int start, end;
  cin >> start >> end;

  vector<bool> visited(n, false);
  vector<int> path;

  getPath(edges, start, end, visited, path);

  for (int i : path)
  {
    cout << i << " ";
  }

  cout << endl;

  return 0;
}
