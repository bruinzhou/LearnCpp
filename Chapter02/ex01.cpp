//演示std::cout的功能
#include<iostream>
using namespace std;

//Declare a function
int DemoConsoleOutput();

int main(){
    //Call i.e. incoke the function
    DemoConsoleOutput();
    
    return 0;
}

//Define i.e. implement the previously function
int DemoConsoleOutput(){
    cout<<"This is a simple string literal"<<endl;
    cout<<"Writing number five: "<<5<<endl;
    cout<<"Pi is 22/7= "<<22/7<<endl;

    return 0;
}