#include<iostream>
using namespace std;
#include<unordered_map>
void printIntersection(int arr1[], int arr2[], int n, int m) {
    unordered_map<int,int> map;
    
    // Write your code here
    for(int i=0;i<n;i++) {
        map[arr1[i]]++;
    }
    
    for(int i=0;i<m;i++) {
        if(map[arr2[i]]) {
            cout << arr2[i] << endl;
            map[arr2[i]]--;
        }else {
            continue;
        }
    }
}
int main() {
  
  return 0;
}
