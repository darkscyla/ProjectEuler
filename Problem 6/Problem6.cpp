// MHS Project Euler Problem 6:                                     |
//                                                                  |
// Problem Statement:                                               |
//                                                                  |
// The sum of the squares of the first ten natural numbers is,      |
//                                                                  |
//                  1^2 + 2^2 + ... + 10^2 = 385                    |
//                                                                  |
// The square of the sum of the first ten natural numbers is,       |
//                                                                  |
//                  (1 + 2 + ... + 10)^2 = 55^2 = 3025              |
//                                                                  |
// Hence the difference between the sum of the squares of the       |
// first ten natural numbers and the square of the sum is           |
// 3025 - 385 = 2640.                                               |
//                                                                  |
// Find the difference between the sum of the squares of the        |
// first one hundred natural numbers and the square of the sum.     |
//                                                                  |
//-------------------------------------------------------------------

// Generic Program
// Use 100 as input for the above program

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // sn--->square of numbers
    // ss--->square of sum
    unsigned int x, sn=0 , ss=0;

    cout <<"Enter a positive integer: ";
    cin >> x;

    if (x<0)
    {
        cerr<<"Error: Invalid Number"<<endl;
        return -1;
    }

    // Pretty straight forward problem
    // Use 1+2...+n = n(n+1)/2
    ss = (x*(x+1)/2)*(x*(x+1)/2);

    for (unsigned int i=1;i<=x;i++){
        sn = sn + i*i;
    }
    cout << "The difference is :"<<ss-sn;
    return 0;
}
