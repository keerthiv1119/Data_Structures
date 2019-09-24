/*
Author Name : Keerthi
ID : N!51119
Date : 18-09-2019
*/
#include<stdio.h>

int partition(int arr[],int low,int high)
{
	int i = (low - 1);
	int pivot = arr[high];
	int j, temp , temp1;
	for(j = low;j <= high-1;j++)
	{
		if(arr[j] < pivot)
		{
			i = i+1;
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
	temp1 = arr[i+1];
	arr[i+1] = arr[high];
	arr[high] = temp1;
	return (i+1);
}

void Quick_Sort(int arr[],int low,int high)
{
	int pivot_index;
	if(low < high)
	{
		pivot_index = partition(arr,low,high);
		Quick_Sort(arr, low, pivot_index - 1);
		Quick_Sort(arr, pivot_index + 1, high);
	}
}
int main()
{
	int i,n;
	printf("Enter the Size of the array");
	scanf("%d",&n);
	int array[n];
	for(i = 0 ;i < n; i++)
	{
		scanf("%d",&array[i]);
	}
	Quick_Sort(array , 0 , n-1);
	for(i=0;i<n;i++)
	{
		printf("Sorted array is : %d\t",array[i]);
	}
}
