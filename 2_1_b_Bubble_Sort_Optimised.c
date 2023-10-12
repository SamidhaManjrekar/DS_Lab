#include<stdio.h>
int main()
{
	int i,j,temp,n, flag, count=0, swap=0;
	printf ("Enter the number of array elements: ");
	scanf("%d", &n);
	int arr[100];
	printf("Enter the array elements: \n");
	for (i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (i=0; i<n-1;i++)
	{
		flag = 1;
		count ++;
		for (j=0; j<n-i-1; j++)
		{
			if (arr[j]>arr[j+1])
			{
				flag= 0;
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				swap++;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
	
	printf ("The sorted array is: ");
	for (i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
    printf("\nThe number of swaps: %d", swap);
    printf("\nThe number of iteration: %d", count);
	return 0;
}
