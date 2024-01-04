#include<iostream>
class Box{
    public:
      int width,length,height;
};
int main(){
    Box *p;
    p=new Box;
    p->width=10;
    p->length=20;
    p->height=30;
    std::cout<<p->width<<"\t"<<p->length<<"\t"<<p->height<<std::endl;
    delete p;
    return 0;
}