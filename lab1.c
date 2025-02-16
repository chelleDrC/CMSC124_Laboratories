#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Colors to emphasize text
#define GREEN "\x1b[32m"
#define RED "\x1b[41m"
#define RESET "\x1b[0m"

// Function prototypes
void push(char stack[], int *top, char c);
char pop(char stack[], int *top);
char peek(char stack[], int top);
int precedence(char op);
int isOperator(char c);
int isValidChar(char c);
int isValidExpression(const char *expr);
void infixToPostfix(const char *infix, char *postfix);
int evaluatePostfix(const char *postfix);
void postfixToInfix(const char *postfix, char *infix);
void displayProgramDescription();

int main()
{
    char choice;
    char infix[MAX], postfix[MAX], resultInfix[MAX];
    int result;

    do
    {
        // Display menu options
        printf(GREEN "Welcome to this Expression Evaluator program! Please choose an action to perform...\n" RESET);
        printf("[P] Program Description\n[E] Evaluate Expression(s)\n[F] Postfix to Infix (Additional Feature)\n[X] Exit\nChoice: ");
        scanf(" %c", &choice);
        choice = toupper(choice);

        switch (choice)
        {
        case 'P':
            system("cls");
            displayProgramDescription();
            break;
        case 'E':
            printf("Enter infix expression: ");
            getchar(); // Clear the newline character left by scanf
            fgets(infix, sizeof(infix), stdin);
            infix[strcspn(infix, "\n")] = '\0'; // Remove the newline character

            if (!isValidExpression(infix))
            {
                printf(RED "Invalid infix expression.\n" RESET);
            }
            else
            {
                infixToPostfix(infix, postfix);
                result = evaluatePostfix(postfix);
                system("cls");
                printf("Postfix Expression: %s\n", postfix);
                printf("Result: %d\n", result);
            }
            break;
        case 'F':
            printf("Enter postfix expression: ");
            getchar(); // Clear the newline character left by scanf
            fgets(postfix, sizeof(postfix), stdin);
            postfix[strcspn(postfix, "\n")] = '\0'; // Remove the newline character

            postfixToInfix(postfix, resultInfix);
            system("cls");
            printf("Infix Expression: %s\n", resultInfix);
            break;
        case 'X':
            system("cls");
            printf("Exiting program. Goodbye!\n");
            break;
        default:
            system("cls");
            printf(RED "Invalid choice. Please enter P, E, F, or X.\n" RESET);
        }
    } while (choice != 'X');

    return 0;
}

// Push a character onto the stack
void push(char stack[], int *top, char c)
{
    if (*top < MAX - 1)
    {
        stack[++(*top)] = c;
    }
}

// Pop a character from the stack
char pop(char stack[], int *top)
{
    if (*top >= 0)
    {
        return stack[(*top)--];
    }
    return '#'; // Return a dummy character if stack is empty
}

// Peek the top character of the stack
char peek(char stack[], int top)
{
    if (top >= 0)
    {
        return stack[top];
    }
    return '#'; // Return a dummy character if stack is empty
}

// Return the precedence of an operator
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

// Check if a character is an operator
int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

// Check if a character is valid in an expression
int isValidChar(char c)
{
    return isdigit(c) || isOperator(c) || c == '(' || c == ')' || c == ' ';
}

// Validate the infix expression
int isValidExpression(const char *expr)
{
    int i, hasOperand = 0;
    for (i = 0; expr[i]; i++)
    {
        if (!isValidChar(expr[i]))
        {
            return 0;
        }
        if (isdigit(expr[i]))
        {
            hasOperand = 1;
        }
    }
    return hasOperand;
}

// Convert infix expression to postfix expression
void infixToPostfix(const char *infix, char *postfix)
{
    char stack[MAX];
    int top = -1;
    int i, j = 0;
    for (i = 0; infix[i]; i++)
    {
        if (isdigit(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == ' ')
        {
            continue;
        }
        else if (infix[i] == '(')
        {
            push(stack, &top, '(');
        }
        else if (infix[i] == ')')
        {
            while (top != -1 && peek(stack, top) != '(')
            {
                postfix[j++] = pop(stack, &top);
            }
            pop(stack, &top); // Remove '(' from stack
        }
        else if (isOperator(infix[i]))
        {
            postfix[j++] = ' ';
            while (top != -1 && precedence(peek(stack, top)) >= precedence(infix[i]))
            {
                postfix[j++] = pop(stack, &top);
            }
            push(stack, &top, infix[i]);
        }
    }
    while (top != -1)
    {
        postfix[j++] = pop(stack, &top);
    }
    postfix[j] = '\0';
}

// Evaluate a postfix expression
int evaluatePostfix(const char *postfix)
{
    int stack[MAX], top = -1, i, a, b;
    for (i = 0; postfix[i]; i++)
    {
        if (isdigit(postfix[i]))
        {
            int num = 0;
            while (isdigit(postfix[i]))
            {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            i--;
            stack[++top] = num;
        }
        else if (postfix[i] == ' ')
        {
            continue;
        }
        else if (isOperator(postfix[i]))
        {
            b = stack[top--];
            a = stack[top--];
            switch (postfix[i])
            {
            case '+':
                stack[++top] = a + b;
                break;
            case '-':
                stack[++top] = a - b;
                break;
            case '*':
                stack[++top] = a * b;
                break;
            case '/':
                stack[++top] = a / b;
                break;
            case '%':
                stack[++top] = a % b;
                break;
            }
        }
    }
    return stack[top];
}

// Convert postfix expression to infix expression
void postfixToInfix(const char *postfix, char *infix)
{
    char stack[MAX][MAX];
    int top = -1;
    int i;
    char temp[2];
    temp[1] = '\0';

    for (i = 0; postfix[i]; i++)
    {
        if (isdigit(postfix[i]))
        {
            char operand[MAX] = "";
            while (isdigit(postfix[i]))
            {
                temp[0] = postfix[i];
                strcat(operand, temp);
                i++;
            }
            i--;
            strcpy(stack[++top], operand);
        }
        else if (postfix[i] == ' ')
        {
            continue;
        }
        else if (isOperator(postfix[i]))
        {
            char op2[MAX], op1[MAX], exp[MAX];
            strcpy(op2, stack[top--]);
            strcpy(op1, stack[top--]);
            snprintf(exp, sizeof(exp), "(%s%c%s)", op1, postfix[i], op2);
            strcpy(stack[++top], exp);
        }
    }
    strcpy(infix, stack[top]);
}

// Display the program description
void displayProgramDescription()
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
    printf("[F] - Postfix to Infix (Additional Feature)\n");
    printf("Additional Info: This program handles basic arithmetic expressions with integers.\n\n");
}
