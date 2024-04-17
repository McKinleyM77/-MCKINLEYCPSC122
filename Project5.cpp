/*
Team Member 1: McKinley Martsolf
Course: CPSC 122
Date Submitted: 2/22/2024
Assignment Name: Project 5 
Description Program implements the Affine Cipher
*/

#include <iostream>
#include <fstream>
using namespace std;
//Note that variable names in the next three statements freor documentation purposes only
void keyGen(string keyFile);
char encrypt(char ch, int alpha, int beta);
char decrypt(char ch, int alpha, int beta, int MI[]);
void control(int mode, string keyFile, string input, string output);

// Driver program to test the above function
int main(int argc, char* argv[]) 
{
 int mode;
 string keyFile, input, output;
// Check if the correct number of arguments are provided.
 if (argc != 3 && argc != 5) 
 {
    cout << "Incorrect number of command line arguments" << endl;
    exit(1);
 }
// Check if the mode is valid.
 mode = atoi(argv[1]);
 keyFile = argv[2];
 // Check if the mode is valid.
 if (argc != 3 && argc != 5)
  {
   keyGen(keyFile); // Generate the key.
   return 0; 
  }
// Check if the mode is valid.
 if (argc == 5)
  {
   input = argv[3]; // Get the input file name.
   output = argv[4]; // Get the output file name.
   control(mode, keyFile, input, output); 
  }

 return 0;
}

/*
Description: Generates and stores an integer key in the range [1..25]
Input: Name of output file
Output: none. Generated key is stored in the output file 
*/
void keyGen(string keyFile)
{
  unsigned seed = time(NULL);
  srand(seed);
 // Generate a random key.
  int num1List[26] = {1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25};
  int num1 = num1List [rand() % 12];
  int num2 = rand() % 25 + 1;

  ofstream keyOutput(keyFile);  // Open the key file for writing
  keyOutput << num1 << "\n" << num2 << endl;    
  // Write the generated key to the file         
  keyOutput.close();            // Close the key file
}

/*
Description; 
1 Opens keyfile and reads key 
2 Opens plaintext and ciphertext files 
3 Reads each character of the plaintext file 
4 If mode is 1 and the character is alphabetic, transforms it to upper case, encrypts it and writes it
  to the output file 
5 If mode is 2 and the character is alphabetic, decrypts it and writes it to output file
6 If the character is not alphabetic, writes it to the output file
7 Closes all three files
Input: Encrypt/decrypt mode, namkes of key file, input, and output files
Output: Writes encrypted/decrypted text to output file
*/
void control(int mode, string keyFile, string input, string output)
{
 //this is the array of multiplicative indices mod 26
 int MI[26] = {0,1,0,9,0,21,0,15,0,3,0,19,0,0,0,7,0,23,0,11,0,5,0,17,0,25};

  ifstream keyInput(keyFile);  // Open the key file for reading

  if (mode == 0) {
    keyGen(keyFile);
    return;
  }

  int alpha;
  int beta;
  char ch;

  keyInput >> alpha;  // Read the key from the key file
  keyInput >> beta;
  keyInput.close();  // Close the key file

  ifstream inFile(input);    // Open the input file for reading
  ofstream outFile(output);  // Open the output file for writing

  // Loop over the input file, encrypting/decrypting, then writing to the output file
  while (inFile.get(ch))
  {
      if (mode == 1)
          outFile << encrypt(ch, alpha, beta);  // Encrypt and write to the output file
      else if (mode == 2)
          outFile << decrypt(ch, alpha, beta, MI);  // Decrypt and write to the output file
  }

  // Close the input and output files
  inFile.close();
  outFile.close();
}


/*
Description: Encrypts a single character with key according to the rules for affine cipher
             encryption
Input: character to be encrypted with key
Output: returns encrypted character 
*/
char encrypt(char ch, int alpha, int beta)
{
  int pos = ch - 'A';
  pos = (pos * alpha + beta) % 26;
  return char (pos + 'A');
}

/*
Description: Decrypts a single character with key according to the rules for affine cipher
             decryption
Input: character to be decrypted with key
Output: returns decrypted character 
*/
char decrypt(char ch, int alpha, int beta, int MI[])
{
  int pos = ch - 'A';
  pos = ((pos * MI[alpha] - beta * MI[alpha]) + 676) % 26;
  return char (pos + 'A');

}


