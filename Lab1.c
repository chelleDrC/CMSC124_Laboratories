// This is a program that will convert infix expressions to postfix notation and evaluate the postfix expression to get the final result.
//  It will also handle invalid expressions (such as ? < >) with appropriate error messages. The program will display a menu.
// Programmer: Richelle S. de Arce & Cherlie Joy Palarpalar
// Date: Feb 5, 2025 - Feb 13, 2025

#include <stdio.h>
#include <stdlib.h> //We include dynamic memory allocation
#include <ctype.h>  //for checking the Expression
#include <string.h> //for string manipulation

// Colors to emphasize text
#define GREEN "\x1b[32m"
#define RED "\x1b[41m"
#define RESET "\x1b[0m"

// Function prototype
void Menu();
void ProgDesc();
void Execute();
int getInfix(char *infix, int size);
int chooseOperation();
int isValidExpression(const char *str);
void ErrorMessage();
void infixToPostfix(const char *infixExpression);
int evaluatePostfix(const char *postFix);
void postfixToInfix(const char *postFix, char *result);
int precedence(char op);

// Main function
int main()
{

    char choice;
    // Call the Menu function
    Menu();

    // Input
    printf("Choice: ");
    scanf(" %c", &choice);
    system("cls");
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
        ErrorMessage();
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
    printf("Cherlie Joy Palarpalar (2023-16099)\n");
    printf("Development Period: Feb 5, 2025 - Feb 13, 2025\n\n");

    printf(GREEN "---PROGRAM OVERVIEW---" RESET "\n");
    printf("1.Convert infix expressions to postfix notation and evaluate the expression.\n");
    printf("2.Evaluate postfix notation to infix expression.\n\n");

    printf(GREEN "---MENU OPTIONS---" RESET "\n");
    printf("[P] Program Description Displays details about the program, development timeline, and contributors.\n");
    printf("[E] Evaluate Expression(s) Allows users to input an infix expression, convert it to postfix, and evaluate it.\n");
    printf("[X] Exit Exits the program immediately.\n\n");

    printf(GREEN "---CONTRIBUTORS & ROLES---" RESET "\n");
    printf("Richelle | Implemented infix-to-postfix conversion.\n");
    printf("Cherlie |  Developed postfix-to-infix \n");
    printf("Cherlie & Richelle | Designed the menu system and input handling.\n\n");
}

void Execute() // Input and conversion
{
    int length;

    length = 999; // Maximum length of the inputcls
    int conOperation;

    char InputExpression[1000];            // Infix Input
    if (getInfix(InputExpression, length)) // Get infix input and check if user wants to Exit to main menu
    {
        system("cls");
        printf(GREEN "---GOING TO MAIN MENU---" RESET "\n");
        return;
    }

    conOperation = chooseOperation(); // function for detailed code "Choose operations"

    switch (conOperation) // Operation
    {
    case 0:
        system("cls");
        printf(GREEN "---GOING TO MAIN MENU---" RESET "\n"); // Return to main menu
        return;
        break;

    case 1:
        printf(GREEN "---INFIX TO POSTFIX---" RESET "\n");
        infixToPostfix(InputExpression); // Convert infix to postfix
        Execute();
        break;

    case 2:
        printf(GREEN "---POSTFIX TO INFIX---" RESET "\n");
        char result[1000];
        postfixToInfix(InputExpression, result); // Convert postfix to infix
        printf(GREEN "INFIX: %s" RESET "\n\n", result);
        Execute();

        break;

    default:
        ErrorMessage();
        break;
    }
}

int getInfix(char *infix, int size)
{
    while (1)
    {
        // Clear input buffer
        getchar();

        // Get infix expression from the user
        printf("You can Enter an Infix or Postfix Expression to be converted vice versa\n");
        printf("(Enter [0] to return to the exit menu.)\n");
        printf("(This is an additional Feature)\n");
        printf("Enter Expression: ");
        scanf(" %[^\n]", infix);

        if (strcmp(infix, "0") == 0)
        {
            return 1; // Exit if the user enters '0'
            break;
        }

        if (isValidExpression(infix))
        {
            printf(GREEN "\nValid expression" RESET "\n");
            return 0;
            break; // Exit the loop if the expression is valid
        }
        else
        {
            ErrorMessage();
        }
    }
}

int chooseOperation()
{
    int num;

    printf(GREEN "---CHOOSE YOUR CONVERSION---" RESET "\n");
    printf("[0] BACK TO MENU\n");
    printf("[1] infix - postfix\n");
    printf("[2] Postfix - infix (additional Feature)\n");
    printf("Choose: ");
    scanf(" %d", &num);
    system("cls");
    return num;
}

int isValidExpression(const char *str)
{
    while (*str)
    {
        // Check if the character is a number, operator, parentheses, or space
        if (!(isdigit(*str) ||                                                           // ✅ Numbers (0-9)
              *str == '+' || *str == '-' || *str == '*' || *str == '/' || *str == '%' || // ✅ Operators
              *str == '(' || *str == ')' ||                                              // ✅ Parentheses
              isspace(*str)))                                                            // ✅ Spaces (allowed as delimiters)
        {
            return 0; // ❌ Invalid character found
        }
        str++; // Move to the next character
    }
    return 1; // ✅ String is valid
}

