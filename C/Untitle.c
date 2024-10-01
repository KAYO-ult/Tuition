#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, num;
    float *data;

    printf("Enter total number of elements (1 to 100): ");
    scanf("%d", &num);

    // Allocates the memory for 'num' elements.
    data = (float*) calloc(num, sizeof(float));

    if (data == NULL) { // Corrected assignment to comparison
        printf("Error!!! memory not allocated.\n");
        exit(0);
    }

    printf("\n");

    // Stores the number entered by the user.
    for (i = 0; i < num; ++i) {
        printf("Enter Number %d: ", i + 1);
        scanf("%f", data + i);
    }

    // Loop to store largest number at address data
    for (i = 1; i < num; ++i) {
        // Change if(*data < *(data + i)) to if(*data > *(data + i)) if you want to find the smallest number
        if (*data < *(data + i)) {
            *data = *(data + i);
        }
    }

    printf("Largest element = %.2f\n", *data); // Print the largest element
    free(data);
return 0;
}
