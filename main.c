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
    double timeExecuted = 0.0f;
    int access = 0;

    srand(time(0));
    
    for (int i = 0; i < 30; i++)
    {
        for (int k = 0; k < count; k++)
        {
            inits[access] = (rand() % 101) + 0;
            finals[access] = (rand() % 101) + 100;
            times[access] = (rand() % 101) + 1;

            access++;
        }

        time_t start_time = time(NULL);
        for (int j = 0; j < count; j++)
        {
            results[access - count + j] = asmaccelleration(inits[access - count + j], finals[access - count + j], times[access - count + j]);
        }
        time_t end_time = time(NULL);
        timeExecuted += difftime(end_time, start_time);
        if (i == 0)
        {
            float to_ms = 0.27777778f;
            printf("\n\nOutput Correctness Check: \n");
            for (int l = 0; l < access; l++)
            {
                float initVel = inits[l];
                float finalVel = finals[l];
                float timeTaken = times[l];

                float expectedOutput = ((finalVel - initVel)*to_ms)/timeTaken;

                int actualOutput = results[l];

                printf("\nVector %d\n\n", l+1);
                printf("Input Initial Velocity: %.2f\n", initVel);
                printf("Input Final Velocity: %.2f\n", finalVel);
                printf("Input Time: %.2f\n", timeTaken);
                printf("Expected Output: %d\n", (int)roundf(expectedOutput));
                printf("Actual Output: %d\n", actualOutput);
            }
        }
    }
    
    printf("\nExecution time: %f\n", timeExecuted);

    return 0;
}
