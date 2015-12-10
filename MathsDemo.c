/*
    Program which demonstrates the mathematical concepts of 1st year Computer Science course.
    Compiler: Borland C++ 5.5.1
    
    Made by Ronan Connolly
    connollyro@gmail.com
*/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define ROWS 2
#define COLS 2
#define STRINGSIZE 4


int euclidsAlgorithm(int num1, int num2);
int fermatsLittle(int num1, int prime);
void matrixAddition(int arr1[ROWS][COLS], int arr2[ROWS][COLS]);
void matrixMultiplication(int arr1[ROWS][COLS], int arr2[ROWS][COLS]);
void caesarCipher(char userword[STRINGSIZE], int key);

main()
{
    //menu choice of user
    int user_choice = 0;
    
    //variable for eculidsAlgorithm
    int num1 = 0;
    int num2 = 0;
    int fnum1 = 0;
    int prime = 0;
    int answer = 0;
    
    //Intialise arrays for matrix mulitplactiona and addition
    int arr1[ROWS][COLS];
    int arr2[ROWS][COLS];
    
    //Declare and intiailse string and key for caesarCipher
    char userword[STRINGSIZE];
    int key = 0;
    
    
    //bool is set to false when user selects exit menu number
    bool menu_running = true;
    
    while(menu_running)
    {
        //display menu
        printf("\t\t\t********************************\n");
        printf("\t\t\t*Welcome to CS Mathematics Demo*\n");
        printf("\t\t\t********************************\n");
        printf("\n");
        printf("1. Euclids Algorithm. \n");
        printf("2. Fermats Little Thereom. \n");
        printf("3. Matrix Addition\n");
        printf("4. Matrix Multiplacation\n");
        printf("5. Caesars Cipher\n");
        printf("6. Exit. \n\n");
        
        //get user input
        printf("Enter a choice: \n");
        scanf("%d", &user_choice);
        
        switch(user_choice)
        {
            case 1:
                
                //prompt user for numbers for euclidsAlgorithm
                printf("Enter two ints to calculate GCD using Euclids Algorithm: \n");
                scanf("%d", &num1);
                scanf("%d", &num2);
                
                //call euclidsAlgorithm function and store return value in answer
                answer = euclidsAlgorithm(num1,num2);
                printf("The GCD of %d and %d = %d\n", num1, num2, answer);
                break;
            
            case 2:
                printf("Fermats Theorem Coming Soon!!!\n\n");
                //printf("Enter a number and a prime to use Fermats Theorem\n");
                //scanf("%d", &fnum1);
                //scanf("%d", &prime);
                //answer = fermatsLittle(fnum1, prime);
                //printf("The inverse (%d^%d-2(%d) = 1(mod%d) = %d\n", fnum1,prime, fnum1, prime);
                break;
            case 3:
                //Prompt user to enter values into a 2d array(2X2 Matrix)
                printf("Enter values into two 2D arrays(2X2 Matrix) to add together\n");
                printf("Enter values for array 1:\n");
                
                //fill array 1
                for(int i = 0; i < ROWS; i++)
                {
                    for(int j = 0; j < COLS; j++)
                    {
                    scanf("%d", &arr1[i][j]);
                    }//end inner for
        
                }//End for
                
                printf("Enter values for array 2:\n");
                
                //fill array 2
                for(int i = 0; i < ROWS; i++)
                {
                    for(int j = 0; j < COLS; j++)
                    {
                    scanf("%d", &arr2[i][j]);
                    }//end inner for
        
                }//End for
                
                //call matrixAddition function
                matrixAddition(arr1,arr2);
                break;
            case 4:
                
                //Prompt user to enter values into a 2d array(2X2 Matrix)
                printf("Enter values into two 2D arrays(2X2 Matrix) to multiply\n");
                printf("Enter values for array 1:\n");
                
                //fill array 1
                for(int i = 0; i < ROWS; i++)
                {
                    for(int j = 0; j < COLS; j++)
                    {
                    scanf("%d", &arr1[i][j]);
                    }//end inner for
        
                }//End for
                
                printf("Enter values for array 2:\n");
                
                //fill array 2
                for(int i = 0; i < ROWS; i++)
                {
                    for(int j = 0; j < COLS; j++)
                    {
                    scanf("%d", &arr2[i][j]);
                    }//end inner for
        
                }//End for
                
                //call matrixMultiplication function
                matrixMultiplication(arr1,arr2);
                break;
                
            case 5:
                //Prompt user to enter a string of STRINGSIZE
                printf("Welcome to Caesar's Cipher!\n");
                printf("Please enter a string MAX %d characters long!\n", STRINGSIZE);
                
                //Input into string
                for(int i = 0; i < STRINGSIZE; i++)
                {
                    scanf("%1s", &userword[i]);
                }//End for
                
                //Ask user for key to encrpyt word
                printf("Please enter a key for encryption: \n");
                scanf("%d", &key);
                printf("\n");
                
                //Call caesarCipher function
                caesarCipher(userword, key);
                
                break;
            case 6:
                //Exit program
                printf("Thanks for playing!! Goodbye\n");
                menu_running = false;
                break;
            
            default:
                printf("Error: invalid Input\n");
                break;
            
                
        }//End switch
        
        
        
    }//End while
        
    
    getchar();
    getchar();
    
    
}//End main

