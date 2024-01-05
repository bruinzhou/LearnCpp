//静态成员函数专门访问静态数据成员
//静态成员函数不能被声明为const
//friend
#include<iostream>
// class MyClass {
// private:
//     int privateMember;

// public:
//     MyClass(int value) : privateMember(value) {}

//     // 友元函数声明
//     friend void printPrivateMember(const MyClass& obj);
// };

// // 友元函数定义
// void printPrivateMember(const MyClass& obj) {
//     std::cout << obj.privateMember << std::endl;
// }


class AnotherClass {
public:
    void accessMyClassPrivateMember(const MyClass& obj) {
        std::cout << obj.privateMember << std::endl;
    }
};

class MyClass {
private:
    int privateMember;

    // 友元类声明
    friend class AnotherClass;

public:
    MyClass(int value) : privateMember(value) {}
};
