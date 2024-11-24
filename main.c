#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

extern int asmaccelleration(float init, float final, float time);

int main()
{ 
    int count = 0;
    printf("How many matrices: ");
    scanf("%d", &count);

    float *inits = malloc(count * sizeof(float));
    float *finals = malloc(count * sizeof(float));
    float *times = malloc(count * sizeof(float));
    int *results = malloc(count * sizeof(float));
    int access = 0;

    
    for (int i = 0; i < count; i++)
    {
        float init = (rand() % (99 - 0 + 1)) + 0;
        float final = (rand() % (200 - 50 + 1)) + 50;
        float time = (rand() % 100) + 1;

        printf("\n\nMatrix: %d\n\n", i+1);
        printf("Initial Velocity (KM/H): %.2f\n", init);
        printf("Final Velocity (KM/H): %.2f\n", final);
        printf("Time (seconds): %.2f", time);

        inits[access] = init;
        finals[access] = final;
        times[access] = time;

        results[access] = asmaccelleration(init, final, time);
        access++;
    }

    printf("\n\nOutput Correctness Check: \n");
    float to_ms = 0.27777778f;
    for (int i = 0; i < access; i++)
    {
        float initVel = inits[i];
        float finalVel = finals[i];
        float timeTaken = times[i];

        float expectedOutput = ((finalVel - initVel)*to_ms)/timeTaken;

        int actualOutput = results[i];

        printf("\nMatrix %d\n\n", i + 1);
        printf("Input Initial Velocity: %.2f\n", initVel);
        printf("Input Final Velocity: %.2f\n", finalVel);
        printf("Input Time: %.2f\n", timeTaken);
        printf("Expected Output: %d\n", (int)roundf(expectedOutput));
        printf("Actual Output: %d\n", actualOutput);
    }
    

    // clock_t t;
    // t = clock();
    // for (int i = 0; i < 30; i++)
    // {
    //     asmaccelleration(10000.0, 99999.0, 10000.1);
    // }
    // t = clock() - t;
    // printf("Result: %d", asmaccelleration(10000.0, 99999.0, 10000.1));
    // double time = (double)t/CLOCKS_PER_SEC;
    // printf("\nAverage time taken: %f", time);

    // Average time taken after 30 runs = 0.0 seconds #asmaccelleration(0.0, 62.5, 10.1);
    // Average time taken after 30 runs = 0.0 seconds #asmaccelleration(10.0, 99.0, 20.1);
    // Average time taken after 30 runs = 0.0 seconds #asmaccelleration(100.0, 999.0, 20.1);
    // Average time taken after 30 runs = 0.0 seconds #asmaccelleration(1000.0, 9999.0, 1000.1);
    // Average time taken after 30 runs = 0.0 seconds #asmaccelleration(10000.0, 99999.0, 10000.1);

    return 0;
}
