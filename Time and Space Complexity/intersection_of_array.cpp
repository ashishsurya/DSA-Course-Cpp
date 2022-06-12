#include <iostream>
#include <algorithm>
using namespace std;

void intersection(int input1[], int input2[], int size1, int size2) {
   
    sort(input1 ,input1+size1);
    sort(input2 ,input2+size2);
  int i=0,j=0;
    while(i<size1 && j<size2)
    {
            if(input1[i]<input2[j])
                i++;
            else if(input1[i]>input2[j])
                j++;
            else if(input1[i]==input2[j])
            {
                cout<<input1[i]<<endl;
                i++;
                j++;
                
            }
     } 
       
   


}

int tripletSum(int *arr, int n, int num)
{
    int ans = 0;
	//Write your code here
    for (int i = 0; i < n-2; i++)
{
for (int j = i + 1; j < n – 1; j++)
{
for (int k = j + 1; k < n; k++)
{
if (arr[i] + arr[j] + arr[k] == num)
{
ans++;
}
}
}
}
    
    return ans;

}

int main()
{
	// int t;
	// cin >> t;
	// while (t--)
	// {

	// 	int size1, size2;

	// 	cin >> size1;
	// 	int *input1 = new int[size1];

	// 	for (int i = 0; i < size1; i++)
	// 	{
	// 		cin >> input1[i];
	// 	}

	// 	cin >> size2;
	// 	int *input2 = new int[size2];

	// 	for (int i = 0; i < size2; i++)
	// 	{
	// 		cin >> input2[i];
	// 	}

	// 	intersection(input1, input2, size1, size2);
		
	// 	delete[] input1;
	// 	delete[] input2;
		
	// 	cout << endl;
	// }

  int a[] = {1,2,3,4,5};

  bool is_present = binary_search(a, a + 5, 5);

  cout << is_present << endl;

  return 0;
}