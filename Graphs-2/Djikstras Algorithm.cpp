#include<bits/stdc++.h>
using namespace std;

int findMinVertex(vector<int> & dist , vector<bool>& visited ,int n) {
  int minDis = INT_MAX;
  int minVertex;
  for (int i = 0; i < n;i++) {
    if(!visited[i] && dist[i] < minDis ) {
      minDis = dist[i];
      minVertex = i;
    }
  }

  return minVertex;
}

void djikstras(vector<vector<int>> & input , int n) {
  vector<int> dist(n, INT_MAX); // to keep track of min_distance of vertex i from vertex 0.
  dist[0] = 0;
  vector<bool> visited(n, false);

  for (int i = 0; i < n-1;i++) {
    int minVertex = findMinVertex(dist, visited , n);
    visited[minVertex] = true;

    // Explore all unvisited neighbours.
    for (int j = 0; j < n;j++) {
      if(input[minVertex][j] != 0 && !visited[j]) {
        dist[j] = min(dist[minVertex] + input[minVertex][j], dist[j]);
      }
    }
  }

  for (int i = 0; i < n;i++) {
    cout << i << " " << dist[i] << endl;
  }
}

int main() {
  int n, e;
  cin >> n >> e;
  vector<vector<int>> input(n, vector<int>(n, 0));

  for (int i = 0; i < e;i++){
    int u, v, w;
    cin >> u >> v >> w;
    input[u][v] = input[v][u] = w;
  }

  djikstras(input, n);

  return 0;
}
