
#include<iostream>
#include<string>

#include"infix.h"
#include"LinkedStack.h"
#include"DividByZero.h"
infix::infix(const std::string& e){
  express = e;
}

void infix::setExpress(const std::string& c){
  express = c;
}

std::string infix::getExpress(){
  return express;
}

bool infix::isDigit(char c){
  return (c >= '0' && c <= '9');
}

bool infix::isOp(char c){
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')');
}

int infix::getPrec(char op){
  int prec;
  switch(op){
  case '+':
  case '-':
      prec = 1;
    break;
  case '*':
  case '/':
      prec = 2;
    break;
  case '(':
  case ')':
      prec = 3;
    break;
  default:
    prec = -1;
    break;
  }
  return prec;
}

double infix::operate(double val1, double val2, char op){
double val = 0;
  if (op == '+') {
    val = (val1 + val2);
  } else if (op == '-') {
    val = (val1 - val2);
  } else if (op == '*'){
    val = (val1 * val2);
  }else if (op == '/') {
    try{
    if(val2==0){
      std::string message = ("infinite result - Cannot handle division-by-zero.");
	throw DividByZeroExcep(message);
    }
    val = (val1 / val2);
    } catch (const DividByZeroExcep& e){
      throw;
    }
  }
  return val;
}

double infix::eval(){

LinkedStack<double> NumStack;
LinkedStack<char> OpStack;
    
double num = 0;
double prev;

int pos = 0;

char prevop, local;

while (pos < (int)express.length()) {
  local = express[pos];
  if (isDigit(local)) {
    num = (num * 10) + (local - '0');
  }
  else if (isOp(local)) {
    if(local=='('){
      OpStack.push(local);
      num = 0;
    } else if (NumStack.isEmpty()) {
	NumStack.push(num);
	OpStack.push(local);
	num = 0;
    } else if (local==')'){
       NumStack.push(num);
       while (OpStack.peek() != '(') {
	 local = OpStack.peek();
	 OpStack.pop();
	 num = NumStack.peek();
	 NumStack.pop();
	 prev = NumStack.peek();
	 NumStack.pop();
	 num = operate(prev, num, local);
	 NumStack.push(num);
       }
       OpStack.pop();
       NumStack.pop();
    } else {
	prevop = OpStack.peek();
	if (getPrec(local) > getPrec(prev)) {
	  NumStack.push(num);
	  OpStack.push(local);
	  num = 0;
	} else {
	  double prevval = NumStack.peek();
	  prevop = OpStack.peek();
	  NumStack.pop();
	  OpStack.pop();
	  prevval = operate(prevval, num, prevop);
	  NumStack.push(prevval);
	  OpStack.push(local);
	  num = 0;
	}
    }
  }
    pos ++;
 }
  while (!OpStack.isEmpty()) {
    prev = NumStack.peek();
    local = OpStack.peek();
    NumStack.pop();
    OpStack.pop();
    num = operate(prev, num, local);
  }
 
 return num;
}
