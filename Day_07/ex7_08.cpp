//常对象
class Data{
    mutable int data;
};
const Data d1;
Data const d2;//均为常对象
//有时需要修改常对象的数据成员
//mutable int data;
//常数据成员
const int data;//只能通过构造函数初始化

//常成员函数
//int getx() const;
//int Data::getx() const{
//  return x;
//}

//指向对象的常指针
// 类名 *const 指针变量名=对象地址;
//Data *const p=&d;

//指向常对象的指针变量定义
//const 类名*指针变量名
//const Data *p;

//对象的常引用
//const 类名&引用变量名

