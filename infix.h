#ifndef INFIX_EXPRESS_
#define INFIX_EXPRESS_

#include<string>

class infix{
 private:
  
  std::string express;

  int getPrec(char op);
  double operate(double val1, double val2, char op);
bool isDigit(char c);
bool isOp(char c);
 public:
  
  infix() = default;
  ~infix() = default;
  infix(const std::string&);
  
  void setExpress(const std::string&);
  std::string getExpress();

  double eval();
};

#endif
