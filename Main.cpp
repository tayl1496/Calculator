
#include<iostream>
#include<string>

#include"infix.h"
#include"LinkedStack.h"
#include"DividByZero.h"

int main(){
  std::string s;
  infix Expression;
  while(std::cin>>s){
    try{
    std::getline(std::cin, s);
    Expression.setExpress(s);
    std::cout<<s <<" = "<<Expression.eval();
    } catch (const DividByZeroExcep e) {
      std::cout<<s <<" = ";
      e.what();
    }
    
  }
  return 0;
}
