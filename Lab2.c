#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void displayMenu();
void stringExpansion();
void stringCompression();
void clearInputBuffer();

int main()
{
    char choice;

    while (1)
    {
        displayMenu();
        printf("Choice: ");
        scanf(" %c", &choice);
        choice = tolower(choice); // Convert to lowercase for case insensitivity
        clearInputBuffer();       // Clear any leftover input

        switch (choice)
        {
        case 'e':
            stringExpansion();
            break;
        case 'c':
            stringCompression();
            break;
        case 'x':
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid choice. Please enter E, C, or X.\n");
        }
    }

    return 0;
}

// Function to display the main menu
void displayMenu()
{
    printf("\nWelcome to this String Expansion/Compression program!\n");
    printf("Please choose an action to perform...\n");
    printf("[E] String Expansion\n");
    printf("[C] String Compression\n");
    printf("[X] Exit\n");
}

// Function to handle string expansion
void stringExpansion()
{
    char input[1000]; // Buffer for input string

    printf("\nEnter compressed string: ");
    scanf("%999s", input);

    printf("\nExpanded string: [RESULT]\n");
}

// Function to handle string compression
void stringCompression()
{
    char input[1000]; // Buffer for input string

    printf("\nEnter expanded string: ");
    scanf("%999s", input);

    // Compression logic goes here

    printf("\nCompressed string: [RESULT]\n");
}

// Function to clear the input buffer
void clearInputBuffer()
{
    while (getchar() != '\n')
        ; // Clear until newline character
}
