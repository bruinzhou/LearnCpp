/*
抽象：对具体问题进行概括，抽出一类对象的公共性质进行描述
封装：将抽象出的一类对象的数据成员，行为成员相结合
继承与派生：保持原有类特性的基础上，进行更具体的说明
类：是用户自定义的数据类型
*/

class Data{
  void set(int d);
  int get(){
    return data;
  }  
  int data;
};
void Data::set(int d){
    data=d;
}

/*
类定义一般放在程序文件开头，或者放在头文件中被程序文件包含，全局与局部的区别
*/
// class Data{
//     void show();
//     int data;
// };
// void fun(){
//     class Data{
//         void show(){
//             //std::cout<<data;
//         }
//         int data;;
//     }
// }

/*
public private protected
在不考虑继承的情况下，protected(派生类可以访问)与private性质一样
*/

/*
class 类名{
    public:
    protected:
    private:
};
*/
