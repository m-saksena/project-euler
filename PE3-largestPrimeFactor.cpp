//
//  main.cpp
//  3. Largest Prime Factor
//
//  Created by Malika Saksena on 16/07/2016.
//  Copyright © 2016 Malika Saksena. All rights reserved.
//


/*
 
 The prime factors of 13195 are 5, 7, 13 and 29.
 
 What is the largest prime factor of the number 600851475143 ?
 
 
 */


/*
 Here, we use the property that the greatest prime factor of 'n' is less than the square root of 'n'. This is because
 
 */


#include <iostream>
#include <math.h>
#include <ctime> //to later calculate how fast our computation was
using namespace std;

//function to check whether a number 'a' is a factor of a given number
bool isPrime (long a)
{
    
    for (int i = 2; i < a; i++)
    {
        if (a % i == 0)
        {
            return false; //if it finds a number that is a factor, it immediately knows that it's not a prime number so returns false.
        }
    }
    
        return true;
    
}


int main(int argc, const char * argv[])

{
    long num; //the number that we are checking
    long startTime, endTime, seconds; //computation time
    long maxFactor = 0; //the largest factor of a given number
    long two = 2;
    
    cout << " Please enter a number: ";
    cin >> num;
    

    time_t startT = time(0);
    
    //checking if square root of number is odd or even, so we can set the upper bound to be an odd number.
    
    //------------vvvvv-> we might as well start halfway as factors meet halfway.
    for (long i = sqrt(num)+1; i > 1; i--)//the number is odd, and only odd factors are prime
    {
        if (num % i == 0)
        {
            if (isPrime(i))
            {

                maxFactor = i;
                break;
            }
        }
    }
    
    time_t endT = time(0);
    
    seconds = endT - startT;
    
    
    

    
    cout << "The highest prime factor of: " << num << " is: " << maxFactor << endl;
    cout << "This computation took: " << seconds << " seconds. " << endl;
    

    //The answer is:
    
    
    return 0;
}
