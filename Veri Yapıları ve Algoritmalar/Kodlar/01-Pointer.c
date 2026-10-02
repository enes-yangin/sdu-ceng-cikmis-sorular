#include <stdio.h>

// Function for demonstration of function pointer usage.
int add(int a, int b) {
    return a + b;
}

int main() {
    // 1. Basic Pointer Declaration and Usage
    int value = 42;           // Regular integer variable.
    int *ptr = &value;        // 'ptr' stores the address of 'value'.

    // 2. Pointer Arithmetic with Arrays
    int numbers[5] = {10, 20, 30, 40, 50}; // Array of integers.
    int *arrPtr = numbers;    // 'arrPtr' points to the first element of 'numbers'.

    // 3. Pointer to Pointer (Double Pointer)
    int *p = &value;          // Single pointer to 'value'.
    int **pp = &p;            // 'pp' holds the address of pointer 'p'.

    // 4. Function Pointer
    int (*funcPtr)(int, int) = add; // 'funcPtr' points to function 'add'.

    // Output demonstration for each method.
    printf("Basic Pointer:\n");
    printf("Value: %d, Address: %p, Dereferenced: %d\n\n", value, (void *)ptr, *ptr);

    printf("Pointer Arithmetic with Arrays:\n");
    for (int i = 0; i < 5; i++) {
        // Using pointer arithmetic to access array elements.
        printf("numbers[%d] = %d\n", i, *(arrPtr + i));
    }
    printf("\n");

    printf("Pointer to Pointer (Double Pointer):\n");
    // Double dereferencing to access the original value.
    printf("Value via double pointer: %d\n\n", **pp);

    printf("Function Pointer:\n");
    // Calling the function via the function pointer.
    printf("add(5, 7) = %d\n", funcPtr(5, 7));

    return 0;
}

