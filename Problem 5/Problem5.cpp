// MHS Project Euler Problem 5                          |
//                                                      |
// Problem Statement:                                   |
//                                                      |
// 2520 is the smallest number that can be divided      |
// by each of the numbers from 1 to 10 without any      |
// remainder. What is the smallest positive number      |
// that is evenly divisible by all of the numbers       |
// from 1 to 20?                                        |
//                                                      |
//-------------------------------------------------------

// Generic Program
// Enter 20 as input for the above problem

#include <iostream>
#include <cmath>

using namespace std;
// Function to checks whether the number is prime or not
bool is_prime(int y);

int main()
{
    unsigned int x;
    unsigned long long prod = 1;

    cout << "Enter an integer greater than zero: ";
    cin >> x;

    if (x<1)
    {
        cerr<<"Error: Invalid Number"<<endl;
        return -1;
    }

    for(unsigned int i=2;i<=x;i++){
        if (is_prime(i)){
            // Say, for example, the required range is 10
            // You only need to multiply 8 as it is a multiple
            // of both 4 and 2. Similarly, do that for other
            // primes. The formula calculates the largest multiple
            // of the prime that exist within the required range
            prod = prod * round(pow(i, floor(log(x)/log(i))));
        }
    }
    cout <<"The smallest number divisible by all is: "<<prod;

    return 0;
}

bool is_prime(int y)
{
    if (y ==2 || y ==3)
        return true;

    for(int j=2;j*j<=y;j++){
        if (y%j == 0)
            return false;
    }
    return true;
}
