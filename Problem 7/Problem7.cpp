// MHS Project Euler Problem 7                  |
//                                              |
// Problem Statement:                           |
//                                              |
// By listing the first six prime numbers:      |
// 2, 3, 5, 7, 11, and 13, we can see that      |
// the 6th prime is 13.                         |
//                                              |
// What is the 10 001st prime number?           |
//                                              |
//-----------------------------------------------

// Generic Program
// Use 10001 as input for the above problem

#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int y);

int main()
{
    int x;

    cout<<"Enter the number :";
    cin>>x;

    int num = 1, prm =0;
    for(int i = 2; num<=x;i++){
        if (is_prime(i)){
            num += 1;
            prm = i;
        }
    }
    cout<< "The " <<x<<"th prime number is :"<<prm;

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
