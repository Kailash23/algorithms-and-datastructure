/*
   Multiplication (Recursive)

   Given two integers m & n, calculate and return their multiplication using
   recursion. You can only use subtraction and addition for your calculation.
   No other operators are allowed.
   Input format : m and n (separated by space)
 */

#include <iostream>
using namespace std;

int multiplyNumbers(int m, int n) {
    if (n == 0) {
        return 0;
    }
    return m + multiplyNumbers(m, n - 1);
}

int main() {
    int m = 3;
    int n = 4;
    cout << multiplyNumbers(m, n);
}

/*
   12
 */
