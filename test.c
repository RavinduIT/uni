#include "mymalloc.h"
#include <stdio.h>
#include <string.h>

void test_allocation() {
    printf("Test Allocation:\n");
    char* ptr1 = (char*)MyMalloc(100);
    if (ptr1 != NULL) {
        printf("Allocated 100 bytes.\n");
    } else {
        printf("Failed to allocate 100 bytes.\n");
    }

    char* ptr2 = (char*)MyMalloc(200);
    if (ptr2 != NULL) {
        printf("Allocated 200 bytes.\n");
    } else {
        printf("Failed to allocate 200 bytes.\n");
    }

    char* ptr3 = (char*)MyMalloc(30000); // Should fail
    if (ptr3 != NULL) {
        printf("Allocated 30000 bytes (unexpected).\n");
    } else {
        printf("Failed to allocate 30000 bytes (expected).\n");
    }

    MyFree(ptr1);
    printf("Freed 100 bytes.\n");

    MyFree(ptr2);
    printf("Freed 200 bytes.\n");
}

void test_free_and_reuse() {
    printf("Test Free and Reuse:\n");
    char* ptr1 = (char*)MyMalloc(100);
    char* ptr2 = (char*)MyMalloc(200);
    MyFree(ptr1);
    printf("Freed 100 bytes.\n");

    char* ptr3 = (char*)MyMalloc(50); // Should reuse the freed 100 bytes block
    if (ptr3 != NULL) {
        printf("Allocated 50 bytes (reused freed block).\n");
    } else {
        printf("Failed to allocate 50 bytes.\n");
    }

    MyFree(ptr2);
    printf("Freed 200 bytes.\n");

    MyFree(ptr3);
    printf("Freed 50 bytes.\n");
}

void test_fragmentation() {
    printf("Test Fragmentation:\n");
    char* ptr1 = (char*)MyMalloc(100);
    char* ptr2 = (char*)MyMalloc(200);
    char* ptr3 = (char*)MyMalloc(300);

    MyFree(ptr2);
    printf("Freed 200 bytes.\n");

    char* ptr4 = (char*)MyMalloc(150); // Should fit into the freed 200 bytes block
    if (ptr4 != NULL) {
        printf("Allocated 150 bytes (fit into freed block).\n");
    } else {
        printf("Failed to allocate 150 bytes.\n");
    }

    MyFree(ptr1);
    printf("Freed 100 bytes.\n");

    MyFree(ptr3);
    printf("Freed 300 bytes.\n");

    MyFree(ptr4);
    printf("Freed 150 bytes.\n");
}

int main() {
    test_allocation();
    test_free_and_reuse();
    test_fragmentation();
    return 0;
}