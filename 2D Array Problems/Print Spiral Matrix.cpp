#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(const vector<vector<int> > &A) {
    int L=0,R=A[0].size()-1,T=0,B=A.size()-1;
    
    int dir = 0;
    
    vector<int> ans;
    
    while(L <= R && T <= B) {
        // left to right
        if (dir == 0) {
            for(int i=L;i<=R;i++) {
                ans.push_back(A[T][i]);
            }
            dir = 1;
            T--;
        } else if (dir == 1) { // top to bottom
            for(int i=T;i<=B;i++) {
                ans.push_back(A[i][R]);
            }
            dir = 2;
            R--;
        } else if (dir == 2) { // right to left
            for(int i=R;i>=L;i--) {
                ans.push_back(A[B][i]);
            }
            dir = 3;
            B++;            
        } else { // bottpm to top
            for(int i=B;i>=T;i--) {
                ans.push_back(A[i][L]);
            }
            dir = 1;
            L++;
        }
    }
    return ans;
}


int main() {

  
  
  return 0;
}
