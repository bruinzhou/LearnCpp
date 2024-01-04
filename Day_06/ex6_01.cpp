/*
review cpp
*/
#include<iostream>

int *f1(int n){
    int *p,i;
    p=new int[n];
    for(i=0;i<n;i++) p[i]=i;
    return p;
}

void f2(int *p,int n){
    while(n-->0) std::cout<<*p++<<" ";
}

void f3(int *p){
    delete [] p;
}
int main(){
    int *pi;
    pi=f1(5);
    f2(pi,5);
    f3(pi);
    return 0;
}
