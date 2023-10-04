#include<stdio.h>
void bubble (int arr[], int num)
{
	int i, j, temp;
	for (i=0; i<num-1;i++)
	{
		for (j=0; j<num-i-1; j++)
		{
			if (arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf ("the sorted array is:");
	for (i=0; i<num; i++)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	int i,j,temp,n;
	printf ("enter the number of array elements:");
	scanf("%d", &n);
	int arr[100];
	printf("enter the array elements: ");
	for (i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	bubble (arr, n);
	
	
	return 0;
}
