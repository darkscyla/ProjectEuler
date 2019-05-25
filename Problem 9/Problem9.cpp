// MHS Project Euler Problem 9							|
//														|
// Problem Statement:									|
//														|
// A Pythagorean triplet is a set of three natural 		|
// numbers, a < b < c, for which,						|
//														|
// 				a^2 + b^2 = c^2							|
//														|
// For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2. 			|
//														|
// There exists exactly one Pythagorean triplet for		|
// which a + b + c = 1000. Find the product abc.		|
//														|
//-------------------------------------------------------

// Generic Program
// Use 1000 as an input for the above problem

#include <iostream>

using namespace std;

int main()
{
    int x;

    cout <<"Enter the triplet sum: ";
    cin >> x;

    // Variables are initialized to opposite
    // extremes to minimize computations

    for(int i=1;i<x;i++){
        for(int j=x-1;j>i;j--){

        	// Due to the decreasing value of j, if
        	// i^2 + j^2 becomes less than c^2, break
        	// the inner loop as further decreasing j
        	// can never yield a sum equal to c^2
            if ((i*i+j*j) < (x-i-j)*(x-i-j)){
                break;
            }
            else if ((i*i+j*j) == (x-i-j)*(x-i-j)){
                cout <<"The two numbers are: "<<i<<" and "<<j<<endl;
                cout <<"The triplet product is: "<<(x-i-j)*i*j;
                return 0;
            }
        }

    }
    cout<<"No solution exists"<<endl;
    return 0;
}
