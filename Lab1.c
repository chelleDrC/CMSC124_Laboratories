// This program converts a given infix expression to its equivalent postfix expression
// and then evaluate the expression.

//  Richelle S. de Arce | 2023-15674
// Work on:
// Cherlie Joy Palarpalar | 2023-XXXX
// Work on:

//  Date: Feb 5, 2025 - Feb

#include <stdio.h>

// Function prototype
void Menu();
void ProgDesc();
void Execute();

int main()
{
    char choice;

    // Call the Menu function
    Menu();

    // Input
    printf("Choice: ");
    scanf(" %c", &choice);

    // Choices
    if (choice == 'P' || 'p')
    { // Program Description
        printf("\n---PROGRAM DESCRIPTION---\n");
        ProgDesc();
        main();
    }
    else if (choice == 'E' || 'e')
    { // Program Execution
        printf("\n---EVALUATE EXPRESSION(S)---\n");
        Execute();
        main();
    }
    else if (choice == 'X' || 'x')
    { // Exiting the Program
        printf("---TERMINATING PROGRAM---");
        return 0;
    }
    else
    {
        printf("invalid Input Try Again..."); // Invalid Input
        main();
    }
}

// Function to display the Menu
void Menu()
{
    printf("Welcome to this Expression Evaluator program!\n");
    printf("Please choose an action to perform...\n");
    printf("[P] Program Description\n");
    printf("[E] Evaluate Expression(s)\n");
    printf("[X] Exit\n");
}
// Display Proram Description
void ProgDesc()
{

    printf("Date: Feb 5, 2025 - Feb\n");
    printf("Developed by:\n");
    printf("Richelle S. de Arce (2023-15674)\n");
    printf("Cherlie Joy Palarpalar (2023-XXXX)\n");
    printf("Development Period: [Start Date] - [End Date]\n\n");

    printf("---PROGRAM OVERVIEW---\n");
    printf("1.Convert infix expressions to postfix notation.\n");
    printf("2.Evaluate postfix expressions to get the final result.\n");
    printf("3.Handle invalid expressions with appropriate error messages.\n\n");

    printf("---MENU OPTIONS---\n");
    printf("[P] Program Description – Displays details about the program, development timeline, and contributors.\n");
    printf("[E] Evaluate Expression(s) – Allows users to input an infix expression, convert it to postfix, and evaluate it.\n");
    printf("[X] Exit – Exits the program immediately.\n\n");

    printf("---CONTRIBUTORS & ROLES---\n");
    printf("[Your Name] – Implemented infix-to-postfix conversion.\n");
    printf("[Teammate’s Name] – Developed postfix evaluation logic.\n");
    printf("[Another Teammate’s Name] – Designed the menu system and input handling.\n\n");
}
void Execute()
{
}
