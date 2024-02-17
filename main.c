#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Colour Codes
#define GREEN "\x1B[32m"
#define RED "\x1B[31m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define RESET "\x1B[0m"

void meow(int n);
void read_input(char *input, int length);

int main(void)
{
    // Display the welcome message and instructions
    printf(GREEN "Welcome to Meow Program, This program allows you to Meow or Bark n times. do 'exit' to terminate\n");
    printf("Simply Enter a positive integer to Meow or a negative integer to Bark ");
    printf(RESET "\n");

    while (1)
    {

        char input[10];
        read_input(input, sizeof(input));

        // Convert the input to an integer
        int n = atoi(input);
        if (n == 0 && input[0] != '0')
        {
            // Convert the input to lowercase
            for (int i = 0; input[i]; i++)
            {
                input[i] = tolower(input[i]);
            }

            // handle errors
            if (strcmp(input, "exit") == 0)
            {
                printf(RED "Program Terminated\n");
                printf(RESET);
                exit(0);
            }
            else
            {
                printf(YELLOW "Input value must be a number, 'exit' to terminate\n");
                printf(RESET);
                continue;
            }
        }

        meow(n);
    }
}

// Function that meows or barks n times
void meow(int n)
{
    if (n > 0)
    {
        printf("--------------------\n");
        for (int i = 0; i < n; i++)
        {
            printf("Meow\n");
        }
        printf("--------------------\n\n");
    }
    else if (n < 0)
    {
        printf("--------------------\n");
        for (int i = 0; i < abs(n); i++)
        {
            printf("Bark\n");
        }
        printf("--------------------\n\n");
    }
    else
    {
        printf(YELLOW "ERROR input value cannot be 0, 'exit' to terminate\n");
        printf(RESET);
    }
}

// Reads the input from the user
void read_input(char *input, int length)
{
    printf(BLUE "Value: ");
    printf(RESET);
    fgets(input, length, stdin);

    // Remove newline character if present
    if (input[strlen(input) - 1] == '\n')
    {
        input[strlen(input) - 1] = '\0';
    }
}
