/*
Name: McKinley Martsolf
Class: CPSC 122 01
Date Submitted: Feburary 2, 2023
Assignment: Project 1
Description: Transforms a digit string stored as a c-string to an int.
*/


  #include <iostream>
  #include <fstream>
  using namespace std;

  // declaring the functions
  int mystringlength (char inp[]);
  int ToInt(char num);
  int atoiMy(char str[]);
  int main(int argc, char* argv[])
  {
    // Convert digit strings to intergers
  int num1 = atoiMy(argv[1]);
  int num2 = atoiMy(argv[2]);
  int product = 0;
  // Prints the sum of the two ints
   product = num1 * num2;
  // creates a new file to store the product
    ofstream outputFile(argv[3]);
  // prints product to the file
    outputFile << product << endl;
  // closes the file  
    outputFile.close();
  return 0;
  }

  // Returns the length of the input string
  int atoiMy(char str[])
  {
    int number = 0;
   for(int i =0; str[i] != '\0'; i++)
    { 
    number = number * 10 + ToInt(str[i]);
    }
    return number;
  }
 // Converts a char to an int
  int ToInt(char num)
    {
      return num - '0';
    }
