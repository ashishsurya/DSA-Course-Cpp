#include<iostream>
#include<string.h>
using namespace std;

bool isPalindrome(char input[], int low, int high) {
  cout << low << " " << high << endl;
  if (low == high)
    return true;

  if (input[low] == input[high])
  {
    return true && isPalindrome(input, low + 1, high - 1);
    } else {
        return false;
    }
}

bool checkPalindrome(char input[]) {
    // Write your code here
    int size = strlen(input);

    return isPalindrome(input, 0, size - 1);
    

    
}


int main(int argc, char const *argv[])
{
  char s[] = "racecar";
  string ans = checkPalindrome(s) ? "True" : "False";
  cout << ans << endl;
  return 0;
}
