// #include <iostream>
// #include <string>
// #include<stack>
// using namespace std;
// bool checkRedundantBrackets(string exp) {
//     // Write your code here
//     stack<char> s;
//     int count;
//     int i=0;
//     int len =exp.size();
//    while(i < len) {
//        int count = 0;
//         while(i<len && (exp[i]!=')')) {
//             s.push(exp[i]);
//             i++;
//         }
//        i =i-1;
//        while(exp[i]!='(') {
//            s.pop();
//            count++;
//            i--;
//        }
//        s.pop();
//        if (count==0) return true;
//        else i = i + count + 2;
//    }
//     return false;
// }





// int main() {
//     string input;
//     cin >> input;
//     cout << ((checkRedundantBrackets(input)) ? "true" : "false");
// }


// #include<iostream>
// using namespace std;

// int main() {
//   int m,n;
//   cin >> m >> n;
//   cout << m + n;
//   return 0;
// }



/* Read input from STDIN. Print your output to STDOUT*/
/* Read input from STDIN. Print your output to STDOUT*/
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int getAmount(vector<int> arr, int n, int g) {
    sort(arr.begin(),arr.end());
    int ans = 0;
    for(int i=0;i<n;i++) {
        ans += arr.at(i);
    }

    return ans;
}



int main(int argc, char *a[])
{
    //Write code here
    int t;
    cin >> t;
    while(t--) {
        int n,g;
        cin >> n >> g;
        vector<int> arr(g);
        for(int i=0;i<g;i++) {
            cin >> arr[i];
        }

        cout << getAmount(arr, n, g) << endl;
        
    }
}
