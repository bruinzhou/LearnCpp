#include<iostream>
//类模板
template <typename T>
//模板名
class Compare{
    public:
        Compare(T a,T b){x=a;y=b;}
        T max(){return (x>y)?x:y;}
        T min(){return (x<y)?x:y;}
    private:
        T x,y;
};

int main(){
    Compare<int> a(4,7);
    std::cout<<"a:max="<<a.max()<<",min="<<a.min()<<std::endl;
    return 0;
}