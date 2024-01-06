#include<iostream>

class Base{
private:
  int b_number;
public:
  Base(){}
  Base(int i):b_number(i){}
  int get_number(){return b_number;}
  void print(){std::cout<<b_number<<std::endl;}
};
class Derived:public Base{
private:
  int d_number;
public:
  Derived(int i,int j):Base(i),d_number(j){}
  void print(){
    std::cout<<get_number()<<" ";
    std::cout<<d_number<<std::endl;
  }
};
int main(){
    Base a(2);
    Derived b(3,4);
    std::cout<<"a is "; a.print();
    std::cout<<"b is "; b.print();
    std::cout<<"base part of b is ";
    b.Base::print();
    return 0;
}