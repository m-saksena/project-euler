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


// NOTE: THIS WAS SOLVED WITHOUT USING STRING FUNCTIONS!



//------------------LENGTH CHECKING------------------// //working!
int lengthA (long A)
{
    
    int digits = 0;
    
    while (A > 0)
    {
        A = A/10;
        digits++;
    }
    
    return digits;
}



//---------finding the nTH DIGIT of an input number 'A'------------------//

    int nDigit(long A, int n)
    {
        int nDigit = 0;
        int digits = lengthA(A);
        long base = pow(10, digits - n);
        
        nDigit =  (int) A/base % 10 ;
        
        return nDigit;
    };
    
    
    
    //---------------PALINDROME CHECKING-----------------
    //function to check whether a number is a palindrome
    bool isPal(long A)
    {

        int leftDigit = 0;
        int rightDigit = 0;
        
        int digits = lengthA(A);
        for (int n = digits; n >= digits/2 - 1 ; n--)
        {
            leftDigit = nDigit(A, n);
            rightDigit = nDigit(A, digits - n + 1);
            
            if  ( leftDigit !=  rightDigit )
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
                //our factors of A are 'i' and 'A/i'
                if ( lengthA(i) == 3 and lengthA(A/i) == 3)
                {
                    cout << "\nFactor 1: " << i;
                    cout << "\nFactor 2: " << A/i;
                    return 1;
                    //break;
                }
                
            }
            
        }
        
        return 0;
    };
    
    
    
    int main(int argc, const char * argv[])
    
    {
        
        ////---------Checking palindromes, and then checking if they have 2 x 3 digit factors. Start from 999*999 and decrement
        
        
        
        for (long num = 999*999; num > 100*100; num--)
        {
            
            if (isPal(num))
            {
                
                if (factor(num))
                {
                    cout << "\nThe highest palindrome is is : " << num;
                    break;
                }
            }
        }
        
        
    }
