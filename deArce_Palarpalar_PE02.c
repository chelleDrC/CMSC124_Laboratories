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

    system("cls");

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

    printf("Press any key to continue...");
    while (getchar() != '\n')
        ; // Clear the input buffer
    getchar();
    return;
}

// Function to expand the string
void ExpandString()
{
    char input[100];
    char expanded[200];
    int i, j = 0, count;
    int format;

    while (1)
    {
        printf("Enter a string to expand: ");
        scanf("%s", input);

        if (!isValidExpansionString(input) || isdigit(input[strlen(input) - 1]))
        {
            ErrorMessage();
            if (askRepeat())
            {
                continue;
            }
            else
            {
                break;
            }
        }

        for (i = 0; i < strlen(input); i++)
        {
            if (isdigit(input[i]))
            {
                count = 0;
                while (isdigit(input[i]))
                {
                    count = count * 10 + (input[i] - '0');
                    i++;
                }
                int k;
                for (k = 0; k < count; k++)
                {
                    expanded[j++] = input[i];
                }
            }
            else
            {
                expanded[j++] = input[i];
            }
        }
        expanded[j] = '\0';

        do
        {
            printf("[EXTRA FEATURE] Choose output format:\n");
            printf("[1] Raw\n");
            printf("[2] Spaced\n");
            printf("Choice: ");
            scanf("%d", &format);
            if (format != 1 && format != 2)
            {
                printf(RED "Invalid choice. Please enter 1 or 2.\n" RESET);
            }
        } while (format != 1 && format != 2);

        char formattedOutput[400];
        chooseOutputFormat(formattedOutput, expanded, format);

        printf(GREEN "Expanded string: %s\n", formattedOutput, RESET);

        printf(RESET "Press any key to continue...");
        while (getchar() != '\n')
            ; // Clear the input buffer
        getchar();
        break;
    }
}

// Function to compress the string
void CompressString()
{
    char input[100];
    char compressed[200];
    int i, count, j = 0;
    int format;

    while (1)
    {
        printf("Enter a string to compress: ");
        scanf("%s", input);

        if (!isValidCompressionString(input))
        {
            ErrorMessage();
            if (askRepeat())
            {
                continue;
            }
            else
            {
                break;
            }
        }

        for (i = 0; i < strlen(input); i++)
        {
            count = 1;
            while (i < strlen(input) - 1 && input[i] == input[i + 1])
            {
                count++;
                i++;
            }
            if (count == 1)
            {
                j += sprintf(&compressed[j], "%c", input[i]);
            }
            else
            {
                j += sprintf(&compressed[j], "%d%c", count, input[i]);
            }
        }
        compressed[j] = '\0';

        do
        {
            printf("[EXTRA FEATURE] Choose output format:\n");
            printf("[1] Raw\n");
            printf("[2] Spaced\n");
            printf("Choice: ");
            scanf("%d", &format);
            if (format != 1 && format != 2)
            {
                printf(RED "Invalid choice. Please enter 1 or 2.\n" RESET);
            }
        } while (format != 1 && format != 2);

        char formattedOutput[400];
        chooseOutputFormat(formattedOutput, compressed, format);

        printf(GREEN "Compressed string: %s\n", formattedOutput, RESET);

        printf(RESET "Press any key to continue...");
        while (getchar() != '\n')
            ; // Clear the input buffer
        getchar();
        break;
    }
}

// Function to check if the string is valid for compression
int isValidCompressionString(const char *str)
{
    while (*str)
    {
        if (!isalpha(*str))
        {
            return 0;
        }
        str++;
    }
    return 1;
}

// Function to check if the string is valid for expansion
int isValidExpansionString(const char *str)
{
    int hasDigit = 0;
    while (*str)
    {
        if (!isdigit(*str) && !isalpha(*str))
        {
            return 0;
        }
        if (isdigit(*str))
        {
            hasDigit = 1;
        }
        str++;
    }
    return hasDigit;
}

// Function to ask user if they want to repeat the process
int askRepeat()
{
    char input[10];
    while (1)
    {
        if (input[strlen(input) - 1] != '\n')
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }

        printf("Do you want to repeat the process? (Y/N): ");
        fgets(input, sizeof(input), stdin);

        // Check if the input is a single character followed by a newline
        if (strlen(input) == 2 && (input[0] == 'Y' || input[0] == 'y' || input[0] == 'N' || input[0] == 'n'))
        {
            if (input[0] == 'Y' || input[0] == 'y')
            {
                return 1;
            }
            else if (input[0] == 'N' || input[0] == 'n')
            {
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

void chooseOutputFormat(char *output, const char *input, int format)
{
    int i, j = 0;
    output[0] = '\0'; // Properly initialize the output string

    if (format == 1)
    {
        strcpy(output, input);
    }
    else
    {
        for (i = 0; i < strlen(input); i++)
        {
            if (i > 0)
            {
                output[j++] = ' ';
            }
            output[j++] = input[i];
        }
        output[j] = '\0'; // Ensure null termination
    }
}