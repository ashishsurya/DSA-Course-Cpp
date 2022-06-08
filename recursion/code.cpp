#include<iostream>
using namespace std;

void removeConsecutiveDuplicates(char *input) {
	/* Don't write main().
	* Don't read input, it is passed as function argument.    
	* Change in the given string itself.
	* No need to return or print anything
	* Taking input and printing output is handled automatically.
	*/
    
    if (input[0] == '\0') return;
    
    removeConsecutiveDuplicates(input+1);
    if (input[0] != input[1]) {
        return;
    } else {
        int i=1;
        for(;input[i]!='\0';i++) {
            input[i] = input[i+1];
        }
        input[i-1] = input[i];
    }


}

int main(int argc, char const *argv[])
{
    cout << "Hello World" << endl;
    return 0;
}
