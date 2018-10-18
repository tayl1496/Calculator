
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
  double val;
  if (op == '+')
    val = (double)(val1 + val2);
  if (op == '-')
    val = (double)(val1 - val2);
  if (op == '*')
    val = (double)(val1 * val2);
  if (op == '/')
    val = (double)(val1 / val2);
  return val;
}

double infix::eval(){
    LinkedStack<int> NumStack;
    LinkedStack<char> OpStack;

    int val = 0;
    int pos = 0;
    int preval, prev;
    char prevop, local;
    while (pos < s.length())
      {
	local = s[pos];
	if (isDigit(local)){
	    val = (val * 10) + (int)(local - '0');
	  } else if (isOp(local)){
	  if (local == '(') {
		OpStack.push (local);
		val = 0;
	      } else if (NumStack.isEmpty()) {
		NumStack.push(val);
		OpStack.push(local);
		val = 0;
	      } else if (local == ')') {
		NumStack.push(val);
		while (OpStack.peek() != '(') {
		    local = OpStack.pop();
		    val = NumStack.pop();
		    prev = NumStack.pop();
		    val = operate(prev, val, local);
		    NumStack.push(val);
		  }
		OpStack.pop();
		NumStack.pop();
	      } else {
		prev = OpStack.peek();
		if (getPrecedence(local) > getPrecedence(prev)) {
		    NumStack.push(val);
		    OpStack.push(local);
		    val = 0;
		  } else {
		    prevval = NumStack.pop();
		    prevop = OpStack.pop();
		    prevval = operate(prevval, val, prevop);
		    NumStack.push(prevval);
		    OpStack.push(local);
		    val = 0;
		  }
	      }
	  }
	local ++;
      }

    while (!OpStack.isEmpty()){
	prev = NumStack.pop();
	local = OpStack.pop();
	val = operate(prev, val, local);

      }
    return val;
}
