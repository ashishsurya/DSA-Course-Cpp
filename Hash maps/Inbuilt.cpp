#include<iostream>
#include<vector>
using namespace std;

int main() {
  vector<int> v(5, NULL);
for(int i:v) {
  if(i==0)
    cout << i << endl;
}
  return 0;
}
