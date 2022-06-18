#include<iostream>
#include<vector>

using namespace std;

vector<int> performOps(vector<int> A) {
    vector<int> B(2 * A.size(), 0);
    for (int i = 0; i < A.size(); i++) {
        B[i] = A[i];
        B[i + A.size()] = A[(A.size() - i) % A.size()];
    }
    return B;
}

int main() {
    vector<int> A;
    A.push_back(5);
    A.push_back(10);
    A.push_back(2);
    A.push_back(1);

    vector<int> B = performOps(A);
    for (int i = 0; i < B.size(); i++)
    {
        cout << B[i] << " ";
}
    return 0;
}
