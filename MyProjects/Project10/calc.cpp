#include <iostream>
using namespace std;

#include "calc.h"
#include <cstring>
#include <cctype>

Calc::Calc(char *argvIn) {
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

}

Calc::~Calc() {
  delete stk;
  delete valueTbl;
  delete inFix;
}

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

void Calc::MakeValueTbl() {
  valueTbl = new int[26];
  for (int i = 0; i < 26; i++)
    valueTbl[i] = 0;
}

void Calc::Parse(char* exp) 
{
  int num = 0;
  int inFixCt = 0;
  inFix = new char[strlen(exp)];
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
        cout << "atm " << inFix[i] << " at i " << i << " with val " << exp[i] << endl;
      } 
      else 
      {
        inFix[inFixCt++] = exp[i];
      }
    }
}

bool Calc::CheckParens(char *exp) {
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
