//构造函数初始化列表举例
#include<iostream>
class Cuboid{
    public:
      Cuboid(int l,int h,int d);
      int volumn(){return length*height*depth;};
    private:
      int length,height,depth;
};
//带初始化列表的构造函数
Cuboid::Cuboid(int l,int h,int d): length(l),height(h),depth(d){
    std::cout<<"Cuboid: "<<"L="<<l<<",H="<<h<<",D="<<d<<std::endl;
}
