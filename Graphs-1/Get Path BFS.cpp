#include <bits/stdc++.h>
using namespace std;

vector<int> hasPath(vector<vector<bool>> &edges, int start, int end, vector<bool> &visited, unordered_map<int, int> &parent)
{
  queue<int> q;
  q.push(start);
  visited[start] = true;
  while (!q.empty())
  {
    int currvertex = q.front();
    q.pop();
    for (int i = 0; i < edges.size(); i++)
    {
      if (edges[currvertex][i] && !visited[i])
      {
        visited[i] = true;
        q.push(i);
        parent[i] = currvertex;
        if (i == end)
        {
          vector<int> ans;
          ans.push_back(end);
          ans.push_back(parent[end]);
          int x = parent[parent[end]];
          while(x != -1) {
            ans.push_back(x);
            x = parent[x];
          }
          return ans;
        }
      }
    }
  }

  return vector<int>(0);
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
  unordered_map<int, int> parent;
  parent[start] = -1;
  vector<int> path = hasPath(edges, start, end, visited, parent);
  for(int i:path) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
