// MHS Project Euler Problem 8                              |
//                                                          |
// Problem Statement:                                       |
//                                                          |
// The four adjacent digits in the 1000-digit number that   |
//  have the greatest product are 9 × 9 × 8 × 9 = 5832.     |
//         ____________________________________             |
//         _______NUMBER BELOW IN STRING_______             |
//                                                          |
// Find the thirteen adjacent digits in the 1000-digit      |
// number that have the greatest product. What is the       |
// value of this product?                                   |
//                                                          |
//-----------------------------------------------------------

// Generic Program
// Use 13 as an input for the above problem

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    // For longer strings, use txt file to store
    string num = "73167176531330624919225119674426574742355349194934"
                 "96983520312774506326239578318016984801869478851843"
                 "85861560789112949495459501737958331952853208805511"
                 "12540698747158523863050715693290963295227443043557"
                 "66896648950445244523161731856403098711121722383113"
                 "62229893423380308135336276614282806444486645238749"
                 "30358907296290491560440772390713810515859307960866"
                 "70172427121883998797908792274921901699720888093776"
                 "65727333001053367881220235421809751254540594752243"
                 "52584907711670556013604839586446706324415722155397"
                 "53697817977846174064955149290862569321978468622482"
                 "83972241375657056057490261407972968652414535100474"
                 "82166370484403199890008895243450658541227588666881"
                 "16427171479924442928230863465674813919123162824586"
                 "17866458359124566529476545682848912883142607690042"
                 "24219022671055626321111109370544217506941658960408"
                 "07198403850962455444362981230987879927244284909188"
                 "84580156166097919133875499200524063689912560717606"
                 "05886116467109405077541002256983155200055935729725"
                 "71636269561882670428252483600823257530420752963450";

        int x;
        long long int prodMax = -1;

        cout << "Enter the length: ";
        cin >> x;

        // I also wanted to know which series generate the maximum
        // product. Therefore, 2 arrays are used. One to store the
        // sequence and the other to retain the series corresponding
        // to the maximum product.
        int a[x], b[x];

        // Converting from ASCII to numeric value
        for(int k=0;k<x;k++){
            a[k] = num[k] - 48;
        }

        for(int i=0; i<(int) (num.length()-x); i++){

            long long int prod = 1;

            for(int j=0;j<x;j++)
                prod = prod * a[j];

            if (prod > prodMax){
                prodMax = prod;

                // See description below first*. Storing and sorting
                // to account for the offset introduced by swapping
                for (int ii=0; ii<x;ii++)
                    b[ii] = a[(ii+i)%x];

            }
            // *Instead of updating all values, only the required
            // digit is swapped. For example, if you have an array
            // [1 2 3 4...] and you are finding product of 3 numbers,
            // at first the array series will be [1 2 3], next it can
            // be [2 3 4] or you can swap 1 with 4 making it [4 2 3].
            // Next swap 2 to get [4 5 3] and so on. Saves a lot of
            // computing power compared to updating whole array
            a[i%x] = num[x+i] - 48;
        }

    cout<<"The largest product is :"<<prodMax<<endl;
    cout<<"The product generating sequence is : ";

    for(int i=0;i<x;i++)
        cout<<b[i]<<" ";

    cout<<endl;

    return 0;
}
