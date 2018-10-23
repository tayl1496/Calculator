
#include<iostream>
#include<string>

#include"infix.h"
#include"LinkedStack.h"
#include"DividByZero.h"

int main(){
  std::string s;
  infix Expression;
  while( std::getline(std::cin, s) ){
    try{
      Expression.setExpress(s);
    std::cout<<Expression.getExpress() <<" = " <<Expression.eval();
    } catch (const DividByZeroExcep& e) {
      std::cerr<<Expression.getExpress() <<" = " <<e.what();
    }
    std::cout<<std::endl;    
  }
  return 0;
}
