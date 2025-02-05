// This program converts a given infix expression to its equivalent postfix expression
// and then evaluate the expression.

//  Richelle S. de Arce | 2023-15674
// Work on:
// Cherlie Joy Palarpalar | 2023-XXXX
// Work on:

//  Date: Feb 5, 2025 - Feb

#include <stdio.h>
#include <stdlib.h> //We include dynamic memory allocation

// Colors to emphasize text
#define GREEN "\x1b[32m"
#define RED "\x1b[41m"
#define RESET "\x1b[0m"

// Function prototype
void Menu();
void ProgDesc();
void Execute();
char *getInfix();
int chooseOperation();

int main()
{
    char choice;

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
    { // Program Execution
        printf(GREEN "\n---EVALUATE EXPRESSION(S)---" RESET "\n");
        Execute();
        main();
    }
    else if (choice == 'X' || choice == 'x')
    { // Exiting the Program
        printf(GREEN "---TERMINATING PROGRAM---" RESET "\n");
        return 0;
    }
    else
    {
        printf(RED "invalid Input Try Again..." RESET "\n"); // Invalid Input
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

    printf(GREEN "---PROGRAM OVERVIEW---" RESET "\n");
    printf("1.Convert infix expressions to postfix notation.\n");
    printf("2.Evaluate postfix expressions to get the final result.\n");
    printf("3.Handle invalid expressions with appropriate error messages.\n\n");

    printf(GREEN "---MENU OPTIONS---" RESET "\n");
    printf("[P] Program Description Displays details about the program, development timeline, and contributors.\n");
    printf("[E] Evaluate Expression(s) Allows users to input an infix expression, convert it to postfix, and evaluate it.\n");
    printf("[X] Exit Exits the program immediately.\n\n");

    printf(GREEN "---CONTRIBUTORS & ROLES---" RESET "\n");
    printf("[Your Name] Implemented infix-to-postfix conversion.\n");
    printf("[Teammate's Name]  Developed postfix evaluation logic.\n");
    printf("[Another Teammate's Name] Designed the menu system and input handling.\n\n");
}

void Execute() // Input and conversion
{
    int conOperation;
    char *infixExpression = getInfix(); // Infix Input

    conOperation = chooseOperation(); // function for detailed code "Choose operations"

    switch (conOperation) // Operation
    {
    case 0:
        printf(GREEN "---GOING TO MAIN MENU---" RESET "\n"); // Return to main menu
        return;

    case 1:
        // infix to postfix (Richelle)
        // Evaluating the expression (Cherlie)
        break;

    case 2:
        // CHERLIE HERE (ikaw bahala anong type of conversion imoha)
        // Evaluating the expression (Cherlie)

        break;

    default:
        printf(RED "Invalid Input Try Again..." RESET "\n");
        break;
    }

    if (infixExpression != NULL)
    {
        printf("You entered: %s", infixExpression);
        free(infixExpression); // Free allocated memory
    }
}

char *getInfix()
{
    int size;

    // Ask for input size
    printf("Enter the size of the infix equation: ");
    scanf("%d", &size);

    // Allocate memory dynamically
    char *infix = (char *)malloc((size + 1) * sizeof(char)); // +1 for null terminator
    if (infix == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    // Clear input buffer
    getchar();

    // Get infix expression from the user
    printf("Enter infix expression: ");
    fgets(infix, size + 1, stdin); // Safe input method

    return infix; // Return the allocated string
}

int chooseOperation()

{
    int num;

    printf(GREEN "---CHOOSE YOUR CONVERSION---" RESET "\n");
    printf("[0] BACK TO MENU\n");
    printf("[1] infix - postfix\n");
    printf("[2] Cherlie feature\n");
    printf("Choose: ");
    scanf("%d", &num);

    return num;
}