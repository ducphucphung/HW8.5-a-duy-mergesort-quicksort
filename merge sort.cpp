#include<bits/stdc++.h>
using namespace std;
int a[1000000000];
void principle(int a[], int start, int mid, int end)
{
	int n1=mid-start+1;
	int n2=end-start;
	int left[n1];
	int right[n2];
	for (int i=0; i<n1; i++)
	{
		left[i]=a[start+i];
	}
	for (int j=0; j<n2; j++)
	{
		right[j]=a[mid+j];
	}
	int x=0, y=0;
	int k=start;
	while(x<n1 && y<n2);
	{
		if (left[x] >= right[y])
		{
			a[k]=right[y];
			y++;
		}
		else
		{
			a[k]=left[x];
			x++;
		}
		k++;
	}
	while(x<n1)
	{
		a[k]=left[x];
		x++;
		k++;
	}
	while(x<n2)
	{
		a[k]=right[y];
		y++;
		k++;
	}
}
void mergesort(int a[], int left, int right)
{
    int mid;    
    if(left<right)
	{             
        mid =(left+right)/2;    
        mergesort(a,left,mid);  
        mergesort(a,mid + 1,right);   
        principle(a,left, mid ,right);   
    }
	else
	{
		return;
	}
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
	mergesort(my_arr, 0, a_size-1);
	cout<<"Your sorted array:"<<endl;
	print(my_arr, a_size);
	return 0;
}

