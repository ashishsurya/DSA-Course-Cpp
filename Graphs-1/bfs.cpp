#include <bits/stdc++.h>
using namespace std;

// BFS FOR UNDIRECTED AND DISCONNECTED GRAPH


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

  queue<int> q;

  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {

      q.push(i);
      visited[i] = true;

      while (!q.empty())
      {
        int currentVertex = q.front();
        q.pop();
        cout << currentVertex << " ";
        for (int i = 0; i < n; i++)
        {
          if (edges[currentVertex][i] && !visited[i])
          {
            q.push(i);
            visited[i] = true;
          }
        }
      }
    }
  }

  return 0;
}