int euclidsAlgorithm(int num1, int num2)
{
    int big_num = 0;
    int small_num = 0;
    int num_of_times = 0;
    int small_by_num = 0;
    int remainder = 0;
    int gcd = 0;
    bool running = true;
    
    
    
    //Check which number is bigger
    if(num1 > num2)
    {
        big_num = num1;
        small_num = num2;
    }
    else
    {
        big_num = num2;
        small_num = num1;
    }
    
    printf("------------------------------------------------\n");
    while(running)
    {
    
        //Divide smaller into bigger
        //Store number of times small_num goes into bifg_num. Ignore decimal places, store in num_of_times
        num_of_times = big_num / small_num;
        
        printf("%d = %d(%d) + r\n", big_num, num_of_times, small_num);
        
        
        //Multiply num_of_times by small_num, Store in 
        small_by_num = small_num * num_of_times;
        
    
        //big_num - small_by_num = remainder R
        remainder = big_num - small_by_num;
        
        printf("%d = %d(%d) + %d\n", big_num, num_of_times, small_num, remainder);
        
        big_num = small_num;
        small_num = remainder;
        
        //printf("New big_num = %d, new small_num = %d\n", big_num, small_num);
        
        
        if(remainder == 0)
        {
            running = false;
            gcd = big_num;
        }
        
    }
    printf("------------------------------------------------\n");

    return gcd;
    
}//End euclidsAlgorithm

int fermatsLittle(int num1, int prime)
{
    //(a^p-2)(a) = 1(mod P)
    //FIX THIS??? I DONT UNDERSTAND FERMATS
    //There is two ways, she has given us the above way..
    
    int inverse = 0;
    int new_prime = prime - 2;
    int num_to_power = 0;
    int division_result = 0;
    int mult_result = 0;
    
    num_to_power = pow(num1, new_prime);
    
    printf("num_to_power = %d\n", num_to_power);
    division_result = num_to_power / prime;
    
    printf("division_result = %d\n", division_result);
    
    mult_result = division_result * prime;
    
    printf("mult_result = %d\n", mult_result);
    
    inverse = num_to_power - mult_result;
    
    printf("The inverse is %d\n", inverse);
    
    
    
    
    
    
    
    
    
    return 0;
}


void matrixAddition(int arr1[ROWS][COLS], int arr2[ROWS][COLS])
{
    int answer_array[ROWS][COLS];
    
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            answer_array[i][j] = arr1[i][j] + arr2[i][j];
        }//end inner for
        
    }//End for
    
    printf("\n");
    printf("--------OUTPUT--------\n");
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            printf(" %d\t", answer_array[i][j]);
            
        }//end inner for
        printf("\n");
        
    }//End for
    printf("----------------------\n");
  
    
    
    
}//End matricAddition


void matrixMultiplication(int arr1[ROWS][COLS], int arr2[ROWS][COLS])
{
    int answer_array[ROWS][COLS];
    
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            answer_array[i][j] = 0;
            for(int k = 0; k < ROWS; k++)
            {
                answer_array[i][j] += arr1[i][k] * arr2[k][j];
            }

        }//end inner for
        
    }//End for
    
    printf("\n");
    printf("--------OUTPUT--------\n");
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            printf(" %d\t", answer_array[i][j]);
            
        }//end inner for
        printf("\n");
        
    }//End for
    printf("----------------------\n");
  
    
    
    
    
    
}//End matrixMultiplication


void caesarCipher(char userword[STRINGSIZE], int key)
{
    int upperAscii = 0;
    int lowerAscii = 0;
    
    printf("ENCRYPTED WORD\n");
    printf("-------------------\n");
    
    for(int i = 0; i < STRINGSIZE;i++)
    {
        //we only want to shift letters
        if(isalpha(userword[i]))
        {
            if(isupper(userword[i]))
            {
                upperAscii = ((userword[i] - 65 + key)%26 + 65);
                printf("%c", upperAscii);
            }
            
            if(islower(userword[i]))
            {
                lowerAscii = ((userword[i] - 97 + key) % 26 + 97);
                printf("%c", lowerAscii);
            }
         }//End outer if
         else
         {
            //print other chars as is
            printf("%c", userword[i]);
         
         }//End else
    }//End for
    
    printf("\n-------------------\n");
    
}//End of Caesar