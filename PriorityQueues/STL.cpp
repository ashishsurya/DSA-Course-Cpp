#include <bits/stdc++.h>
using namespace std;



class Edge {
  public:
    int u;
    int v;
    int w;

  Edge(int x,int y,int z) {
    u = x;
    v = y;
    w = z;
  }
};


bool comp (pair<string,int> a, pair<string,int> b) {
  if(a.second == b.second)
    return a.first.size() > b.first.size();
  return a.second < b.second;
}

int main()
{

  priority_queue<pair<string,int> , vector<pair<string,int>> , function<bool(pair<string,int>,pair<string,int>)>> edgeHeap(comp);

  edgeHeap.push({"i", 2});
  edgeHeap.push({"love", 2});
  edgeHeap.push({"leetcode", 1});
  edgeHeap.push({"coding", 1});




  while(!edgeHeap.empty()) {
    pair<string,int> top = edgeHeap.top();
    cout << top.first << " " << top.second << endl;
    edgeHeap.pop();
  }

  return 0;
}
