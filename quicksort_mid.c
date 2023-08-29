#include <stdio.h>

void quicksort(int arr[], int l, int h) {
    int pivot, i, j, temp;
    if (l < h) {
        int mid = (l + h) / 2; // Calculate the middle index
        pivot = mid; // Change the pivot to the middle element
        i = l;
        j = h;
        while (i <= j) {
            while (arr[i] < arr[pivot]) {
                i++;
            }
            while (arr[j] > arr[pivot]) {
                j--;
            }
            if (i <= j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }
        if (l < j) {
            quicksort(arr, l, j); // Recurse on the left partition
        }
        if (i < h) {
            quicksort(arr, i, h); // Recurse on the right partition
        }
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
