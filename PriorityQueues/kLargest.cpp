#include<iostream>
#include<vector>
#include<queue>
using namespace std;


vector<int> kLargest(int input[], int n, int k){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */

    priority_queue<int, vector<int>, greater<int> > pq;
    vector<int> ans;

    for (int i = 0; i < k;i++) {
      pq.push(input[i]);
    }

    for (int i = k; i < n;i++) {
      if(input[i] > pq.top()) {
        pq.pop();
        pq.push(input[i]);
      } else {
        continue;
      }
    }

    while(!pq.empty()) {
      ans.push_back(pq.top());
      pq.pop();
    }

    return ans;
}

int main() {
  int arr[] = {10, 4, 5, 3, 9, 33, 7};

  for(int i : kLargest(arr,7,5)) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
