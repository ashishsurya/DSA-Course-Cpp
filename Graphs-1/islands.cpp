#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<bool>> &edges, vector<bool> &visited, vector<int> &component, int sv)
{
  visited[sv] = true;
  component.push_back(sv);

  for (int i = 0; i < edges.size(); i++)
  {
    if (i == sv)
    {
      continue;
    }
    if (edges[sv][i] && !visited[i])
    {
      visited[i] = true;
      dfs(edges, visited, component, i);
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

  // each vector represents one component.;
  vector<vector<int>> components;

  // do a dfs on all nodes.;
  for (int i = 0; i < n; i++)
  {

    // to store the current component;
    vector<int> component;
    if (!visited[i])
    {
      dfs(edges, visited, component, i);
    }

    if (component.size() > 0)
    {
      sort(component.begin(), component.end());
      components.push_back(component);
    }
  }

  cout << components.size() << endl;

  return 0;
}
