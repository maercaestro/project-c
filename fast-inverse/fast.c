// Fast-Inverse Square Root Algorithm demonstration
// by Abu Huzaifah Bidin
// Date : 23-Feb-25, 1420 hrs
#include <stdio.h> // common header
#include <math.h> // for typical inverse square root calculation
#include <time.h> // for clocking the time for both calculation
#include <stdint.h> // header to manager integer

// setting up the functions first
float fastInvSqrt(float number)
{
    long i;
    float x2,y;
    const float threehalfs = 1.5F;

    x2 = number *0.5F;
    y = number;
    i  = *(long*)&y;            // Evil floating point bit level hacking
    i  = 0x5f3759df - (i >> 1); // What the fuck?
    y  = *(float*)&i;
    y  = y * (threehalfs - (x2 * y * y)); // First iteration using Newton method
//  y  = y * (threehalfs - (x2 * y * y)); // 2nd iteration, can be removed

    return y;
}

int main() {
    float number = 553.0f; // Test number

    // Standard Math.h method
    clock_t start1 = clock();
    float std_result = 1.0f / sqrtf(number);
    clock_t end1 = clock();
    
    // Fast Inverse Square Root
    clock_t start2 = clock();
    float fast_result = fastInvSqrt(number);
    clock_t end2 = clock();

    // Print results
    printf("Standard Method (math.h):\n");
    printf("  1/sqrt(%f) = %f (Time: %lu ns)\n", number, std_result, (end1 - start1));

    printf("Fast Inverse Square Root:\n");
    printf("  1/sqrt(%f) = %f (Time: %lu ns)\n", number, fast_result, (end2 - start2));

    return 0;
}




