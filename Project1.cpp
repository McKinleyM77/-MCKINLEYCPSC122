/*
Name: McKinley Martsolf
Class: CPSC 122 01
Date Submitted: January 25, 2023
Assignment: Project 1
Description: Generate a amount of prime numbers that the user wants and in caloums.
*/


#include <iostream>
using namespace std;

void display(int, int);  //function prototype must be declared
                         //before use.  prototype includes
       //return type, function name, parameters type(s)
bool isPrime(int);

int main (int argc, char* argv[])
{

 int num = atoi(argv[1]);
 int col = atoi(argv[2]);

 display(num,col);
 cout << endl;

 return 0;
} 

void display(int nums, int cols)
{
 int ct = 0;
 int num = 2;

 while (ct < nums)
  {
    if (isPrime(num))
    {
      cout << num << '\t';  //tab to next col
      ct++;
      if (ct % cols == 0)  
        cout << endl;
    }
    num++;
  }
}


bool isPrime(int canidate)
{
  int div = 2;
  for (int div = 2; div < canidate; div++) // 
    if (canidate % div == 0) // if canidate is divisible by div, 
      return false;
  return true; // if canidate is not divisible by any div, then it is prime
}
  /*
    int div = 2;
    while (div < canidate){
        if(div % canidate == 0){
          return false;
        }
        div++;
    } 
    return true;
    }
*/
