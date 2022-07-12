#include<bits/stdc++.h>
using namespace std;

bool hasPath(vector<vector<bool>>& edges, int n, int x , int y,vector<bool>& visited) {
  if (x == y || edges[x][y])
    return true;
  visited[x] = true;
  for (int i = 0; i < n;i++){
    if(edges[x][i] && !visited[i]){
      return hasPath(edges, n, i, y, visited) || false;
    }
  }

  return false;
}

int main() {

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

  int x, y;
  cin >> x >> y;


  vector<bool> visited(n, false);

  cout << (hasPath(edges, n, x, y, visited) ? "true" : "false") << endl;

  return 0;
}
