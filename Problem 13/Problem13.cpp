// MHS Project Euler Problem  13					|
//													|
// Problem Statement:								|
//													|
// Work out the first ten digits of the sum			|
// of the following one-hundred 50-digit numbers.	|
//			_____________________________			|
//			_____NUMBERS IN DATA.TXT_____			|
//													|
//---------------------------------------------------

// Generic Program
// For the above problem, use 10 as an input

#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    string temp;
    ifstream dataFile("data.txt");
    ifstream dataNum("data.txt");

    if(dataFile.is_open() && dataNum.is_open()){

        int no_of_lines=0;

        // Calculate the number of lines in data.txt
        while(getline(dataFile,temp)){
            no_of_lines++;
        }

        string num[no_of_lines];
        int i =0;

        // Store the numbers in a string array
        while(getline(dataNum,num[i])){
            i++;
        }

        int x;
        long long int sum=0;

        cout<<"Enter the number of digits: ";
        cin>>x;

        // There is no default data type in C++ that can store
        // numbers having 50 digits. Even if there was, it would
        // be very inefficient to calculate the sum of all numbers
        // when only the first 10 digits are required. Now consider
        // the following sums:-
		//
        // 9 + 9 = 18 		(One digit is carried to tens place)
        // 3 × 9 = 27	 	(Still one digit)
        // 11 × 9 = 99		(Still one digit)
        // 12 × 9 = 108		(Finally 2 digits)
        //
        // Roughly, if the order of numbers (10^) increases by 1,
        // another digit is added to the sum. Therefore, a rough
        // estimate is to calculate the sum of 'x' numbers plus
        // the order of the numbers to the base 10. This estimate
        // ensures that truncation has no effect on the sum of the numbers.
        // (This estimate can be further reduced by a proper analysis)

        int num_to_check = x + ceil(log(no_of_lines)/log(10));

        for (int i=0; i<no_of_lines;i++){
            for(int j=0;j<num_to_check;j++){
                sum = sum + ((num[i][j])-48)*pow(10,num_to_check-j-1);
            }
        }

        // Only display the first 10 digits of the sum, truncate the rest
        cout<<"The sum of the first "<<x<<" digits is "<< (long long int) (sum/pow(10,ceil(log(sum)/log(10))-x));

    }

    else{
        cout<<"File not found"<<endl;
        return 0;
    }

    return 0;
}