void ErrorMessage()
{
    printf(RED "Invalid Input Try Again..." RESET "\n");
}

int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    default:
        return 0;
    }
}

void postfixToInfix(const char *postFix, char *result)
{
    char *stack[100];
    int stackIndex = 0;
    int i = 0;

    while (postFix[i] != '\0')
    {
        if (isspace(postFix[i]))
        {
            i++;
            continue;
        }

        if (isdigit(postFix[i]))
        {
            char num[20];
            int numIndex = 0;
            while (isdigit(postFix[i]))
            {
                num[numIndex++] = postFix[i++];
            }
            num[numIndex] = '\0';
            stack[stackIndex] = (char *)malloc((numIndex + 1) * sizeof(char));
            strcpy(stack[stackIndex++], num);
        }
        else if (strchr("+-*/%", postFix[i]))
        {
            char *b = stack[--stackIndex];
            char *a = stack[--stackIndex];

            char *expr = (char *)malloc(strlen(a) + strlen(b) + 4);
            sprintf(expr, "(%s%c%s)", a, postFix[i], b);

            free(a);
            free(b);

            stack[stackIndex++] = expr;
            i++;
        }
    }

    strcpy(result, stack[--stackIndex]);
}

int evaluatePostfix(const char *postFix)
{
    int stack[100];     // Stack to store operands
    int stackIndex = 0; // Index for the stack
    int i = 0;          // Index for the postfix expression

    while (postFix[i] != '\0')
    {
        if (isspace(postFix[i]))
        {
            i++;
            continue; // Skip spaces
        }

        if (isdigit(postFix[i]))
        {
            int num = 0;
            while (isdigit(postFix[i]))
            {
                num = num * 10 + (postFix[i++] - '0'); // Convert string to integer
            }
            stack[stackIndex++] = num; // Push the number onto the stack
        }
        else
        {
            int b = stack[--stackIndex]; // Pop the top two elements
            int a = stack[--stackIndex];
            switch (postFix[i])
            {
            case '+':
                stack[stackIndex++] = a + b; // Perform addition
                break;
            case '-':
                stack[stackIndex++] = a - b; // Perform subtraction
                break;
            case '*':
                stack[stackIndex++] = a * b; // Perform multiplication
                break;
            case '/':
                stack[stackIndex++] = a / b; // Perform division
                break;
            case '%':
                stack[stackIndex++] = a % b; // Perform modulus
                break;
            }
            i++;
        }
    }
    return stack[0]; // The result is the last element in the stack
}

void infixToPostfix(const char *infixExpression)
{
    int length = strlen(infixExpression);

    char stack[1000];   // Stack to store operators
    char postFix[2000]; // Output postfix expression

    int postfixIndex = 0; // Index for the postfix expression
    int stackIndex = 0;   // Index for the stack
    int i;

    for (i = 0; i < length; i++)
    {
        if (isspace(infixExpression[i]))
        {
            continue; // Skip spaces
        }
        if (isdigit(infixExpression[i]))
        {
            // Collect multi-digit number
            while (isdigit(infixExpression[i]))
            {
                postFix[postfixIndex++] = infixExpression[i++]; // Add number to postfix expression
            }
            postFix[postfixIndex++] = ' '; // Separate numbers in postfix
            i--;                           // Go back one position after loop
        }
        else if (infixExpression[i] == '(')
        {
            stack[stackIndex++] = '('; // Push '(' to stack
        }
        else if (infixExpression[i] == ')')
        {
            while (stackIndex > 0 && stack[stackIndex - 1] != '(')
            {
                postFix[postfixIndex++] = stack[--stackIndex]; // Pop from stack to postfix expression
                postFix[postfixIndex++] = ' ';
            }
            if (stackIndex > 0 && stack[stackIndex - 1] == '(')
            {
                stackIndex--; // Pop '('
            }
        }
        else if (strchr("+-*/%", infixExpression[i]))
        {
            while (stackIndex > 0 && precedence(stack[stackIndex - 1]) >= precedence(infixExpression[i]))
            {
                postFix[postfixIndex++] = stack[--stackIndex]; // Pop from stack to postfix expression
                postFix[postfixIndex++] = ' ';
            }
            stack[stackIndex++] = infixExpression[i]; // Push operator to stack
        }
    }

    while (stackIndex > 0)
    {
        postFix[postfixIndex++] = stack[--stackIndex]; // Pop remaining operators to postfix expression
        postFix[postfixIndex++] = ' ';
    }

    if (postfixIndex > 0 && postFix[postfixIndex - 1] == ' ')
    {
        postfixIndex--; // Remove trailing space
    }

    postFix[postfixIndex] = '\0'; // Null-terminate the postfix expression

    printf(GREEN "POSTFIX: %s" RESET "\n", postFix);

    int result = evaluatePostfix(postFix); // Evaluate the postfix expression
    printf(GREEN "Evaluating Expression: %d" RESET "\n\n", result);
}
