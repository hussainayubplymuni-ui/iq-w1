//  LHPK4014 - Software Engineering 1
//Assessment 1 (W1): Set Exercises - Combined Program
//  Personalization Number: 4827

/*
 This program consists of 10 short exercises.
 Each exercise is written in its own function (task1 to task10).
 All exercises are called in order from the main() function.
 The personalization number 4827 is used for each exercise.
 Only Task 1 ,2 and 9 reads input from the user.
 All other tasks use values based on the assignment specifications
 and personalization number.
*/

#include <iostream>
#include <string>
using namespace std;

// Function prototypes
void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7(string name, int marks);   // Exercise 7 uses parameters
void task8();
double ComputeAverage();              // helper for Exercise 9
void task9();
void task10();

// Global variables (used by Task 10) 
int personalizationNum = 4827;        // global from my personalization number
int globalCount = personalizationNum; // global counter starts at 4827

// using main
//  main runs all ten exercises in order

int main() {
    cout << " Task 1 " << endl;  task1();
    cout << "\n Task 2 " << endl;  task2();
    cout << "\n Task 3 " << endl;  task3();
    cout << "\n Task 4 " << endl;  task4();
    cout << "\n Task 5 " << endl;  task5();
    cout << "\nTask 6 " << endl;  task6();
    cout << "\nTask 7 " << endl;  task7("4827", 27); // name + marks passed as parameters
    cout << "\n Task 8 " << endl;
    for (int i = 0; i < 5; i++) task8();     // Exercise 8 requires calling the function 5 times
    cout << "\nTask 9 " << endl;  task9();
    cout << "\n Task 10 " << endl; task10();
    return 0;
}


// Task 1 - Variables & Output
// Declares two integers and prints their sum.
// Personalization: Uses the second digit (8) and last digit (7) of 4827.
// Error 1: no user input.

void task1() {
    int a = 8;
    int b = 7;

    cout << "Variables and Output" << endl;
    cout << "Sum : " << a + b << endl;
}


// Task 2 - Arithmetic Operations
// Multiplies two numbers and displays the result.
// Personalization: The first number is the sum of the digits of 4827 (4+8+2+7 = 21).
// The second number is 5 (chosen value).
// Error 2: no user input, duplicate output lines removed.

void task2() {
    int a = 21;
    int b = 5;

    cout << "First number is : " << a << endl;
    cout << "Second number is : " << b << endl;
    cout << "Result = " << a * b << endl;
}


// Task 3 - Loops / Iterations
// Prints a multiplication table from 1 up to N.
// Personalization: N is calculated using 4827 % 10 + 1, which equals 8.
// Error 3: uses the global variable.

void task3() {
    int N = (personalizationNum % 10) + 1;

    for (int i = 1; i <= N; i++) {
        cout << N << " x " << i << " = " << N * i << endl;
    }
}


// Task 4 - If-Else Conditions
// Checks whether a number is even or odd.
// Personalization: uses the full personalization number 4827 (odd).
// Error 3: variable renamed to "number" so it does not hide the global.

void task4() {
    int number = 4827;

    if (number % 2 == 0) {
        cout << number << " is even" << endl;
    } else {
        cout << number << " is odd" << endl;
    }
}


// Task 5 - Switch Case
// Displays the month name for a number between 1 and 12.
// Personalization: month = (4827 % 12) + 1 = 4, so it prints April.
// Error 3: no local copy of personalizationNum any more.

void task5() {
    int month = (4827 % 12) + 1;

    switch (month) {
        case 1:  cout << "January" << endl;   break;
        case 2:  cout << "February" << endl;  break;
        case 3:  cout << "March" << endl;     break;
        case 4:  cout << "April" << endl;     break;
        case 5:  cout << "May" << endl;       break;
        case 6:  cout << "June" << endl;      break;
        case 7:  cout << "July" << endl;      break;
        case 8:  cout << "August" << endl;    break;
        case 9:  cout << "September" << endl; break;
        case 10: cout << "October" << endl;   break;
        case 11: cout << "November" << endl;  break;
        case 12: cout << "December" << endl;  break;
        default: cout << "Invalid month" << endl;
    }
}


//  Task 6 - Arrays
//  Declares an array of five numbers and prints the third value.
//  Personalization: one array value is the last digit of 4827 (7).

void task6() {
    cout << "The array contains five elements" << endl;
    int array[5] = {20, 45, 7, 3, 9};
    cout << "The third value is " << array[2] << endl;
}


//  Task 7 - Functions with Parameters
//  Accepts a name and marks as parameters and displays a
//  personalized welcome message with the marks.
//  Personalization: 4827 passed as name, marks (27) from the
//  last two digits of 4827.

void task7(string name, int marks) {
    cout << "Hello  welcome " << name << endl;
    cout << "Your marks are " << marks << endl;
}
//  Task 8 - Static Local Variable
//  Displays the personalization number and the function call
//  count using a static local variable.
//  Personalization: called 5 times, shows 4827 each time.

void task8() {
    static int count = 0;   // static: keeps its value between calls
    count++;
    cout << " My personalization number is 4827" << endl;
    cout << "Total function count is " << count << endl;
}


//  Task 9 - Debugging (ComputeAverage)
//  Reads marks until -1 is entered, ignores negative marks,
//  and returns the average of the valid marks as a double.
//  The four original bugs are documented inline below.
double ComputeAverage() {
    int total = 0;
    int marks = 0;
    int count = 0;
    do {
        cin >> marks;
        if (marks >= 0) {
            total = total + marks;
            // Bug 1: original code added negative marks too.
            // Fix:  only add marks that are zero or positive.
            count++;
            // Bug 2: original code counted every input.
            // Fix:  count only valid marks.
        }
    } while (marks != -1);
    // Bug 3: original code could divide by zero.
    // Fix:  if no valid marks were entered, return 0.0.
    if (count == 0) {
        return 0.0;
    }
    // Bug 4: original code used integer division.
    // Fix:  cast total to double so the average can include decimals.
    return static_cast<double>(total) / count;
}

void task9() {
    cout << "Enter marks, also enter -1 when you want to stop :" << endl;
    double average = ComputeAverage();
    cout << "The average of the marks is : " << average << endl;
}


//  Task 10 - Global vs Static Variables
//  Global and static variables keep their value between calls,
//  but a global is reachable from any function while a static
//  is only reachable inside its own function; a local resets
//  every call. All three start from 4827.

void showVariables() {
    static int staticCount = personalizationNum; // static: persists across calls
    int localCount = personalizationNum;         // local: resets every call

    globalCount++;
    staticCount++;
    localCount++;
    cout << "Global: " << globalCount << endl;
    cout << "Static: " << staticCount << endl;
    cout << "Local: " << localCount << endl;
    cout << endl;
}

void task10() {
    for (int i = 0; i < 3; i++) showVariables();
}

