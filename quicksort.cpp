#include<bits/stdc++.h>
using namespace std;
int a[1000000000];
void principle(int left, int right)
{
	int i=left, j=right;
	int pivot=a[(i+j)/2];
	while(left<right)
	{
		while (a[i]<pivot)
		    i++;
		while(a[j]>pivot)
		    j--;
		if(i<j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if(i<right)
        principle(i,right);
    if(j>left)
        principle(left,j);
}
void print(int arr[], int size)
{
	for(int i=0; i<size; i++)
		printf("%d", arr[i]);
	printf("\n");
}
int main()
{
	int my_arr[]={1, 3, 5, 4, 9, 2, 6};
	int a_size=sizeof(my_arr)/sizeof(my_arr[0]);
	cout<<"Your old array:"<<endl;
	print(my_arr, a_size);
	principle(0, 6);
	cout<<"Your sorted array:"<<endl;
	print(my_arr, a_size);
	return 0;
}
