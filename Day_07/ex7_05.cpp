//实现其他类型到类类型的隐式转换
#include<iostream>
class Data{
    public:
      Data(const std::string& str=""):s1(str){}
      void SetString(const Data& r){
        s1=r.s1;
      }
      void print(){std::cout<<s1<<std::endl;}
    private:
      std::string s1;
};

int main(){
    Data a,b,c("world");
    std::string i="string";
    a.SetString(c);
    b.SetString(std::string("world"));
    a.print();
    b.print();
    Data d=Data(i);
    d.print();
    return 0;
}