#include <stdio.h>

int binary_search_recursive(int arr[], int l, int h, int k) {
    while (l <= h) {
        int mid = (l + h) / 2;
        if (arr[mid] == k)
            return mid;
        else if (k < arr[mid])
            binary_search_recursive(arr, l, mid-1, k);
        else
            binary_search_recursive(arr, mid+1, h, k);
    }
    return -1;
}

int main() {
    int arr[100], key, i, j, num, temp;
    printf("Enter number of elements: ");
    scanf("%d", &num);

    printf("Enter %d numbers\n", num);
    for (i = 0; i < num; i++)
        scanf("%d", &arr[i]);

    printf("Enter a number that you would like to search: ");
    scanf("%d", &key);

    // Bubble sort to sort the array
    for (i = 0; i < num; i++) {
        for (j = 0; j < num - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\nSorted array:\n");
    for (i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }

    int l = 0, h = num - 1; 

    int result = binary_search_recursive(arr, l, h, key);
    if (result == -1) {
        printf("\nNot in array");
    } else {
        printf("\nPresent in array at %d position", result+1);
    }
    return 0;
}
