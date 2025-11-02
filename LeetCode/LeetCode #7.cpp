/*
7. Reverse Integer
Solved
Medium
Topics
premium lock icon
Companies
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).



Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21


Constraints:

-231 <= x <= 231 - 1
*/

#include "Leetcode dep.h"
using namespace std;

// Function that reverses an integer
int reverseNumber(int x) {
    long long rev = 0; // Use long long to detect overflow

    while(x != 0) {
        int digit = x % 10;          // Get last digit
        rev = rev * 10 + digit;      // Build reversed number

        // Check for overflow beyond 32-bit integer range
        if(rev > INT_MAX || rev < INT_MIN)
            return 0;

        x /= 10; // Remove last digit from x
    }

    return (int)rev; // Cast back to int before returning
}

int main() {
    int num;
    cout << "Enter an integer: ";
    cin >> num;

    int result = reverseNumber(num);

    if(result == 0 && (num != 0)) {
        cout << "Reversed number overflowed 32-bit limit!" << endl;
    }
    else {
        cout << "Reversed number: " << result << endl;
    }

    return 0;
}
