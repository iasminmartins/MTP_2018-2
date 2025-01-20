/* This program provides a menu for converting numbers between binary, decimal, hexadecimal, and octal formats. */

#include <stdio.h>

// Function to reverse a string
void inv(char vet[]) {
    int i, j, cont = 0, aux;
    // Counting the length of the string
    for(i = 0; vet[i] != '\0'; i++, cont++);
    j = cont - 1;
    
    // Reversing the string
    for(i = 0; i < j; i++, j--) {
        aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
    }
    vet[cont] = '\0'; // Adding the null terminator
}

// Function to calculate power of a number (n^n2)
int pot(int n, int n2) {
    int i, r = 1;
    for(i = 0; i < n2; i++, r *= n); // Calculate n raised to the power of n2
    return r;
}

// Function to convert a binary string to decimal, dividing by 49
int b_d(char vet[]) {
    inv(vet); // Reverse the string to process it from left to right
    int i, soma = 0;
    // Convert the binary string to decimal
    for(i = 0; vet[i] != '\0'; i++) {
        if(vet[i] == '1') {
            soma += vet[i] * pot(2, i); // Add the value of each binary digit
        }
    }
    return soma / 49; // Return the result divided by 49
}

// Function to convert decimal to binary and print it
void d_b(int n) {
    int i, flag = 0, vet[256], j;
    j = n;
    // Convert decimal to binary
    for(i = 0; flag < 1; i++) {
        vet[i] = j % 2;
        j /= 2;
        if(j == 0 || j == 1) {
            vet[i + 1] = j;
            j = i + 1;
            flag++;
        }
    }
    
    // Print the binary representation
    printf("\nIn binary it is ");
    for(j; j >= 0; j--) {
        printf("%d", vet[j]);
    }
}

// Main function to handle user input and conversions
int main() {
    char n[256];
    int esc = 0;
    
    do {
        // Display the menu and ask the user to choose a conversion option
        printf("-------------- Menu --------------\nChoose a conversion option:\n[1]-Binary to decimal\n[2]-Binary to hexadecimal\n[3]-Hexadecimal to decimal\n[4]-Hexadecimal to binary\n[5]-Decimal to binary\n[6]-Decimal to hexadecimal\n[7]-Octal to decimal\n[8]-Decimal to octal\nEnter your choice: ");
        scanf("%d", &esc);
        
        // Binary to decimal conversion
        if(esc == 1) {
            printf("\nEnter the binary number: ");
            scanf("%s", &n[0]);
            printf("\nIn decimal it is %d", b_d(n));
        }
        
        // Binary to hexadecimal conversion
        if(esc == 2) {
            printf("\nEnter the binary number: ");
            scanf("%s", &n[0]);
            printf("\nIn hexadecimal it is %x", b_d(n));
        }
        
        // Hexadecimal to decimal conversion
        if(esc == 3) {
            printf("\nEnter the hexadecimal number: ");
            scanf("%x", &n);
            printf("\nIn decimal it is %d", n);
        }
        
        // Hexadecimal to binary conversion
        if(esc == 4) {
            printf("\nEnter the hexadecimal number: ");
            scanf("%x", &n);
            d_b(n);
        }
        
        // Decimal to binary conversion
        if(esc == 5) {
            printf("\nEnter the decimal number: ");
            scanf("%d", &n);
            d_b(n);
        }
        
        // Decimal to hexadecimal conversion
        if(esc == 6) {
            printf("\nEnter the decimal number: ");
            scanf("%d", &n);
            printf("\nIn hexadecimal it is %x", n);
        }
        
        // Octal to decimal conversion
        if(esc == 7) {
            printf("\nEnter the octal number: ");
            scanf("%o", &n);
            printf("\nIn decimal it is %d", n);
        }
        
        // Decimal to octal conversion
        if(esc == 8) {
            printf("\nEnter the decimal number: ");
            scanf("%d", &n);
            printf("\nIn octal it is %o", n);
        }
    } while(esc < 1 || esc > 8); // Continue until a valid option is chosen
    
    return 0;
}
