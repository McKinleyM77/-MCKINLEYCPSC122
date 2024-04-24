/*
Name: McKinley Martsolf
Class: CPSC 122 01
Date Submitted: February 11th, 2024
Assignment: Project 3
Description: This project has a keygen, encrypt, decrypt, and a control function that reads a file, encrypts or decrypts, and writes a file.
*/

#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

void keyGen(string keyFile);
char encrypt(char ch, int key);
char decrypt(char ch, int key);
void control(int mode, string keyFile, string input, string output);


int main(int argc, char* argv[])
{
    int mode;
    string keyFile, input, output;
    if (argc != 3 && argc != 5)
    {
        cout << "Incorrect number of command line arguments" << endl;
        exit(1);
    }

    if (argc == 3 || argc == 5)
    {
        mode = atoi(argv[1]);
        keyFile = argv[2];
    }

    if (argc == 5)
    {
        input = argv[3];
        output = argv[4];
    }

    if (mode == 0)
        keyGen(keyFile);
    else if (mode == 1 || mode == 2)
        control(mode, keyFile, input, output);

    return 0;
}

/* 
    Key generation function:
    - Open file
    - Generate and write key
    - Close file
*/
void keyGen(string keyFile)
{
    unsigned seed = time(NULL);
    srand(seed);
    int num = rand() % 26;
    ofstream keyOutput(keyFile);  // Open the key file for writing
    keyOutput << num;             // Write the generated key to the file
    keyOutput.close();            // Close the key file
}

/*
    Control function:
    - Open files
    - Read key
    - Loop over input, encrypting/decrypting, then writing to output
*/
void control(int mode, string keyFile, string input, string output)
{
    ifstream keyInput(keyFile);  // Open the key file for reading

    int key;
    keyInput >> key;  // Read the key from the key file
    keyInput.close();  // Close the key file

    ifstream inFile(input);    // Open the input file for reading
    ofstream outFile(output);  // Open the output file for writing

    char ch;
    // Loop over the input file, encrypting/decrypting, then writing to the output file
    while (inFile.get(ch))
    {
        if (mode == 1)
            outFile << encrypt(ch, key);  // Encrypt and write to the output file
        else if (mode == 2)
            outFile << decrypt(ch, key);  // Decrypt and write to the output file
    }

    // Close the input and output files
    inFile.close();
    outFile.close();
}

// Function to encrypt a character using a given key
char encrypt(char ch, int key)
{
    // Check if the character is an alphabetic character
    if (isalpha(ch))
    {
        // Determine the base value ('A' for uppercase, 'a' for lowercase)
        char base = isupper(ch) ? 'A' : 'a';

        // Calculate the new position after encryption
        int pos = ch - base;
        pos = (pos + key) % 26;

        // Set the encrypted character based on the new position
        ch = pos + base;
    }
    return ch;
}

// Function to decrypt a character using a given key
char decrypt(char ch, int key)
{
    // Check if the character is an alphabetic character
    if (isalpha(ch))
    {
        // Determine the base value ('A' for uppercase, 'a' for lowercase)
        char base = isupper(ch) ? 'A' : 'a';

        // Calculate the new position after decryption
        int pos = ch - base;
        pos = (pos - key + 26) % 26;  // Move back the position by the key value

        // Set the decrypted character based on the new position
        ch = pos + base;
    }
    return ch;
}
