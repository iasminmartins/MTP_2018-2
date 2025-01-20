/* This program generates random floating-point numbers using an LCG and allows the user to calculate the sum or product of the numbers. */

#include <stdio.h>

// Define a custom type for 64-bit unsigned integer
typedef unsigned long long int Bytes8;

// Define a structure for Linear Congruential Generator (LCG)
typedef struct LCG 
{
    Bytes8 a, c, m, rand_max, atual;
} LCG;

// Initialize the LCG with a given seed
void semente(LCG *r, Bytes8 seed) 
{
    r->a = 0x5DEECE66DULL;  // Multiplier
    r->c = 11ULL;            // Increment
    r->m = (1ULL << 48);     // Modulus (2^48)
    r->rand_max = r->m - 1;  // Maximum random value
    r->atual = seed;         // Initial state (seed)
}

// Generate a random number using LCG
Bytes8 lcg_rand(LCG *r) 
{
    r->atual = (r->a * r->atual + r->c) % r->m;
    return r->atual;
}

// Generate a random float between 0 and 1
double lcg_rand_01(LCG *r) 
{
    return ((double)lcg_rand(r)) / (r->rand_max);
}

// Generate an array of random numbers between min and max
void gera_numeros(float *vetor, int tam, float min, float max, LCG *r) {
    int i;
    for(i = 0; i < tam; i++)
        vetor[i] = (max - min) * lcg_rand_01(r) + min;
}

// Calculate the sum of a vector recursively
float soma(float *inicio_vetor, float *fim_vetor) {
    if (inicio_vetor != fim_vetor + 1) {
        return (*inicio_vetor) + soma(inicio_vetor + 1, fim_vetor);
    }
    return 0;
}

// Calculate the product of a vector recursively
float produto(float *inicio_vetor, float *fim_vetor) {
    if (inicio_vetor != fim_vetor + 1) {
        return (*inicio_vetor) * produto(inicio_vetor + 1, fim_vetor);
    }
    return 1;
}

int main() {
    LCG random;
    semente(&random, 123456);  // Initialize the random generator with a seed
    int opc = 0, i;
    float numeros[50];

    // Generate 50 random numbers between 0.5 and 1.5
    gera_numeros(numeros, 50, 0.5, 1.5, &random);

    // Print the generated numbers
    printf("The 50 random numbers generated are:\n\n");
    for(i = 0; i < 50; i++)
        printf("[%02d] - %.2f\n", i + 1, numeros[i]);

    // Menu for choosing sum or product calculation
    do {
        printf("\n\nChoose one of the following options: \n[1] - Sum of numbers \n[2] - Product of numbers \n[3] - Exit the program. \n\n");
        scanf("%d", &opc);
        switch(opc) {
            case 1:
                printf("\nThe sum is %g.", soma(&numeros[0], &numeros[49]));
                break;
            case 2:
                printf("\nThe product is %g.", produto(&numeros[0], &numeros[49]));
                break;
            default:
                if(opc != 3)
                    printf("\nPlease choose a valid option.");
        }
    } while(opc != 3);
    return 0;
}
