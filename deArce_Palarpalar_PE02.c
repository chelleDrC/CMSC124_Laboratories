// This is a program that will expand or compress strings.
//  It will also handle invalid expressions (such as ? < >) with appropriate error messages. The program will display a menu.
// Programmer: Richelle S. de Arce & Cherlie Joy Palarpalar
// Date: Feb 5, 2025 - Feb 13, 2025

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Colors to emphasize text
#define GREEN "\x1b[32m"
#define RED "\x1b[41m"
#define RESET "\x1b[0m"

// Function prototype
void Menu();
void ProgDesc();
void Execute();
void ExpandString();
void CompressString();
int isValidCompressionString(const char *str);
int isValidExpansionString(const char *str);
int askRepeat();
void ErrorMessage();
void chooseOutputFormat(char *output, const char *input, int format);

// Main function
int main()
{

    char choice;

    system("cls"); // Clear the screen

    // Call the Menu function
    Menu();

    // Input
    printf("Choice: ");
    scanf(" %c", &choice);

    // Choices
    if (choice == 'P' || choice == 'p')
    { // Program Description
        printf(GREEN "\n---PROGRAM DESCRIPTION---" RESET "\n");
        ProgDesc();
        main();
    }
    else if (choice == 'E' || choice == 'e')
    {
        printf(GREEN "\n---STRING EXPANSION---" RESET "\n");
        ExpandString();
        main();
    }
    else if (choice == 'C' || choice == 'c')
    {
        printf(GREEN "\n---STRING COMPRESSION---" RESET "\n");
        CompressString();
        main();
    }
    else if (choice == 'X' || choice == 'x')
    { // Exiting the Program
        printf(GREEN "---TERMINATING PROGRAM---" RESET "\n");
        return 0;
    }
    else
    {
        ErrorMessage();
        main();
    }
}

// Function to display the Menu
void Menu()
{
    printf("Welcome to this String Expansion/Compression program!\n");
    printf("Please choose an action to perform...\n");
    printf("[P] Program Description\n");
    printf("[E] String Expansion\n");
    printf("[C] String Compression\n");
    printf("[X] Exit\n");
}

// Display Proram Description
void ProgDesc()
{

    printf("Developed by:\n");
    printf("Richelle S. de Arce (2023-15674)\n");
    printf("Cherlie Joy Palarpalar (2023-16099)\n");
    printf("Development Period: Feb 2, 2025 - Feb 14, 2025\n\n");

    printf(GREEN "---PROGRAM OVERVIEW---" RESET "\n");
    printf("1.Perform string expansion and compression.\n");
    printf("2.Output the string in either raw or spaced format. [EXTRA FEATURE]\n\n");

    printf(GREEN "---MENU OPTIONS---" RESET "\n");
    printf("[P] Program Description - Displays details about the program, development timeline, and contributors.\n");
    printf("[E] String Expansion - Allows users to input an expression and expand it.\n");
    printf("[C] String Compression - Allows users to input an expression and compress it.\n");
    printf("[X] Exit - Exits the program immediately.\n\n");

    printf(GREEN "---CONTRIBUTORS & ROLES---" RESET "\n");
    printf("Richelle | Implemented Menu System and String Compression.\n");
    printf("Cherlie | Implementd String Expansion and output formatting.\n");
    printf("Cherlie & Richelle | Implemented error handling.\n\n");

    while (getchar() != '\n')
        ; // Clear the input buffer
    printf("Press enter to continue...");
    getchar();
    return;
}

// Function to expand the string
void ExpandString()
{
    // Variables
    char input[100];
    char expanded[200];
    int i, j = 0, count;
    int format;
    char formattedOutput[400];

    // Loop to handle invalid input
    while (1)
    {
        printf("Enter a string to expand: ");
        scanf("%s", input);

        if (!isValidExpansionString(input) || isdigit(input[strlen(input) - 1]))
        {                   // Check if the input is valid
            ErrorMessage(); // Display error message
            if (askRepeat())
            { // Ask user if they want to repeat the process
                continue;
            }
            else
            {
                break;
            }
        }

        // Loop to expand the string
        for (i = 0; i < strlen(input); i++)
        {
            if (isdigit(input[i]))
            {              // Check if the character is a digit
                count = 0; // Initialize count to 0
                while (isdigit(input[i]))
                { // Loop to get the count
                    count = count * 10 + (input[i] - '0');
                    i++;
                }
                // Loop to add the character to the expanded string
                for (int k = 0; k < count; k++)
                {
                    expanded[j++] = input[i];
                }
            }
            else
            {
                expanded[j++] = input[i]; // Add the character to the expanded string
            }
        }
        expanded[j] = '\0'; // Ensure null termination

        // Loop to choose output format
        do
        {
            printf("[EXTRA FEATURE] Choose output format:\n");
            printf("[1] Raw\n");
            printf("[2] Spaced\n");
            printf("Choice: ");

            if (scanf("%d", &format) != 1)
            { // Check if the input is a number
                while (getchar() != '\n')
                    ;       // Clear the input buffer
                format = 0; // Set to an invalid value
            }
            if (format != 1 && format != 2)
            {                                                               // Check if the input is 1 or 2
                printf(RED "Invalid choice. Please enter 1 or 2.\n" RESET); // Display error message
            }
        } while (format != 1 && format != 2);

        chooseOutputFormat(formattedOutput, expanded, format); // Choose output format

        printf(GREEN "Expanded string: %s\n", formattedOutput, RESET); // Display the expanded string in the format

        while (getchar() != '\n')
            ; // Clear the input buffer
        printf(RESET "Press enter to continue...");
        getchar();
        break;
    }
}

