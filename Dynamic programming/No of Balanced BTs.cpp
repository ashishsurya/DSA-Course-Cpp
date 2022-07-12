#include<bits/stdc++.h>
using namespace std;

// T(n) = T(n-1) + T(n-2);

int noofbalancedBts(int n){
  if(n <=1)
    return 1;

  int mod = (int)(pow(10, 9)) + 7;

  int x = noofbalancedBts(n - 1);
  int y = noofbalancedBts(n - 2);

  int temp1 = (int)(((long)x * x) % mod);
  int temp2 = (int)((2*(long)x*y) % mod);

  int ans = (temp1 + temp2) % mod;
  

  return ans;
}

int main() {

  int n;
  cin >> n;
  cout << noofbalancedBts(n) << endl;

  return 0;
}
