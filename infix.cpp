
#include<sstream>
#include<string>

#include"infix.h"
#include"LinkedStack.h"

void infix::setExpress(std::string c){
  express = c;
}

std::string infix::getExpress(){
  return express;
}

bool isDigit(char c){
  return ('0' <= c <= '9')
}

bool isOp(char c){
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')');
}

int infix::getPrec(char op){
  int prec;
  switch(op){
  case: '+'
  case: '-'
      prec = 1;
    break;
  case: '*'
  case: '/'
      prec = 2;
    break;
  case: '('
  case: ')'
      prec = 3;
    break;
  default:
    prec = -1;
    break;
  }
  return prec;
}

double infix::operate(int val1, int val2, char op){
  double val(0);
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
    }
  }
  return val;
}

double infix::eval(){

    LinkedStack<double> NumStack;
    LinkedStack<char> OpStack;
    
    double num(0);
    double preval, prev;

    int pos(0);

    char prevop, local;

    while (pos < express.length()) {
	local = express[pos];
	if (isDigit(local)){
	    num = (num * 10) + (local - '0');
	  } else if (isOp(local)){
	  if (local == '(') {
		OpStack.push (local);
		num = 0;
	      } else if (NumStack.isEmpty()) {
		NumStack.push(num);
		OpStack.push(local);
		num = 0;
	      } else if (local == ')') {
		NumStack.push(num);
		while (OpStack.peek() != '(') {
		    local = OpStack.pop();
		    num = NumStack.pop();
		    prev = NumStack.pop();
		    num = operate(prev, num, local);
		    NumStack.push(num);
		  }
		OpStack.pop();
		NumStack.pop();
	      } else {
		prev = OpStack.peek();
		if (getPrec(local) > getPrec(prev)) {
		    NumStack.push(num);
		    OpStack.push(local);
		    num = 0;
		  } else {
		    prevval = NumStack.pop();
		    prevop = OpStack.pop();
		    prevval = operate(prevval, num, prevop);
		    NumStack.push(prevval);
		    OpStack.push(local);
		    num = 0;
		  }
	      }
	  }
	pos ++;
      }

    while (!OpStack.isEmpty()){
	prev = NumStack.pop();
	local = OpStack.pop();
	num = operate(prev, num, local);

      }
    return num;
}