// Function to compress the string
void CompressString()
{
    // Variables
    char input[100];
    char compressed[200];
    int i, count, j = 0;
    int format;
    char formattedOutput[400];

    // Loop to handle invalid input
    while (1)
    {
        printf("Enter a string to compress: ");
        fgets(input, sizeof(input), stdin);
        while (getchar() != '\n')
            ; // Clear input buffer

        // Check if the input is valid
        if (!isValidCompressionString(input))
        {
            ErrorMessage(); // Display error message
            printf("Enter any key to continue...");
            if (askRepeat())
            { // Ask user if they want to repeat the process
                return;
            }
            else
            {
                break;
            }
        }

        // Loop to compress the string
        for (i = 0; i < strlen(input); i++)
        {
            count = 1; // Initialize count to 1
            // Loop to count the number of consecutive characters for compression
            while (i < strlen(input) - 1 && input[i] == input[i + 1])
            {
                count++;
                i++;
            }

            // Check if the count is 1
            if (count == 1)
            { // If the count is 1, add the character to the compressed string
                j += sprintf(&compressed[j], "%c", input[i]);
            }
            else
            { // If the count is greater than 1, add the count and the character to the compressed string
                j += sprintf(&compressed[j], "%d%c", count, input[i]);
            }
        }
        compressed[j] = '\0'; // Ensure null termination

        // Loop to choose output format
        do
        {
            printf("[EXTRA FEATURE] Choose output format:\n");
            printf("[1] Raw\n");
            printf("[2] Spaced\n");
            printf("Choice: ");
            if (scanf("%d", &format) != 1)
            { // Check if the input is a number
                while (getchar() != '\n')
                    ;       // Clear the input buffer
                format = 0; // Set to an invalid value
            }
            if (format != 1 && format != 2)
            { // Check if the input is 1 or 2
                printf(RED "Invalid choice. Please enter 1 or 2.\n" RESET);
            }
        } while (format != 1 && format != 2);

        chooseOutputFormat(formattedOutput, compressed, format); // Choose output format

        printf(GREEN "Compressed string: %s\n", formattedOutput, RESET); // Display the compressed string in the format

        while (getchar() != '\n')
            ; // Clear the input buffer
        printf(RESET "Press enter to continue...");
        getchar();
        break;
    }
}

// Function to check if the string is valid for compression
int isValidCompressionString(const char *str)
{
    // Loop to check if the string is valid
    while (*str)
    {
        if (!isalpha(*str))
        { // If the character is not a letter, return 0
            return 0;
        }
        str++; // Move to the next character
    }
    return 1;
}

// Function to check if the string is valid for expansion
int isValidExpansionString(const char *str)
{
    int hasDigit = 0; // Initialize hasDigit to 0
    // Loop to check if the string is valid
    while (*str)
    {
        if (!isdigit(*str) && !isalpha(*str))
        { // If the character is not a digit or a letter, return 0
            return 0;
        }
        if (isdigit(*str))
        { // If the character is a digit, set hasDigit to 1
            hasDigit = 1;
        }
        str++; // Move to the next character
    }
    return 1; // Return 1 if the string is valid (contains only letters/numbers)
}

// Function to ask user if they want to repeat the process
int askRepeat()
{
    char input[10];
    // Loop to ask user if they want to repeat the process
    while (1)
    {
        if (input[strlen(input) - 1] != '\n')
        { // If the last character is not a newline, clear the input buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ; // Clear the input buffer
        }

        printf("Do you want to repeat the process? (Y/N): ");
        fgets(input, sizeof(input), stdin);

        // Check if the input is a single character followed by a newline
        if (strlen(input) == 2 && (input[0] == 'Y' || input[0] == 'y' || input[0] == 'N' || input[0] == 'n'))
        {
            if (input[0] == 'Y' || input[0] == 'y')
            { // If the input is Y or y, return 1
                return 1;
            }
            else if (input[0] == 'N' || input[0] == 'n')
            { // If the input is N or n, return 0
                return 0;
            }
        }
        else
        {
            printf(RED "Invalid choice. Please enter Y or N.\n" RESET);
        }
    }
}

// Function to display error message
void ErrorMessage()
{
    printf(RED "Invalid input! Please try again.\n" RESET);
}

// Function to choose output format
void chooseOutputFormat(char *output, const char *input, int format)
{
    int i, j = 0;
    output[0] = '\0'; // Properly initialize the output string

    if (format == 1)
    { // If the format is 1, copy the input to the output
        strcpy(output, input);
    }
    else
    { // If the format is 2, add spaces between characters
        // Loop to add spaces between characters
        for (i = 0; i < strlen(input); i++)
        {
            // Add a space if the character is not a digit or the previous character is not a digit
            if (i > 0 && !(isdigit(input[i]) && isdigit(input[i - 1])))
            {
                output[j++] = ' ';
            }
            output[j++] = input[i]; // Add the character to the output
        }
        output[j] = '\0'; // Ensure null termination
    }
}