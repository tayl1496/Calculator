#ifndef INFIX_EXPRESS_
#define INFIX_EXPRESS_

#include<string>

class infix{
 private:
  
  std::string express("");

  int getPrec(char op);
  double operate(int val1, int val2, char op);
bool isDigit(char c);
bool isOp(char c);
 public:
  
  infix() default;
  ~infix() default;
  
  void SetExpress(const std::string&);
  std::string GetExpress();

  double evaluate();
};

#endif
