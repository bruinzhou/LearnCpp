//构造函数重载
#include<iostream>

class Point{
    public:
      Point(){x=y=0;}
      Point(int a,int b):x(a),y(b){}
      void display(){std::cout<<"x="<<x<<",y="<<y<<std::endl;}
    private:
      int x,y;
};

int main(){
    Point m;
    m.display();
    Point n(1,2);
    n.display();
    return 0;
}