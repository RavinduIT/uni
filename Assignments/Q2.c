#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void generateRandomNumbers(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000 + 1; // Random numbers between 1 and 1000
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void linearSearch(int arr[], int size, int target, int *comparisons) {
    for (int i = 0; i < size; i++) {
        (*comparisons)++;
        if (arr[i] == target) {
            printf("Found %d at index %d using Linear Search.\n", target, i);
            return;
        }
    }
    printf("Target %d not found (Linear Search).\n", target);
}

int binarySearch(int arr[], int size, int target, int *comparisons) {
    int left = 0, right = size - 1;
    while (left <= right) {
        (*comparisons)++;
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

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

double calculateAverage(int totalComparisons, int count) {
    return (double)totalComparisons / count;
}

int main() {
    srand(time(NULL));
    int numbers[SIZE];
    generateRandomNumbers(numbers, SIZE);
    
    printf("Array of random numbers:\n");
    printArray(numbers, SIZE);
    
    int sortedNumbers[SIZE];
    for (int i = 0; i < SIZE; i++) {
        sortedNumbers[i] = numbers[i];
    }
    sortArray(sortedNumbers, SIZE);
    
    int targets[5];
    printf("Enter 5 target numbers to search for:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &targets[i]);
    }

    int totalLinearComparisons = 0;
    int totalBinaryComparisons = 0;

    for (int i = 0; i < 5; i++) {
        int target = targets[i];
        int linearComparisons = 0;
        int binaryComparisons = 0;

        linearSearch(numbers, SIZE, target, &linearComparisons);
        int binaryResult = binarySearch(sortedNumbers, SIZE, target, &binaryComparisons);
        
        if (binaryResult != -1) {
            printf("Found %d at index %d using Binary Search.\n", target, binaryResult);
        } else {
            printf("Target %d not found (Binary Search).\n", target);
        }

        printf("Comparisons: Linear Search = %d, Binary Search = %d\n", linearComparisons, binaryComparisons);
        totalLinearComparisons += linearComparisons;
        totalBinaryComparisons += binaryComparisons;
    }

    double averageLinear = calculateAverage(totalLinearComparisons, 5);
    double averageBinary = calculateAverage(totalBinaryComparisons, 5);
    
    printf("Average comparisons: Linear Search = %.2f, Binary Search = %.2f\n", averageLinear, averageBinary);

    return 0;
}