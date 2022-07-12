#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
  int start;
  int destination;
  int weight;
};

bool compare(Edge a,Edge b) {
  return a.weight < b.weight;
}

int findParent(int v , vector<int> parent) {
  if(v == parent[v]) {
    return parent[v];
  }

  return findParent(parent[v], parent);
}

void kruskals(vector<Edge> &input, int n)
{
  // sort the input
  sort(input.begin(), input.end(),compare);

  vector<Edge> output(n - 1);

  vector<int> parent(n);
  for (int i = 0; i < n;i++) {
    parent[i] = i;
  }

  

  int count = 0;
  int i = 0;
  while (count != n - 1)
  {
    Edge curr = input[i];
    
    // TO BE IMPLEMENTED
    int sourceParent = findParent(curr.start, parent);
    int destinationParent = findParent(curr.destination, parent);

    if(sourceParent != destinationParent) {
      output[count] = curr;
      parent[sourceParent] = destinationParent;
      count++;
    }
    i++;
  }

  for (int i = 0; i < n - 1;i++) {
    if(output[i].start < output[i].destination) {
    cout << output[i].start << " " << output[i].destination << " " << output[i].weight << endl;
    } else {
    cout << output[i].destination << " " << output[i].start << " " << output[i].weight << endl;

    }
  }
}

int main()
{

  int n, e;
  cin >> n >> e;
  vector<Edge> input(e);

  // take input
  for (int i = 0; i < e; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    input[i].start = u;
    input[i].destination = v;
    input[i].weight = w;
  }

 

  kruskals(input, n);

  return 0;
}
