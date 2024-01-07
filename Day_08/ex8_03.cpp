#include<iostream>

class Point{
    double x,y;
    public:
    Point(double x1,double y1=0):x(x1),y(y1){}
    virtual double area(){return 0;}
    
};
class Circle:public Point{
    double r;
    public:
    Circle(double x,double y,double r1):Point(x,y),r(r1){}
    virtual double area(){return 3.14*r*r;}
};

int main(){
    Point a(2.5,2.5);
    Circle c(2.5,2.5,1);
    Point *pc=&c;
    std::cout<<"Circle area="<<pc->area()<<std::endl;//动态联编
    std::cout<<"Circle area="<<pc->Point::area()<<std::endl;//静态联编
    return 0;
}