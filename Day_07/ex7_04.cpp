#include<iostream>

class Point{
    public:
      Point(int a=0,int b=0):x(a),y(b){}
      void display() {std::cout<<"x="<<x<<",y="<<y<<std::endl;}
    private:
      int x,y;
};

int main(){
    Point k,m(1),n(1,2);
    k.display();
    m.display();
    n.display();
    return 0;
}

//不能在类外指定构造函数的默认参数
//