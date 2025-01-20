/* This program extracts and converts digits from an input string into an integer. */

#include <stdio.h>

int main() {
    char numero[256];
    int i = 0, j = 0;
    
    // Prompt the user for a sentence
    printf("Enter a sentence: ");
    scanf("%s", numero);
    
    // Loop through each character of the string
    while(numero[i] != '\0') {
	// Check if the character is a digit
        if(numero[i] >= 48 && numero[i] <= 57) 
	{ 
            j = j * 10 + (numero[i] - '0'); // Convert character to integer
        }
        i++;
    }
    
    // Print the resulting integer
    printf("%d\n", j);
    
    return 0;
}
