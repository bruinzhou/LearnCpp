/*
bool empty();
size_type size();
top();
void push(const T& x);
void pop();
*/
#include<iostream>
#include<stack>

int main(){
    std::stack<int> S;
    for(int i=1;i<=6;i++)
    S.push(i);
    while(!S.empty()){
        std::cout<<S.top()<<" ";
        S.pop();
    }
    return 0;
}