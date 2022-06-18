#include<iostream>
using namespace std;
#include<unordered_map>
int pairSum(int *arr, int n) {
	// Write your code here
    int count = 0;
    unordered_map<int,int> map;
    for(int i=0;i<n;i++){
        if(map[0-arr[i]]) {
            count += map[0-arr[i]];
        }
        map[arr[i]]++;
        
    }
    return count;
}
int main() {
  
  return 0;
}
