//使用函数的返回值
#include<iostream>
using namespace std;
int DemoConsoleOutput(){
    cout<<"This is a simple string literal"<<endl;
    cout<<"Writing number five: "<<5<<endl;
    cout<<"Pi is 22/7= "<<22/7<<endl;

    return 0;
}
int main(){
    //Function call with return used to exit
    return DemoConsoleOutput();
}