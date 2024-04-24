/*
Team Member 1: McKinley Martsolf
Course: CPSC 122
Date Submitted: 2/10/2024
Assignment Name: Project 4 
Description Program reads an unsorted file of strings.  Sorts it. Writes it out 
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// These are the functions that are called throughout the code
void control(string input, string output, int numLines);
int countLines(string input);

// This part of the code allows for multiple inputs on the command line. Also allows for the user to input a file name.
int main(int argc, char* argv[])
{
 if (argc != 3) 
 {
    cout << "Incorrect number of command line arguments" << endl;
    exit(1);
 }

 string input = argv[1];
 string output = argv[2];

 int numLines = countLines(input);
 cout << numLines << endl;
 control(input, output, numLines);

 return 0;
}
// this part of the code counts the lines in the poem and prints it out on the command line.
int countLines(string input)
{
  ifstream fin;
  fin.open(input);
    int ct = 0;
    string line;
  while (fin.peek() != EOF)
    {
      getline(fin, line);
      ct++;
    }
  fin.close();
  return ct;
}

// Overall, this code reads lines from an input file, stores them in an array of strings, sorts them into alphabetical order and then creates a new file in that alphabeticla order for the reader to read from.
void control(string input, string output, int numLines)
{
  string stuff[numLines];
  string line;
  string temp;

  ifstream fin;
  ofstream fout;

  // opens file and reads into array then closes it
  fin.open(input);

  int idx = 0;
  while (fin.peek() != EOF)
    {
      getline(fin, line);
      stuff[idx] = line;
      idx++;
    }
  fin.close();

// organizes the array of strings in alphabetical order.
  for (int count = 0; count < numLines; count++)
    {
      for(int count2 = count + 1; count2 < numLines; count2++)
        {
          if(stuff[count].compare(stuff[count2]) > 0)
          {
            temp = stuff[count];
            stuff[count] = stuff[count2];
            stuff[count2] = temp;
          }
        }
    }
// opens a new file and writes the array to it in the new aplhabetical order.  
fout.open(output);

  for(int count = 0; count < numLines; count++)
    {
      fout << stuff[count] << endl;
    }

fout.close();
}

//code for selection_sort goes here
//code for find_small goes here
//code for swap goes here
