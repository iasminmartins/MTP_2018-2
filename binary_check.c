/* Program that checks if a binary number is divisible by 3 */

#include <stdio.h>

int main(){
    int est = 0, i = 0;
    char bits[256];

    // Prompt the user to enter a binary number
    printf("Enter a binary number: ");
    scanf("%s", &bits[0]);

    // Process the binary number to determine the state based on transitions
    while(bits[i] != '\0'){
        // State transitions based on the current bit
        if(est == 0 && bits[i] == '0'){
            est = 0;
        }
        else if(est == 0 && bits[i] == '1'){
            est = 1;
        }
        else if(est == 1 && bits[i] == '0'){
            est = 2;
        }
        else if(est == 1 && bits[i] == '1'){
            est = 0;
        }
        else if(est == 2 && bits[i] == '0'){
            est = 1;
        }
        else{
            est = 2;
        }
        i++;
    }

    // Print the final state and the original binary sequence
    printf("\nThe state is: %d\nThe original sequence is: %s\n", est, bits);

    // Check if the number is divisible by 3 based on the final state
    if(est == 0){
        printf("\nIt is a multiple of 3");
    }
    else{
        printf("\nIt is not");
    }
    
    return 0;
}
