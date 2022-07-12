#include<bits/stdc++.h>
using namespace std;

int findMinVertex(vector<int> & weight  , vector<bool> visited ,int n) {
  int minWeight = INT_MAX;
  int minVertex;
  for (int i = 0; i < n; i++)
  {
    if(!visited[i] && weight[i] < minWeight) {
      minVertex = i;
      minWeight = weight[i];
    }
  }

  return minVertex;
}

void prims(vector<vector<int>> input , int n) {


// parent array
  int parent[n];
  parent[0] = 0;


// weight array
  vector<int> weight(n, INT_MAX);
  weight[0] = 0;

// visited array
  vector<bool> visited(n, false);

  for (int i = 0; i < n - 1;i++) {
    // get the min vertex.
    int minVertex = findMinVertex(weight, visited, n);
    visited[minVertex] = true;
    // explore all unvisited neighbours.
    for (int j = 0; j < n;j++) {
      if(input[minVertex][j] != 0 && !visited[j] ) {
        if(input[minVertex][j] < weight[j]){
          weight[j] = input[minVertex][j];
          parent[j] = minVertex;
        }
      }
    }
  }

  for (int i = 1; i < n;i++) {
    if(parent[i] < i) {
      cout << parent[i] << " " << i << " " << weight[i] << endl;
    } else {
      cout << i << " " << parent[i] << " " << weight[i] << endl;

    }
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

  prims(input, n);

  return 0;
}
