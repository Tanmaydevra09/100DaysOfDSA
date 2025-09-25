#include <iostream>
using namespace std;

// Factorial
int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

// Sum of first N numbers
int sumN(int n) {
    if (n == 0)
        return 0;
    return n + sumN(n - 1);
}

// Power: x^y
int power(int x, int y) {
    if (y == 0)
        return 1;
    return x * power(x, y - 1);
}

// Print numbers 1 to N (increasing)
void printIncreasing(int n) {
    if (n == 0)
        return;
    printIncreasing(n - 1);
    cout << n << " ";
}

// Print numbers N to 1 (decreasing)
void printDecreasing(int n) {
    if (n == 0)
        return;
    cout << n << " ";
    printDecreasing(n - 1);
}

int main() {
    int n, x, y;

    cout << "Enter a number for factorial and sum: ";
    cin >> n;

    cout << "Factorial of " << n << " = " << factorial(n) << endl;
    cout << "Sum of first " << n << " numbers = " << sumN(n) << endl;

    cout << "Enter base and exponent for power: ";
    cin >> x >> y;
    cout << x << "^" << y << " = " << power(x, y) << endl;

    cout << "Numbers from 1 to " << n << " (increasing): ";
    printIncreasing(n);
    cout << endl;

    cout << "Numbers from " << n << " to 1 (decreasing): ";
    printDecreasing(n);
    cout << endl;

    return 0;
}
