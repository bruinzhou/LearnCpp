//西工大魏英老师C++程序设计代码

#include<iostream>
template <typename T>
class Array{
    private:
        T *arr;
    public:
        Array(int c){arr=new T[c];}
        T& operator[](int i){return arr[i];}
};

int main(){
    int i;
    Array<int> array(5);
    for(i=0;i<5;i++) std::cin>>array[i];
    for(i=0;i<5;i++)
        std::cout<<"array["<<i<<"]:"<<array[i]<<" ";
        std::cout<<std::endl;
        return 0;
}