//复制构造函数
//用一个已经生成的对象来初始化另一个同类的对象
// class Point{
//     public:
//       Point():x(0),y(0){}
//       Point(const Point& r):x(r.x),y(r.y){}
//       Point(int a,int b):x(a),y(b){}
//     private:
//       int x,y;
// };
//深复制、浅复制
#include<iostream>
#include<string.h>
class CA{
    public:
      CA(int b,char *cstr){
        a=b;
        str=new char[b];
        strcpy(str,cstr);
      }
      //复制构造函数
      CA(const CA &C){ 
        a=C.a;
        str=new char[a];
        if(str!=0) 
        strcpy(str,C.str);
      }
      void show(){
        std::cout<<str<<std::endl;
      }
      ~CA(){
        delete str;
      }
    private:
      int a; char *str;
};
int main(){
    CA a(10,"hello");
    CA b=a;
    b.show();
    return 0;
}

