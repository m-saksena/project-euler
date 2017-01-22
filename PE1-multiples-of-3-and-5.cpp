//
//  main.cpp
//  1. Multiples of 3 and 5
//
//  Created by Malika Saksena on 16/07/2016.
//  Copyright © 2016 Malika Saksena. All rights reserved.
//


/*
 
 If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 
 Find the sum of all the multiples of 3 or 5 below 1000.
 
 
 */

#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
    
    int sum = 0;
    int max = 1000; //defines the upper bound
    
    
    for(int i = 1; i < max; i++)
    {
        if (i%3 == 0 or i%5 == 0)
        {
            sum = sum + i;
            
            //can also be written as sum += i;
            
        }
        
    
            
    }
    
    cout<<"The sum is: " <<sum <<endl;
    
    
    
    return 0;
}
