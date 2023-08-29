#include <stdio.h>

void quicksort(int arr[], int l, int h) 
{
    int pivot, i, j, temp;
    if (l < h) 
    {
        pivot = l;
        i = l;
        j = h;
        while (i <= j) 
        {
            while (arr[i] <= arr[pivot] && i <= h) 
            {
                i++;
            }
            while (arr[j] > arr[pivot] && j >= l) 
            {
                j--;
            }
            if (i < j) 
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[j];
        arr[j] = arr[pivot];
        arr[pivot] = temp;
        quicksort(arr, l, j - 1);
        quicksort(arr, j + 1, h);
    }
}

int main() 
{
    int n, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr1[n];

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr1[i]);
    }

    quicksort(arr1, 0, n - 1);

    printf("After sorting:\n");
    for (i = 0; i < n; i++) 
    {
        printf("%d ", arr1[i]);
    }

    return 0;
}