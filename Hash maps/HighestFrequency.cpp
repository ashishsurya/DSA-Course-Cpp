#include<iostream>
#include<unordered_map>
using namespace std;

int highestFrequency(int arr[], int n) {
    // Write your code here
    unordered_map<int, int> m;
    for (int i = 0; i < n;i++) {
      m[arr[i]]++;
    }
    int ans = arr[0];
    for (int i = 0; i < n;i++) {
      if(m[arr[i]] > m[ans]) {
        ans = arr[i];
      }
    }
    
    return ans;
}

int main() {
  int arr[] = {2, 2, 3, 3,3, 4};
  int n = 6;
  cout << highestFrequency(arr, n);
  return 0;
}
