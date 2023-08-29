#include <stdio.h>

void quicksort(int arr[], int l, int h) 
{
    int pivot, i, j, temp;
    if (l < h) 
    {
        pivot = h; // Change the pivot to the last element
        i = l;
        j = h - 1; // Modify j to be the second last element
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
        temp = arr[i];
        arr[i] = arr[pivot];
        arr[pivot] = temp;
        quicksort(arr, l, i - 1); // Recurse on the left partition
        quicksort(arr, i + 1, h); // Recurse on the right partition
    }
}

int main() {
    int n, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr1[n];

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    quicksort(arr1, 0, n - 1);

    printf("After sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }

    return 0;
}
