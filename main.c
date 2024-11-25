#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include <time.h>

extern void accelerationasm(int rows, float* input, int* output);

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
            printf("Car   Vi (km/h)   Vf (km/h)   T (s)   Expected (m/s^2)   Computed (m/s^2)\n");
            printf("----------------------------------------------------------------------------\n");
            for (int k = 0; k < rows ; k++) { 
                float Vi = input[k * 3];                 // Original Vi in km/h
                float Vf = input[k * 3 + 1];             // Original Vf in km/h
                float T = input[k * 3 + 2];              // Original T in seconds
                float Vi_ms = Vi * 0.27777778f;          // Convert Vi to m/s
                float Vf_ms = Vf * 0.27777778f;          // Convert Vf to m/s
                float expected_acceleration = (Vf_ms - Vi_ms) / T;
                int expected = (int)roundf(expected_acceleration);

                printf("%-6d%-12.2f%-12.2f%-8.2f%-20d%-20d\n",
                       k, Vi, Vf, T, expected, output[k]);
            }
        }
    }

    // Print average execution time
    printf("\nAverage execution time for %d rows (over %d repetitions): %.8f seconds\n",
           rows, repetitions, total_time / repetitions);

    return 0;
}

