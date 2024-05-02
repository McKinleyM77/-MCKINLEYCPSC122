/*
Name: Charlie LaMotte, Federico Brown and McKinley Martsolf
Class: CPSC 122
Date Submitted: 4/19/2024
Assignment: Project 10
Description: Part 1 of Calculator Assignment
To Compile: make
To Execute: ./calc "(121+12)"
*/

#include <iostream>
using namespace std;

#include "calc.h"
#include <cstring>
#include <cctype>

// Constructor makes the stack and fills it in with the argument form the command line as well as checking parenthesis and tokens
Calc::Calc(char *argvIn)
{
  stk = new Stack;
  if(!CheckTokens(argvIn))
  {
    cout << "Error: Invalid expression" << endl;
  }
  if (!CheckParens(argvIn))
  {
    cout << "Error: Unbalanced parentheses" << endl;
  }
  MakeValueTbl();
  Parse(argvIn);
  InFixToPostFix();
}

// Destructor deletes the stack
Calc::~Calc() 
{
  delete stk;
  delete valueTbl;
  delete inFix;
  delete postFix;
}

// Checks to make sure the stack only has items that will work in the calculator
bool Calc::CheckTokens(char* exp) 
{ 
  int count = 0;
  char allowed[] = " ()*+-0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for (int i = 0; i < strlen(exp); i++){
    for (int j = 0; j < strlen(allowed); j++){
      if(exp[i] == allowed[j]){
        count++;
      }
    }

  }
  if(count == strlen(exp)){
    return true;
  }
  return false; 
}

//Makes array to store ints from the command line
void Calc::MakeValueTbl() {
  valueTbl = new int[26];
  for (int i = 0; i < 26; i++)
    valueTbl[i] = 0;
}

//Takes the argument from the command line and puts it into infix
void Calc::Parse(char* exp) 
{
  int num = 0;
  int inFixCt = 0;
  inFix = new char[strlen(exp) + 1];
  for(int i = 0; i < strlen(exp); i++)
    {
      if(isdigit(exp[i]) == true)
      {
        num = (exp[i] - '0');
        while (isdigit(exp[i+1]) == true)
          {
            num = (num * 10) + (exp[i+1] - '0');
            i++;
          }
        valueTbl[valueIdx] = num;
        valueIdx++;
        inFix[inFixCt++] = 'A' + valueIdx - 1;
      } 
      else 
      {
        inFix[inFixCt++] = exp[i];
      }
    }
}

//Checks to make sure the parens are balanced
bool Calc::CheckParens(char* exp) 
{
  int i = 0;
  while (exp[i] != '\0') {
    if (exp[i] == '(')
      stk->Push(exp[i]);
    if (exp[i] == ')') {
      if (stk->IsEmpty())
        return false;
      stk->Pop();
    }
    i++;
  }
  return (stk->IsEmpty());
}

//Evaluates the equation in postfix
int Calc::Evaluate()
{
  for(int i = 0; i < strlen(postFix); i++) // Changed from strlen(inFix) to strlen(postFix)
    {
      if(isalpha(postFix[i]))
      {
        stk->Push(postFix[i]);
      }
      else
      {
        int result; 
        int op1 = 0;
        int op2 = 0;
        if (isalpha(stk->Peek()))
        {
          op2 = valueTbl[stk->Peek() - 'A'];
          stk->Pop();
        } 
        else
        {
          op2 = stk->Peek();
          stk->Pop();
        }

        if (isalpha(stk->Peek()))
        {
          op1 = valueTbl[stk->Peek() - 'A'];
          stk->Pop();
        }
        else
        {
          op1 = stk->Peek();
          stk->Pop();
        }

        if(postFix[i] == '-')
          result = op1 - op2; 
        if(postFix[i] == '+')
          result = op1 + op2;
        if(postFix[i] == '*')
          result = op1 * op2;
        stk->Push(result);
      }
    }
  return stk->Peek();
}

//Converts infix to postfix
void Calc::InFixToPostFix()
{
  int idx = 0;
  postFix = new char[strlen(inFix) + 1];
  for(int i = 0; i < strlen(inFix); i++)
    {
      if(isalpha(inFix[i]))
        postFix[idx++] = inFix[i];
      if(inFix[i] == '(')
        stk->Push(inFix[i]);
      if(inFix[i] == '+' || inFix[i] == '-' || inFix[i] == '*')
        stk->Push(inFix[i]);
      if(inFix[i] == ')')
        {
          while(stk->Peek() != '(')
          {
            postFix[idx++] = stk->Peek();
            stk->Pop();
          }
          stk->Pop();
        }
    }
}

//prints the equation in infix
void Calc::DisplayInFix() 
{
  int i = 0;
  cout << "Infix: ";
  while (inFix[i] != '\0')
    {
    cout << inFix[i++];
    }
  cout << endl;
}

//Priints the equation in postfix
void Calc::DisplayPostFix()
{
  int i = 0;
  cout << "Postfix: ";
  while (postFix[i] != '\0')
    {
    cout << postFix[i++];
    }
  cout << endl;
}