#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, i, *ptr, sum = 0; 
    
    printf("Enter number of elements: ");
    scanf("%d", &num);
    
    ptr = (int*)calloc(num, sizeof(int)); // Corrected the usage of calloc
    
    if (ptr == NULL) {
        printf("Sorry! unable to allocate memory");
        exit(0);
    }
    
    printf("Enter elements of array: ");
    for (i = 0; i < num; i++) {
        scanf("%d", ptr + i); 
        sum += *(ptr + i);
    }
    
    printf("Sum = %d\n", sum); // Added newline for better output formatting
    
    free(ptr); 
    return 0;
}
