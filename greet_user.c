#include <stdio.h>

int main(int argc, char **argv) {
    int i;

    // Check if there are more than 1 command-line arguments
    if (argc > 1) {
        // Check if there are more than 2 command-line arguments
        if (argc > 2)
            // Print the message 'Thank you' 'n' times based on the second argument
            for (i = 0; i < argv[2][0] - '0'; i++)
                printf("Thank you!, %s\n", argv[1]);
        else
            // Print 'Greetings' if only one argument is passed
            printf("Greetings!, %s\n", argv[1]);
    }
    else
        // If no arguments are passed, print 'Hello'
        printf("Hello!\n");

    return 0;
}
