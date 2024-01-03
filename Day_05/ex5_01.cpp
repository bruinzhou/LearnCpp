/*
向量成员函数原型
迭代器
iterator begin();
iterator end();
reverse_iterator rbegin();
reverse_iterator rend();

容量
size_type size();//返回向量元素数目
size_type max_size();//返回向量能容纳的最大元素数目
void resize(size_type sz,T c=T());重置向量长度sz,c扩充到扩充元素中
size_type capacity(); 返回向量容器存储空间大小
bool empty();测试向量是否为空
void reverse(size_type n);为向量申请容纳n个元素的空间

元素存取
operator[](size_type n);返回向量第n个元素的运算符
at(size_type n);返回向量第n个位置元素
front();返回向量第一个元素
back();返回向量末尾元素

void assign(size_type n,const T& u);向量赋n个u值
void push_back(const T& x);增加一个元素到向量末尾
void pop_back();删除向量末尾元素
void insert(iterator pos,size_type n,const T& x);
iterator erase(iterator pos);删除向量指定位置的元素，pos从1起
void swap(vector<T,Allocator>& vec);与向量vec换
void clear();清空元素
*/