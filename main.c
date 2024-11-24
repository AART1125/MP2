#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void accelerationasm(int rows, float* input, int* output);

// Updated function to allow Vf to be smaller than Vi
void generate_random_input(float* input, int rows) {
    for (int i = 0; i < rows; i++) {
        input[i * 3] = (rand() % 200) - 100;       // rand() Vi (-100 to 99)
        input[i * 3 + 1] = (rand() % 200) - 100;  // rand() Vf (-100 to 99)
        input[i * 3 + 2] = (rand() % 10) + 1;     // rand() T (1 to 10)
    }
}

int main() {
    int rows, repetitions;

    // Allow user to specify the size of the dataset
    printf("Enter the number of cars: ");
    scanf("%d", &rows);

   // Test 30 times
    repetitions = 30; 

    float* input = (float*)malloc(rows * 3 * sizeof(float)); 
    int* output = (int*)malloc(rows * sizeof(int));         

    srand((unsigned int)time(NULL)); // Seed random number generator

    double total_time = 0.0;
    for (int i = 0; i < repetitions; i++) {
        generate_random_input(input, rows);

        clock_t start = clock();
        accelerationasm(rows, input, output);
        clock_t end = clock();

        total_time += (double)(end - start) / CLOCKS_PER_SEC;

        // Correctness check for the first repetition only
        if (i == 0) {
            printf("Correctness check (first 10 rows):\n");
            for (int k = 0; k < rows && k < 10; k++) { // Print first 10 results
                float Vi = input[k * 3] * 0.27777778f; // Convert Vi to m/s
                float Vf = input[k * 3 + 1] * 0.27777778f; // Convert Vf to m/s
                float T = input[k * 3 + 2];
                float expected_acceleration = (Vf - Vi) / T;
                int expected = (int)expected_acceleration;

                if (output[k] != expected) {
                    printf("Row %d: Expected %d, Got %d\n", k, expected, output[k]);
                } else {
                    printf("Row %d: Correct (%d m/s^2)\n", k, output[k]);
                }
            }
        }
    }

    // Print average execution time
    printf("\nAverage execution time for %d rows (over %d repetitions): %.8f seconds\n",
           rows, repetitions, total_time / repetitions);

    return 0;
}
