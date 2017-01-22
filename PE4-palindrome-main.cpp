//
//  main.cpp
//  4. Largest palindrome product Largest palindrome product 4. Largest Palindrome Product
//
//  Created by Malika Saksena on 29/07/2016.
//  Copyright © 2016 Malika Saksena. All rights reserved.
//



/*
 -----------------------------------PROJECT EULER---------------------------
 PROBLEM 4. LARGEST PALINDROME PRODUCT
 
 A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 
 Find the largest palindrome made from the product of two 3-digit numbers.
 
 */



#include <iostream>
#include "math.h"
using namespace std;


//------------------LENGTH CHECKING------------------// //working!
int lengthA (long A)
{
    //    //Method 1: Dividing by powers of 10 method
    
    
    int maxDigits = 10;
    
    
    int digits = 1; //initializing digits
    
    for (int i = 1 ; i < maxDigits ; i++)
        
    {
        if ( A >=  (  pow( 10, (maxDigits - i) )  )   )
        {
            digits =  digits + (maxDigits - i);
            
            return digits;
            
            //goto stop;
        };
        
        
        
        
        //    /*
        //    //Method 2: Log method//
        //    lenA = floor( log10(A) ) + 1; //floor rounds down
        //    */
        //
        
        
    }
    
    //stop:
    
    
    return digits;
}



//------------------FIRST DIGIT------------------// //working!
int firstDigit(long A)
{
    int fDigit;
    fDigit = A / pow(10, ( lengthA(A) - 1 ) );
    
    
    return fDigit;
    
};


//------------------nTH DIGIT------------------// WORKING!
int nDigit(long A, int n)
{
    int nDigit = 0;
    int digits = lengthA(A);
    
    for (int i = 1; n <= digits; i++)
    {
        nDigit = (int) (A % 10);
        
        if (i == n)
        {
            break;
        }
        
        A = A / 10;
        
    }
    
    
    return nDigit;
};



//---------------PALINDROME CHECKING-----------------
//function to check whether a number is a palindrome
bool isPal(long A)
{
    int digits = lengthA(A);
    
    for (int n = digits; n >= digits/2 - 1 ; n--)
    {
        if  ( nDigit(A, n) !=  nDigit(A, digits - n + 1) )
        {
            
            return false;
        }
        
    }
    
    return true;
    
};

//---------------2 x 3-DIGIT FACTOR CHECKING-----------------
//function to check whether a number has 2 3-digit factors
// if it does, the function returns "true" (1) and then prints out the factors
bool factor(long A)
{
    
    for (long i = sqrt(A) + 1; i > 99; i--)
    {
        if (A % i == 0)
        {
            if ( lengthA(i) == 3 and lengthA(A/i) == 3)
            {
                return 1;
                break;
            }

        }
        
    }
    
    return 0;
};






int main(int argc, const char * argv[])

{
    
    ////-----------------------------------METHOD 3--------------------------------------------
    ////---------Checking palindromes, and then checking if they have 2 x 3 digit factors. Start from 999*999 and decrement
    
    

    for (long num = 999*999; num > 100*100; num--)
    {
        if (isPal(num) == 1)
        {
            if (factor(num) == 1)
            {
                cout << "The highest palindrome is is : " << num;
                break;
            }
            
        
        }
    }
    
    
    
    
    
}











