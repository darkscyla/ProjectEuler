// MHS Project Euler Problem 10                         |
//                                                      |
// Problem Statement:                                   |
//                                                      |
// The sum of the primes below 10 is                    |
//                                                      |
//          2 + 3 + 5 + 7 = 17.                         |
//                                                      |
// Find the sum of all the primes below two million.    |
//                                                      |
//-------------------------------------------------------

// Generic Program
// Use 2000000 as an input for the above problem


#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int);

int main()
{
    unsigned int x;
    unsigned long long int sum =5;

    cout<<"Enter the range: ";
    cin>>x;

    // Changed limits and optimized the
    // code assuming that the range is
    // greater than 3
    for(unsigned int i=5; i<=x;i+=2)
    {
        if (is_prime(i))
            sum = sum + i;
    }

    cout<<"The sum of primes is: "<<sum;

    return 0;
}

bool is_prime(int y)
{
    for(int j=3;j*j<=y;j+=2){
        if (y%j == 0)
            return false;
    }
    return true;
}
