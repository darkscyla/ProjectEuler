// MHS Project Euler Problem 15                             |
//                                                          |
// Problem Statement:                                       |
//                                                          |
// Starting in the top left corner of a 2×2 grid, and       |
// only being able to move to the right and down, there     |
// are exactly 6 routes to the bottom right corner.         |
//                                                          |
//	S                                                       |
//	o___o___o                                               |
//	|	|	|                                               |
//	o___o___o	S--->Start                                  |
//	|	|	|	E--->End                                    |
//	o___o___o                                               |
//			E                                               |
//                                                          |
//|----------------------------------------------           |
//|	o > o > o	|	o > o	.	|	o > o	.	|           |
//|			v	|		v		|		v		|           |
//|	.	.	o	|	.	o > o	|	.	o	.	|           |
//|			v	|			v	|		v		|           |
//|	.	.	o	|	.	.	o	|	.	o > o	|           |
//|-------------|---------------|---------------|           |
//|	o	.	.	|	o	.	.	|	o	.	.	|           |
//|	v			|	v			|	v			|           |
//|	o	.	.	|	o > o	.	|	o > o > o	|           |
//|	v			|		v		|			v	|           |
//|	o > . > o	|	.	o > o	|	.	.	o	|           |
//|----------------------------------------------           |
//                                                          |
// How many such routes are there through a 20×20 grid?     |
//                                                          |
//-----------------------------------------------------------

// Generic Program
// Use 20 as an input for the above program

#include <iostream>

using namespace std;

int main()
{
    //An easier way is to use combinatorics. The formula is (2n)! / (n!*n!)

    int x;

    cout<<"Enter the grid size: ";
    cin>>x;

    unsigned long long int grid[x+1][x+1];

    // The problem can be solved by dividing it into smaller sub-problems
    // For example, if the solution for 2×2 grid is required, it can be
    // found if the solution of 1×1 grid is known. (Start and End swapped)
    //
    //  E
    //  .	.		2 < 1
    //				^
    //  .	.		1	0
    //		S
    //
    // All the nodes along the bottom and right edge have only one path
    // that leads to it. All the other nodes have paths that is the sum
    // of nodes to the left and below it.
    //
    //	E
    //	.	.	.		6 < 3 < 1
    //					^	^
    //	.	.	.		3 < 2 < 1
    //					^	^
    //	.	.	.		1	1	0
    //			S
    // (Notice the symmetry)

    
    // Initializing the bottom and right edges to 1
    for(int i=0;i<=x;i++){
        grid[x][i]=1;
        grid[i][x]=1;
    }

    // Finding sums using the method described above
    for(int i=x-1;i>=0;i--){
        grid[i][i] = grid[i][i+1] + grid[i+1][i];

        for(int j=i-1;j>=0;j--){
            grid[i][j] = grid[i][j+1] + grid[i+1][j];

            // By symmetry
            grid[j][i] = grid[i][j];
        }
    }

    cout<<"The unique routes you can take on a "<<x<<"x"<<x<<" grid is: "<<grid[0][0]<<endl;

    return 0;
}
