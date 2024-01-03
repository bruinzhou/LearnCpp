/*
自定义一个动态数组模板
*/
#include<stdlib.h>
#include<iostream>

enum ErrorType{
    invalidArraySize,memoryAllocationError,indexOutofRange
};
char *errorMsg[]={"Invalid arrat size","Memery allocation error","Invalid index"};

template <typename T>
class Array{
    private:
        T *alist;
        int size;
        void Error(ErrorType error,int badIndex=0) const;
    public:
        Array(int sz=50);
        Array(const Array<T>& A);
        ~Array(void);
        Array<T>& operator=(const Array<T>& rhs);
        T& operator[](int);
        operator T*()const;
        int ListSize() const;
        void Resize(int sz);
};

template <typename T>
void Array<T>::Error(ErrorType error,int badindex) const{
    std::cout<<errorMsg[error];
    if(error==indexOutofRange) std::cout<<badindex;
    std::cout<<std::endl;
    exit(1);
}

template <typename T>
Array<T>::Array(int sz){
    if(sz<=0){
        Error(invalidArraySize);
    }
    else{
        size=sz;
        alist=new T[size];
        if(alist==NULL)
            Error(memoryAllocationError);
    }
}

template <typename T>
Array<T>::Array(const Array<T>& X){
    int n=X.size;
    size=n;
    alist=new T[n];
    if(alist==NULL)
        Error(memoryAllocationError);
    T *srcptr=X.alist;
    T *destptr=alist;
    while(n--)
        *destptr++=*srcptr++;
}

template <typename T>
Array<T>::~Array(){
    delete [] alist;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs){
    int n=rhs.size;
    if(size!=n){
        delete []alist;
        alist=new T[n];
        if(alist==NULL)
            Error(memoryAllocationError);
        size=n;
    }
    
    T* destptr=alist;
    T* srcptr=rhs.alist;
    while(n--)
        *destptr++=*srcptr++;
    return *this;
}

template <typename T>
T &Array<T>::operator[](int n){
    if(n<0||n>size-1)
        Error(indexOutofRange,n);
    return alist[n];
}

template <typename T>
Array<T>::operator T*()const{
    return alist;
}

template <typename T>
int Array<T>::ListSize() const{
    return size;
}

template <typename T>
void Array<T>::Resize(int sz){
    if(sz<=0)
        Error(invalidArraySize);
    if(sz==size) return;
    T *newlist=new T[sz];
    if(newlist==NULL) Error(memoryAllocationError);
    int n=(sz<=size)?sz:size;
    T *srcptr=alist;
    T *destptr=newlist;
    while(n--)
        *destptr++=*srcptr++;
    delete [] alist;
    alist=newlist; size=sz;
}

int main(){
    int i,*p;
    Array<int> a(5);
    for(i=0;i<5;i++) std::cin>>a[i];
    for(i=0;i<5;i++) std::cout<<a[i]<<' ';
    std::cout<<std::endl;
    Array<int>b=a;
    for(i=0;i<5;i++) std::cout<<b[i]<<' ';
    std::cout<<std::endl;
    a.Resize(10);
    for(p=a;p<a+10;p++) std::cout<<*p<<' ';
    return 0;
}