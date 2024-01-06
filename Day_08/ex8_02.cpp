#include<iostream>
class man{
protected:
  int age;
  std::string name;
public:
  man(int n,string n):age(a),name(n){}
  void print(){
    std::cout<<"姓名："<<name<<",年龄："<<age<<std::endl;
  }
  int get_age(){return age;}
  std::string get_name(){return name;}
};
