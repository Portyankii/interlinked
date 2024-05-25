#include <stdio.h>
#include <ncurses.h>

// Remember to actully declare the fortran functions dumbass
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b); // Added
double divide(double a, double b);   // Added
double squareroot(double a); // cant belive the fix was thgat shrimple


void initUI() {
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
}

void endUI() {
    endwin();
}

void displayMenu() {
    clear(); // Added to clear the screen before displaying the menu
    printw("Calculator\n");
    printw("1. Add\n");
    printw("2. Subtract\n");
    printw("3. Multiply\n");
    printw("4. Divide\n");
    printw("5. Square Root\n");
    // Additional menu items...
    printw("Choose an option: ");
    refresh(); // Added to update the display
}

int main() {
    initUI();

    int choice;
    double a, b, result;
    while (1) {
        displayMenu();
        choice = getch() - '0';

        if (choice >= 1 && choice <= 5) { // Adjust range based on the number of options
            if (choice >= 1 && choice <= 4) { // Prompt for two numbers for operations 1-4
                printw("\nEnter two numbers: ");
                scanw("%lf %lf", &a, &b);
            } else if (choice == 5) { // Prompt for one number for square root
                printw("\nEnter a number: ");
                scanw("%lf", &a);
            }

            switch (choice) {
                case 1:
                    printw("Enter number 1: ");
                    result = add(a, b);
                    break;
                case 2:
                    result = subtract(a, b);
                    break;
                case 3:
                    result = multiply(a, b); 
                    break;
                case 4:
                    result = divide(a, b);   
                    break;
                case 5:
                    result = squareroot(a);
                    break;
                // 
            }

            printw("Result: %lf\n", result);
            break; // Exit the loop after a valid operation
        } else {
            printw("\nPick a valid option!\n");
            refresh();
            napms(3000); // Wait for 1 second before redisplaying the menu
        }
    }

    getch();
    endUI();
    return 0;
}
