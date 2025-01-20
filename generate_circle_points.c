/* This program generates N points evenly distributed on a unit circle and prints their (x, y) coordinates. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a structure for a point in 2D space
typedef struct{
    double x, y;
} ponto;

// Function to generate N points
ponto *gerar_pontos(int N);

int main(){
    int N;
    ponto *p;

    // Prompt the user to input the number of points
    printf("Enter the number of points: ");
    scanf("%d", &N); getchar();

    // Generate the points and print them
    p = gerar_pontos(N);

    // Free allocated memory
    free(p);

    return 0;
}

// Function to generate N points evenly distributed on a unit circle
ponto *gerar_pontos(int N){
    int i;
    ponto *p = (ponto*) malloc(N * sizeof(ponto));  // Allocate memory for N points

    // Generate and print each point
    for(i = 0; i < N; i++){
        p[i].x = cos(i * 2.0 * M_PI / (N - 1));  // Calculate the x-coordinate
        p[i].y = sin(i * 2.0 * M_PI / (N - 1));  // Calculate the y-coordinate
        printf("(%.3lf, %.3lf)\n", p[i].x, p[i].y);  // Print the point
    }

    return p;  // Return the pointer to the array of points
}
