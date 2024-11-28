#include <stdio.h>
#include <stdlib.h>

extern void compute_acceleration(int rows, float* input, int* output);

int main() {
    int rows;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    float* input = (float*)malloc(rows * 3 * sizeof(float)); // Input: rows x 3 matrix
    int* output = (int*)malloc(rows * sizeof(int));         // Output: acceleration values

    printf("Enter the matrix values (Vi, Vf, T for each row):\n");
    for (int i = 0; i < rows; i++) {
        scanf("%f, %f, %f", &input[i * 3], &input[i * 3 + 1], &input[i * 3 + 2]);
    }

    compute_acceleration(input, output, rows);

    printf("Accelerations (m/s^2):\n");
    for (int i = 0; i < rows; i++) {
        printf("%d\n", output[i]);
    }
    return 0;
}

