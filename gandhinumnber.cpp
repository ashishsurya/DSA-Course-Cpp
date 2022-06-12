#include <iostream>
#include<cmath>
using namespace std;

int sumOfFourthPower(int n) {
	if (n == 0) return 0;
	return sumOfFourthPower(n/10) + pow(n%10 , 4);
}

bool checkGandhiNumber(int n) {
	
	return n == sumOfFourthPower(n);
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "sdvvd" << endl;
	cin >> n;
	cout << (checkGandhiNumber(n) ? "True" : "False") << endl;
	return 0;
}