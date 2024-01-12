#define InitSize 10
#define IncSize 5
#include<iostream>

template <typename T>
class SeqList{
public:
  SeqList(int length=InitSize);
  ~SeqList();

public:
  bool ListInsert(int i,const T& e);
  bool ListDelete(int i);
  bool GetElem(int i,T& e);
  int LocateElem(const T &e);

  void DispList();
  int ListLength();
  void ReverseList();

private:
  void IncreaseSize();
  
private:
  T* m_data;
  int m_length;
  int m_maxsize;
};
//通过构造函数对顺序表进行初始化
template <typename T>
SeqList<T>::SeqList(int length){
  m_data=new T[length];
  m_length=0;
  m_maxsize=length;  
}
//通过析构函数对顺序表进行资源释放
template <typename T>
SeqList<T>::~SeqList(){
    delete[] m_data;
    m_length=0;
}
//在第i个位置插入元素e,时间复杂度O(n),时间开销源于元素的移动
template <typename T>
bool SeqList<T>::ListInsert(int i,const T& e){
  //如果顺序表已经存满了数据，不允许插入新数据
  if(m_length>=m_maxsize){
    std::cout<<"顺序表已满，不能在进行插入操作！"<<std::endl;
    return false;
  }
  //判断插入位置i是否合法，i的位置应该是1到m_length+1
  if(i<1||i>(m_length+1)){
    std::cout<<"元素"<<e<<"插入的位置"<<i<<"不合法,合法的位置是1到"<<m_length+1<<std::endl;
    return false;
  }
  //从最后一个元素向前遍历，直到元素i，并将之后的元素向后移动一位
  for(int j=m_length;j>=i;--j){
    m_data[j]=m_data[j-1];
  }
  m_data[i-1]=e;
  std::cout<<"成功的从位置为"<<i<<"处插入元素"<<m_data[i-1]<<"!"<<std::endl;
  m_length++;
  return true;
}
//删除第i个位置的元素
template <typename T>
bool SeqList<T>::ListDelete(int i){
  if(m_length<1){
    std::cout<<"当前顺序表为空，不能删除任何元素！"<<std::endl;
    return false;
  }
  if(i<1||i>m_length){
    std::cout<<"删除位置"<<i<<"不合法,合法的位置是1到"<<m_length<<"之间！"<<std::endl;
    return false;
  }
  std::cout<<"成功删除的位置为"<<i<<"的元素，该元素的值为"<<m_data[i-1]<<"!"<<std::endl;
  //从数组i+1个位置开始向后遍历元素，分别将这些位置元素向移动
  for(int j=i;j<m_length;++j){
    m_data[j-1]=m_data[i];
  }
  m_length--;
  return true;
}
//按位置获取顺序表中的元素值
template <typename T>
bool SeqList<T>::GetElem(int i,T& e){
  if(m_length<1){
    std::cout<<"当前顺序表为空，不能获取任何数据！"<<std::endl;
    return false;
  }
  if(i<1||i>m_length){
    std::cout<<"获取元素的位置"<<i<<"不合法,合法的位置是1到"<<m_length<<"之间"<<std::endl;
    return false;
  }
  e=m_data[i-1];
  std::cout<<"成功获取位置为"<<i<<"的元素,该元素的位置"<<m_data[i-1]<<"!"<<std::endl;
  return true;
}
//按元素查找顺序表中第一次出现的位置
template <typename T>
int SeqList<T>::LocateElem(const T& e){
  for(int i=0;i<m_length;++i){
    if(m_data[i]==e){
      std::cout<<"值为"<<e<<"的元素在顺序表中第一次出现的位置为"<<i+1<<"!"<<std::endl;
      return i+1;
    }
  }
  std::cout<<"值为"<<e<<"的元素在顺序表中没有找到！"<<std::endl;
  return -1;
}
//输出顺序表中所有的元素
template <typename T>
void SeqList<T>::DispList(){
  for(int i=0;i<m_length;++i){
    std::cout<<m_data[i]<<" ";
  }
  std::cout<<std::endl;//换行
} 
//获取顺序表的长度，时间复杂度为O(1)
template <typename T>
int SeqList<T>::ListLength(){
  return m_length;
}
//翻转顺序表
template <typename T>
void SeqList<T>::ReverseList(){
  if(m_length<=1){
    return;
  }
  T temp;
  
}

int main(){
    SeqList<int> seqobi(10);
    seqobi.ListInsert(1,15);
    seqobi.ListInsert(2,10);
    seqobi.ListInsert(30,8);
    seqobi.ListDelete(1);
    int eval=0;
    seqobi.GetElem(1,eval);
    int findvalue=10;
    seqobi.LocateElem(findvalue);
    return 0;
}