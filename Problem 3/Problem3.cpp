// MHS Project Euler Problem 3                          |
//                                                      |
// Problem Statement:                                   |
//                                                      |
// The prime factors of 13195 are 5, 7, 13 and 29.      |
// What is the largest prime factor of the number       |
//                                                      |
//                  600851475143                        |
//                                                      |
//-------------------------------------------------------

// Generic Program
// Enter 600851475143 as input for the above problem

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Use unsigned long long as int cannot
    // store a number this big
    unsigned long long int k;

    cout <<"Please enter a positive integer greater than zero: ";
    cin >> k;

    // Exception handling for invalid input
    if (k<1)
    {
        cerr<<"Error: Invalid Input"<<endl;
        return -1;
    }

    // The largest prime that can divide a
    // number is less than or equal to its
    // square root (unless the number itself
    // is prime)

    unsigned long int i = sqrt(k);

    unsigned long int maxN = k , numN = 2;

    while (numN <= i){
        if (k % numN == 0){
            maxN = numN;
            k = k/numN;
        }
        else
            numN = numN + 1;
    }
    cout<<"The largest prime factor is: "<<maxN<<endl;
}
