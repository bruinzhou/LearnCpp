/*
队列类成员函数原型

bool empty();测试是否为空队列;
size_type size();
front();
back();
void push(const T& x);
void pop();删除队列下一个元素
*/
#include<iostream>
#include<queue>

int main(){
    std::queue<int> Q;
    for(int i=1;i<=6;i++) Q.push(i);
    Q.front()-=Q.back();
    while(!Q.empty()){
        std::cout<<Q.front()<<" ";
        Q.pop();
    }
    return 0;
}