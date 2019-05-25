// MHS Project Euler Problem 4                          |
//                                                      |
// Problem Statement:                                   |
//                                                      |
// A palindromic number reads the same both ways.       |
// The largest palindrome made from the product of      |
// two 2-digit numbers is 9009 = 91 × 99.               |
//                                                      |
// Find the largest palindrome made from the            |
// product of two 3-digit numbers.                      |
//                                                      |
//-------------------------------------------------------

// Generic Program
// Enter 3 as input for the above problem

#include <iostream>
#include <cmath>

using namespace std;

// Function to check whether the number is palindrome or not
bool is_palindrome(int x);

int main()
{
    int x, y, maxX = 0;
    cout<<"Enter the number of digits : ";
    cin >> x;

    y = (int) round(pow(10,x));

    for (int i = 0;i < y;i++){
        for (int j=i; j < y;j++){
            if (is_palindrome((y-i)*(y-j)) && (((y-i)*(y-j)) > maxX))
                maxX = (y-i)*(y-j);
        }
    }
    cout << "The largest palindrome number is :"<<maxX<<endl;
    return 0;
}
// The problem can be more easily solved using strings.
// Though, I just wanted to use mathematics to solve it
bool is_palindrome(int x)
{
    // Calculate the number of digits in 'x'
    int i = (int) floor(log10(x)) + 1;

    // Introducing 2 variables for temporary storage
    // Just allows readability. The variable 'a' stores
    // the right most digit and 'b' the left most digit
    // With each iteration, 'a' and 'b' move inwards
    int a, b;

    for(int k = 0;k <= i/2 - 1;k++){

        a = ((int)(x/round(pow(10,k))))%10;
        b = ((int)(x/round(pow(10,i-1-k))))%10;

        if (a != b)
            return false;
    }
    return true;
}
