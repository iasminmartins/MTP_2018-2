/* This program uses a recursive function to perform operations on two input numbers. */

#include <stdio.h>

// Function declaration
double funcao(float m, float n);

int main() {
    float m, n;

    // Prompt user to enter two numbers
    printf("Enter two numbers: ");
    scanf("%f%f", &m, &n);

    // Call the function and print the result
    printf("%g + %g = %g", m, n, funcao(m, n));
    return 0;
}

// Recursive function that performs different operations depending on the values of m and n
double funcao(float m, float n) {
    if(m == 0) 
        return n + 1;
    else if(m > 0 && n == 0) 
        return funcao(m - 1, 1);
    else if(m > 0 && n > 0) 
        return funcao(m - 1, funcao(m, n - 1));
}
