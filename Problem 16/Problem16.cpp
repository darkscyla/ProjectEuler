// MHS Project Euler Problem 16						|
//													|
// Problem Statement:								|
//													|
// 2^15 = 32768 and the sum of its digits is		|
//													|
//			3 + 2 + 7 + 6 + 8 = 26					|
//													|
// What is the sum of the digits of the number		|
// 2^1000?											|
//													|
//---------------------------------------------------

// Generic Program
// For the above problem, use 1000 as an input

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x, sum = 0;

    cout<<"Enter a power of 2: ";
    cin>>x;

    // The number of digits of any number can be easily found using
    // the logarithmic function. For example, to find the number of
    // digits in 69, use log(69), truncate the decimal part and add
    // one. Similarly, the number of digits in 2^k is
    // 1 + floor( k*log(2) ).

    // An advantage of using int is that it will automatically truncate
    // the decimal part. Therefore, the floor function is omitted. Also,
    // the algorithm below was optimized multiple times. By using an
    // extra digit, all 'if' statements were removed. Therefore, the
    // the variable 'digits' is increased by one.

    int digits = 2 + x*(log(2)/log(10));

    // Initialize all the digits to zero
    int num[digits] = {0};

    // This variable keeps track of the position of the largest non-zero
    // term. For example,
    //
    // Pos:  0 1 2
    // 		[0 0 1]		curr_pos -> 2
    // 		[0 0 2]		curr_pos -> 2
    // 		[0 0 4]		curr_pos -> 2
    // 		[0 0 8]		curr_pos -> 2
    // 		[0 1 6]		curr_pos -> 1
    // 		[0 3 2]		curr_pos -> 1
    // 		[0 6 4]		curr_pos -> 1
    // 		[1 2 8]		curr_pos -> 0
    //
    // By keeping this record, unnecessary multiplication of zero is avoided
    // (which is of course 0 and therefore, redundant). The effect is quite
    // notable when the number is large say ~10000.

    int curr_pos = digits-1;

    num[curr_pos]=1;

    for(int i=0;i<x;i++){

        for(int j=curr_pos;j<digits;j++){

        	// The numbers are doubled from left to right
        	// Carry 1 if 2*current_number is greater than
        	// 9. Or divide the current_number by 5 and see
        	// the quotient. Again, use of 'int' truncates
        	// the decimal part leaving only the quotient.
            num[j-1]=num[j-1]+num[j]/5;

            // Double the number and store the unit place
            num[j]  =(2*num[j])%10;
        }

        // Check if the number left to curr_pos is non-zero.
        // If so, shift the curr_pos to the left
        curr_pos = curr_pos -(bool)(num[curr_pos-1]);
    }

    for(int k=curr_pos;k<digits;k++){
        sum = sum + num[k];
    }
    cout<<"The sum of the digits is: "<<sum<<endl;
    cout<<"The "<<x<<"th power of 2 is: "<<endl<<endl;

    for(int k=curr_pos;k<digits;k++){
        cout<<num[k];
    }
    cout<<endl;

    // The program can be further optimized by grouping
    // the numbers in pairs, say 8, instead of using a
    // single one.

    return 0;
}
