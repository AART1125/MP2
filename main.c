#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern int asmaccelleration(float init, float final, float time);

int main()
{ 
    int count = 0;
    printf("How many matrices: ");
    scanf("%d", &count);
    int *results = malloc(count * sizeof(float));

    int access = 0;
    for (int i = 0; i < count; i++)
    {
        float init = 0.0f;
        float final = 0.0f;
        float time = 0.0f;

        printf("\nMatrix: %d\n", i+1);
        printf("\nInitial Velocity (KM/H): ");
        scanf("%f", &init);
        printf("\nFinal Velocity (KM/H): ");
        scanf("%f", &final);
        printf("\nTime (seconds): ");
        scanf("%f", &time);

        results[access] = asmaccelleration(init, final, time);
        access++;
    }

    printf("\nResults:\n");

    for (int i = 0; i < access; i++)
    {
        printf("\n%d\n", results[i]);
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
