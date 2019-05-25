// MHS Project Euler Problem 1                              |
//                                                          |
// Problem statement:                                       |
//                                                          |
// If we list all the natural numbers below 10 that are     |
// multiples of 3 or 5, we get 3, 5, 6 and 9. The sum       |
// of these multiples is 23.                                |
// Find the sum of all the multiples of 3 or 5 below 1000.  |
//-----------------------------------------------------------

// The program is generic and can use other numbers as well.
// Put 3, 5, 1000 as inputs respectively for the above problem
// Mathematical functions are used instead of brute force

#include <iostream>

using namespace std;

// Function to check whether any of the
// number is a multiple of each other
bool is_multiple(int&, int&);

int main()
{
    int x[2], range;
    int sum = 0;

    cout << "Enter the first number: ";
    cin >> x[0];

    cout << "Enter the second number: ";
    cin >> x[1];

    // If any of the number is 0, display error and quit the program
    if (x[0] == 0 || x[1] == 0)
    {
        cerr << "ERROR: Number cannot be zero"<<endl;
        return -1;
    }

    cout << "Enter the range: ";
    cin >> range;

    // The problem statement uses the word "below"
    range-=1;

    // Mathematically compute the sum
    // Use property 1+2+...+n = n(n+1)/2
    // 3+6+...+3n = 3(1+2+...+n)
    if(!is_multiple(x[0],x[1]))
    {
        int y[3];

        // Advantage of using int in this case is the truncation of the decimal part
        // Avoids the use of floor function
        y[0] = range/x[0];
        y[1] = range/x[1];
        y[2] = range/(x[0]*x[1]);

        sum = x[0]*(y[0]*(y[0]+1)/2) + x[1]*(y[1]*(y[1]+1)/2) - x[0]*x[1]*(y[2]*(y[2]+1)/2);
    }
    else
    {
        int y = range/x[0];
        sum = x[0]*(y*(y+1)/2);
    }
    cout<<"The sum of the multiples is: "<<sum;

    return 0;
}

bool is_multiple(int& x,int& y)
{
    if(x % y ==0 || y % x ==0)
    {
        // Passing by reference allows x to be changed
        // to the smaller of the two numbers
        if (x > y)
            x = y;
        return true;
    }
    return false;
}
