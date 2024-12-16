//使用cin和cout显示用户的数字输入与文本输入
#include<iostream>
#include<string>

using namespace std;

int main(){
    int inputNumber;
    
    cout<<"Enter an integer: ";
    
    cin>> inputNumber;

    cout<<"Enter your name: ";
    string inputName;
    cin>>inputName;

    cout<<inputName<<" entered "<<inputNumber<<endl;
    
    return 0;
}