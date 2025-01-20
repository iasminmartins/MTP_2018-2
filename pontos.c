/* 
 * Generates points on a unit circle, saves them in text and binary formats, 
 * and allows reading and displaying from the binary file via a menu.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ponto {
    double x, y;
};

// Function to create points on the unit circle
struct ponto *criar(int num) {
    struct ponto *p = (struct ponto*) malloc(num * sizeof(struct ponto));
    int i;

    for(i = 0; i < num; i++) {
        p[i].x = cos(i * 2.0 * M_PI / (num - 1));  // Calculate x-coordinate
        p[i].y = sin(i * 2.0 * M_PI / (num - 1));  // Calculate y-coordinate
    }

    return p;
}

// Function to save points in text format
void salvar(struct ponto *p, int num) {
    FILE *arq;
    arq = fopen("pontos.dat", "w");
    int i;

    for(i = 0; i < num; i++) {
        // Save each point's x and y coordinates to the file (without repetition)
        fprintf(arq, "%.3lf\t%.3lf\n", p[i].x, p[i].y);
    }

    fclose(arq);
}

// Function to save points in binary format
void abin(struct ponto *p, int num) {
    FILE *arq;
    arq = fopen("pontos.dat", "wb");
    fwrite(p, num, sizeof(struct ponto), arq);  // Write points to the file in binary format
    fclose(arq);
}

// Function to read points from the binary file
struct ponto *ler(unsigned int *pn) {
    struct ponto *p = (struct ponto*) malloc(sizeof(struct ponto));
    unsigned int num = 0;
    FILE *arq;
    arq = fopen("pontos.dat", "rb");

    while(1) {
        fread(p, 1, sizeof(struct ponto), arq);
        if(feof(arq))
            break;
        num++;
    }

    rewind(arq);
    p = (struct ponto*) realloc(p, num * sizeof(struct ponto));  // Reallocate memory for all points
    fread(p, num, sizeof(struct ponto), arq);
    fclose(arq);
    *pn = num;  // Set the number of points
    return p;
}

// Function to display points
void mostrar(struct ponto *p, struct ponto *pf) {
    if(p < pf) {
        printf("(%.3lf, %.3lf)\n", p->x, p->y);  // Print the current point
        mostrar(p + 1, pf);  // Display next point
    }
}

int main() {
    struct ponto *p;
    int num, opc;

    do {
        system("cls");  // Clear the screen (use "cls" for Windows, "clear" for Linux/Mac)
        printf("-----MENU----- \n[1]- Generate file with points. \n[2]- Retrieve points from file.\n[3]- Exit program.\n\n");
        scanf("%d", &opc);

        switch(opc) {
            case 1:
                // Prompt the user for the number of points
                printf("\nEnter the number of points you want to generate: ");
                scanf("%d", &num);
                getchar();
                p = criar(num);  // Generate points
                salvar(p, num);   // Save points in text format
                abin(p, num);     // Save points in binary format
                printf("\nFile saved!");
                getchar();  // Replace getch() with getchar() for a better experience
                break;

            case 2:
                // Load and display points from file
                p = ler(&num);
                mostrar(p, p + num);  // Display all points
                getchar();  // Replace getch() with getchar() for a better experience
                break;

            default:
                if (opc != 3)
                    printf("\nInvalid option!");
                getchar();  // Replace getch() with getchar() for a better experience
                break;
        }
    } while(opc != 3);

    printf("\nGoodbye! :)");
    free(p);  // Free allocated memory
    return 0;
}
