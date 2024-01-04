/*
class ADT{
    struct Point{int x,int y;};结构体
    union UData{Point p;long color;};共用体
    enum COLORS{Red,Green,BLUE,BLACK,WHITE};枚举类型
    class Nested{ 嵌套类
        Point start;
        Udata end;
        COLORS color;
    };
    typedef Point* LPPOINT;声明类型别名
};

在类的外部定义成员函数
class Data{
    public:
      void set(int d);
      int get(){
        return data;
      }
    private:
      int data;
};
void Data::set(int d){
    data=d;
}
void set(int d){

}
在类的内部声明成员函数，在类的外部定义成员函数，良好的编程习惯


类的声明
class Point;
Class Line{
    Point a;错误;
    Point *pp,&rp;
    Line b;类不能具有自身类型的数据成员
    Line *p1,&r1;
};

对象的动态建立和释放
Point *p; 定义指向Point对象的指针变量
p=new Point;动态分配Point对象
delete p;
*/
