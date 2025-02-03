#include <stdio.h>

void linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Found %d at index %d using Linear Search.\n", target, i);
            return;
        }
    }
    printf("Sorry, number %d is not in the array (Linear Search).\n", target);
}

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int numbers[] = {258, 552, 642, 191, 354, 595, 945, 247, 612, 608, 924};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int target, choice;

    printf("Choose the search method:\n1. Linear Search\n2. Binary Search\n");
    scanf("%d", &choice);
    
    printf("Enter the number to search: ");
    scanf("%d", &target);

    if (choice == 1) {
        linearSearch(numbers, size, target);
    } else if (choice == 2) {
        int sortedNumbers[] = {191, 247, 258, 354, 595, 608, 612, 642, 924, 945};
        int result = binarySearch(sortedNumbers, size, target);
        if (result != -1) {
            printf("Found %d at index %d using Binary Search.\n", target, result);
        } else {
            printf("Sorry, number %d is not in the array (Binary Search).\n", target);
        }
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}