#include<bits/stdc++.h>
using namespace std;

double geometricSum(int k) {
    // Write your code here
	if (k == 0) return 1;
    return (1 / pow(2, k)) + geometricSum(k-1);
}



 int main(int argc, char const *argv[])
 {
   cout << geometricSum(2) << endl;
  return 0;
 }
 