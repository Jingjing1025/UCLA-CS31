//
//  main.cpp
//  Project 4
//
//  Created by Jingjing on 2017/2/10.
//  Copyright © 2017 Jingjing. All rights reserved.
//

#include <iostream>
using namespace std;
#include <string>
#include <cassert>

int locateMinimum( const string array[ ],int n )
{
    int m = 0;
    
    if (n <= 0)  //"invalid" case
        m = -1;
    
    for (int k =1; k < n; k++)
    {   
                
        if (array [k] < array [m])
        {
            m = k;
        }
       
    }
    return m;
}

int findLastOccurrence( const string array[ ], int n, string target )
{
    int largestIndex = -1;
    
    for (int k = 0; k < n; k++)
    {
        if (array[k] == target)
            largestIndex = k;
    }
    if (largestIndex == -1 || n <=0)
        return -1;
    return largestIndex;
}

int flipAround( string array[ ],int n )
{
    int begin = 0;
    int end = n-1;
    int flipTimes = 0;  //Thus, when n=1,0,or < 0, flip times will have the value 0
    string a;
    
    while (begin < end)
    {
        //carry out the flips
        a = array [begin];
        array [begin] = array [end];
        array [end] = a;
        flipTimes +=1;
        begin ++;
        end--;
    }
    return flipTimes;
}

bool hasNoDuplicates( const string array[ ], int  n )
{
    bool result = true;
    
    if (n < 0)
        result = false;
    
    for (int k = 0; k < n; k++) //use nested loops to determine whether there are duplicates
    {
        for (int m = k+1; m < n-1; m++)
        {
            
            if (array [k] == array [m])  //if there are duplicated element, set result to false
            result = false;
        }
    }
    return result;
}

void unionWithNoDuplicates( const string array1[ ], int n1, const string array2[ ], int n2, string resultingString[ ], int& resultingSize )
{
    if (n1 <= 0 || n2 <= 0)
        resultingSize = -1;
    else
    {
        int a = 1;
        
        resultingString [0] = array1 [0];  //assign the first element of array1 to resultingString
        resultingSize = 1;
        
        //nested loops to check if the elemnt in tha arrays is duplicated with those in resultingString
        for (int k = 1; k < n1; k++)
        {
            bool duplicate1 = false;
            
            for (int m = 0; m < k; m++)
            {
                if (array1 [k] == resultingString [m])
                {
                    duplicate1 = true;
                }
            }
        
            if (duplicate1 == false)  //if there are no duplicates, assign this element to resultingString
            {
                resultingString [a] = array1 [k];
                a++;
                resultingSize = a;
            }

        }
    
    
    for (int p = 0; p < n2; p++)  //similarly for array2
    {
        bool duplicate2 = false;
        
        for (int n = 0; n < p+resultingSize; n++)
        {
            if (array2 [p] == resultingString [n])
            {
                duplicate2 = true;
            }
        }
        if (duplicate2 == false)
        {
            resultingString [resultingSize] = array2 [p];
            resultingSize++;
        }
        
    }
    
    }
}


int shiftRight( string array[ ], int n, int amount, string placeholderToFillEmpties )
{
    int numberRemaining = 0;
    
    if (n < 0||amount < 0 || amount > n)  //the "invalid" cases
    {
        numberRemaining = -1;
        return numberRemaining;
    }
    
    for (int k = n-1; k >= 0; k--)  //shift to right
    {
        array [k] = array [k - amount];
    }
    for (int m = 0; m < amount; m++)  //fill the empty spots
    {
        array [m] = placeholderToFillEmpties;
    }
    numberRemaining = n - amount;
    
    return numberRemaining;
}

bool isInIncreasingOrder( const string array[ ], int  n )
{
    bool result = true;
    
    if (n == 0 || n == 1)  //specail cases
        result = true;
    if (n < 0)
        result = false;
    
    for (int k = 0; k < n-1; k++)   //check for the false conditions
    {
       if (array [k+1] <= array [k])
           result = false;
    }
    return result;
}

//to test the functions
/*
int main ()
{
    string j[7] = { "daenerys", "jon", "jon", "tyrion", "samwell", "argaery", "jon"};
    string b[6] = { "delta", "gamma", "beta", "alpha", "beta", "alpha" };
    
    string output [9] = {"","","","","","","","",""};
    int outputSize = 10;
   
    
    cout << locateMinimum(j, 7) << endl;
    cout << findLastOccurrence(j, 7, "jon") << endl;
    cout << flipAround(j, 7) << endl;
    cout.setf( ios::boolalpha );
    cout << hasNoDuplicates(j, 7) << endl;
    unionWithNoDuplicates(j, 7, b, 6,  output, outputSize);
    for (int i = 0; i < outputSize; i++)
    {
        cout << output [i] << " ";
    } cout << endl;
    cout << outputSize << endl;
    cout << shiftRight(j, -1,-2, "help") << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << j [i] << " ";
    } cout << endl;
 
    cout << isInIncreasingOrder(j, 3) << endl;
    
     int answer;
     
     string a[5] = {"angela", "bella", "chris", "Dalia", "emlia"};
     string h[4] = {"delta", "alaska", "alaska", "delta"};
     
     
     assert(locateMinimum(a, 5 ) == 3);
     assert(locateMinimum(h, 0 ) == -1);
     
     assert(findLastOccurrence(a, 5, "beta" ) == -1);
     assert(findLastOccurrence(h, 4, "delta" ) == 3);
     
     assert(hasNoDuplicates(a, 5) == true);
     assert(hasNoDuplicates(h, 4) == false);
     
     assert(isInIncreasingOrder(a, 3) == true);
     assert(isInIncreasingOrder(a, 5) == false);
     
     unionWithNoDuplicates(a, 5, h, 4, output, outputSize );
     assert( outputSize == 7 );
     assert( output[0] == "angela" );
     assert( output[6] == "alaska" );
     
     answer = shiftRight(h, 2, 1, "foobar" );
     assert( answer == 1 );
     assert( h[0] == "foobar" );
     
     assert(flipAround(a, 3 ) == 1);
     assert(flipAround(b, 4 ) == 2);
     
     cout << "All tests succeeded" << endl;
     return( 0 );
    
   
    }*/
