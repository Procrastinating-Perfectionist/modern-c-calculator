#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// ANSI Color Codes for a professional CLI look
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define CYN   "\x1B[36m"
#define RESET "\x1B[0m"

// Function Prototypes
void saveToHistory(double n1, char op, double n2, double res);
void viewHistory();
void clearHistory();
void clearBuffer();

int main() {
    int choice;
    char op;
    double num1, num2, result;

    while (1) {
        system("cls"); // Use "clear" if on Mac/Linux
        printf(CYN "==========================================\n");
        printf("        CALCULATOR SYSTEM     \n");
        printf("==========================================\n" RESET);
        printf("1. " GRN "Basic Math" RESET " (+, -, *, /)\n");
        printf("2. " GRN "Power Function" RESET " (x^y)\n");
        printf("3. " YEL "View History" RESET "\n");
        printf("4. " RED "Clear History" RESET "\n");
        printf("5. Exit\n");
        printf("------------------------------------------\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf(RED "Invalid choice! Press Enter to try again." RESET);
            clearBuffer();
            getchar();
            continue;
        }

        if (choice == 5) break;

        switch (choice) {
            case 1:
                printf("\nEnter operator (+, -, *, /): ");
                scanf(" %c", &op);
                printf("Enter two numbers: ");
                if (scanf("%lf %lf", &num1, &num2) != 2) {
                    printf(RED "Error: Please enter valid numbers!\n" RESET);
                    clearBuffer();
                } else {
                    if (op == '+') result = num1 + num2;
                    else if (op == '-') result = num1 - num2;
                    else if (op == '*') result = num1 * num2;
                    else if (op == '/') {
                        if (num2 == 0) {
                            printf(RED "Math Error: Division by zero!\n" RESET);
                            break;
                        }
                        result = num1 / num2;
                    } else {
                        printf(RED "Invalid Operator!\n" RESET);
                        break;
                    }
                    printf(GRN "\nRESULT: %.2lf %c %.2lf = %.2lf\n" RESET, num1, op, num2, result);
                    saveToHistory(num1, op, num2, result);
                }
                break;

            case 2:
                printf("\nEnter base number: ");
                scanf("%lf", &num1);
                printf("Enter exponent: ");
                scanf("%lf", &num2);
                result = pow(num1, num2);
                printf(GRN "\nRESULT: %.2lf ^ %.2lf = %.2lf\n" RESET, num1, num2, result);
                saveToHistory(num1, '^', num2, result);
                break;

            case 3:
                viewHistory();
                break;

            case 4:
                clearHistory();
                break;

            default:
                printf(RED "Invalid selection!\n" RESET);
        }

        printf("\nPress Enter to return to Menu...");
        clearBuffer();
        getchar();
    }

    printf(CYN "\nThank you for using . Goodbye!\n" RESET);
    return 0;
}

// Logic to append calculations to a text file
void saveToHistory(double n1, char op, double n2, double res) {
    FILE *f = fopen("history.txt", "a");
    if (f != NULL) {
        fprintf(f, "[LOG] %.2lf %c %.2lf = %.2lf\n", n1, op, n2, res);
        fclose(f);
    }
}

// Logic to read from history.txt
void viewHistory() {
    char line[100];
    FILE *f = fopen("history.txt", "r");
    printf(YEL "\n--- CALCULATION LOG ---\n" RESET);
    if (f == NULL) {
        printf("No records found.\n");
        return;
    }
    while (fgets(line, sizeof(line), f)) {
        printf("%s", line);
    }
    fclose(f);
}

// Logic to delete the history file
void clearHistory() {
    if (remove("history.txt") == 0) 
        printf(GRN "\nLog file deleted successfully.\n" RESET);
    else 
        printf(RED "\nNo log file found to delete.\n" RESET);
}

// Utility to fix the common C scanf buffer bug
void clearBuffer() {
    while (getchar() != '\n');
}
