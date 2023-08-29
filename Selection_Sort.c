#include <stdio.h>

void selection_sort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[min_index]) 
            {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void selectionSortDescending(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        int max_index = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] > arr[max_index]) 
            {
                max_index = j;
            }
        }
        // Swap the maximum element with the current element
        int temp = arr[i];
        arr[i] = arr[max_index];
        arr[max_index] = temp;
    }
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call selection_sort to sort the array
    selection_sort(arr, n);

    printf("\nascending array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    selectionSortDescending(arr, n);

    printf("\ndecending array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
