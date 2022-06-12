#include<iostream>
#include<queue>
using namespace std;

vector<int> kSmallest(int arr[], int n, int k) {
    // Write your code here
    vector<int> ans;

    priority_queue<int> pq;
    for (int i = 0; i < k;i++) {
      pq.push(arr[i]);
    }

    for (int i = k; i < n;i++) {
      if(arr[i] < pq.top()) {
        pq.pop();
        pq.push(arr[i]);
      } else {
        continue;
      }
    }
    
    while (!pq.empty()) {
      ans.push_back(pq.top());
      pq.pop();
    }

    return ans;
}

int main() {

  int arr[] = {10, 4, 5, 3, 9, 33, 7};

  for(int i : kSmallest(arr,7,5)) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
