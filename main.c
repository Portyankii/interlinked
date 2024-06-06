#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

// Declare the Fortran functions
double add(double x, double y);
double subtract(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);
double squareroot(double x);
double solve_linear(double a, double b, double c, double x_coefficient, double y_coefficient);

void initUI() {
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
}

void endUI() {
    endwin();
}

void displayMenu() {
    clear(); // Clear the screen before displaying the menu
    printw("Calculator\n");
    printw("1. Add\n");
    printw("2. Subtract\n");
    printw("3. Multiply\n");
    printw("4. Divide\n");
    printw("5. Square Root\n");
    printw("6. Solve Linear Equation\n");
    printw("7. Exit\n");
    printw("Choose an option: ");
    refresh(); // Update the display
}

int parseEquation(const char* input, double* a, double* b, double* c) {
    // parser
    if (sscanf(input, "%lfx + %lfy = %lf", a, b, c) == 3) {
        return 0; // Successfully parsed
    }
    if (sscanf(input, "%lfx + %lfx = %lf", a, b, c) == 3) { // hopefully handels cases where A & B have the same variable
        return 0;
    }
    return -1; // Error parsing
}

int main() {
    initUI();

    int choice;
    double x, y, result;
    double a, b, c;
    char equation[100];

    // Array of function pointers for binary operations
    double (*operations_bin[])(double, double) = {add, subtract, multiply, divide};
    // Function pointer for unary operations
    double (*operations_un[])(double) = {squareroot};

    while (1) {
        displayMenu();
        choice = getch() - '0';

        if (choice >= 1 && choice <= 6) { // Adjust range based on the number of options
            if (choice >= 1 && choice <= 4) { // Prompt for two numbers for binary operations
                printw("\nEnter two numbers: ");
                scanw("%lf %lf", &x, &y);
                result = operations_bin[choice - 1](x, y);
            } else if (choice == 5) { // Prompt for one number for square root
                printw("\nEnter a number: ");
                scanw("%lf", &x);
                result = operations_un[0](x);

                
            } else if (choice == 6) { // Prompt for linear equation
                printw("\nEnter equation (ax + by = c): ");
                getnstr(equation, 100);
                if (parseEquation(equation, &a, &b, &c) == 0) {
                    // Assuming x_coefficient = 1 and y_coefficient = 1 for simplicity
                    result = solve_linear(a, b, c, 1.0, 1.0);
                } else {
                    printw("Error: Could not parse the equation.\n");
                    refresh();
                    getch();
                    continue;
                } 
            }

            printw("Result: %lf\n", result);
            refresh(); // Update the display with the result
            getch(); // Wait for user input before redisplaying the menu
        } else if (choice == 7) {
            break; // Exit the loop and end the program
        } else {
            printw("\nPick a valid option!\n");
            refresh();
            napms(2000); // Wait for 2 seconds before redisplaying the menu
        }
    }

    endUI();
    return 0;
}
