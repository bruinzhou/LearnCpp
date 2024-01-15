#define InitSize 10
#define IncSize 5
#include<iostream>

template <typename T>
class  SeqList{
public:
  SeqList(int length=InitSize);
  ~SeqList();

public:
  bool ListInsert(int i,const T& e);
  bool ListDelete(int i);
  bool GetItem(int i,T& e);
  int LocateElem(const T& e);  
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

template<typename T>
SeqList<T>::SeqList(int length){
  m_data=new T[length];
  m_length=0;
  m_maxsize=length;
}

template <typename T>
SeqList<T>::~SeqList(){
  delete[] m_data;
  m_length=0;
}

template <typename T>
bool SeqList<T>::ListInsert(int i,const T& e){
  
  if(m_length>=m_maxsize){
    std::cout<<"顺序表已满，不能在进行插入操作！"<<std::endl;
    return false;
    IncreaseSize();
  }
  
  if(i<1||i>(m_length+1)){
    std::cout<<"元素"<<e<<"插入的位置"<<i<<"不合法，合法的位置是1到"<<m_length+1<<std::endl;
    return false;
  }
  
  for(int j=m_length;j>=i;--j){
    m_data[j]=m_data[j-1];
  }
  m_data[i-1]=e;
  std::cout<<"成功的从位置为"<<i<<"处插入元素"<<m_data[i-1]<<"!"<<std::endl;
  m_length++;
  return true;
}

template <typename T>
bool SeqList<T>::ListDelete(int i){
  if(m_length<1){
    std::cout<<"当前顺序表为空，不能删除任何元素！"<<std::endl;
    return false;
  }
  if(i<1||i>m_length){
    std::cout<<"删除位置"<<"不合法，合法的位置是1到"<<m_length<<"之间!"<<std::endl;
    return false;
  }
  std::cout<<"成功删除位置为"<<i<<"的元素，该元素的值为"<<m_data[i-1]<<"!"<<std::endl;
  for(int j=i;j<m_length;++j){
    m_data[j-1]=m_data[i];
  }
  m_length--;
  return true;
}

template <typename T>
bool SeqList<T>::GetItem(int i,T& e){
  if(m_length<1){
    std::cout<<"当前顺序表为空，不能获取任何数据！"<<std::endl;
    return false;
  }
  e=m_data[i-1];
  std::cout<<"成功获取位置为"<<i<<"的元素，该元素的位置"<<m_data[i-1]<<std::endl;
  return true;
}

template <typename T>
int SeqList<T>::LocateElem(const T& e){
  for(int i=0;i<m_length;++i){
    if(m_data[i]==e){
        std::cout<<"值为"<<e<<"的元素在顺序表中第一次出现的位置为"<<i+1<<"!"<<std::endl;
        return i+1;
    }
    std::cout<<"值为"<<e<<"的元素在顺序表中没有找到！"<<std::endl;
    return -1;
  }
}

template <typename T>
void SeqList<T>::DispList(){
  for(int i=0;i<m_length;++i){
    std::cout<<m_data[i]<<" ";
  }
  std::cout<<std::endl;
}

template <typename T>
int SeqList<T>::ListLength(){
  return m_length;
}

template <typename T>
void SeqList<T>::ReverseList(){
  if(m_length<=1){
    return;
  }
  T temp;
  for(int i=0;i<m_length/2;++i){
    temp=m_data[i];
    m_data[i]=m_data[m_length-i-1];
    m_data[m_length-i-1]=temp;
  }
}

template <typename T>
void SeqList<T>::IncreaseSize(){
  T* p=m_data;
  m_data=new T[m_maxsize+IncSize];
  for(int i=0;i<m_length;++i){
    m_data[i]=p[i];
  }
  m_maxsize=m_maxsize+IncSize;
  delete[] p;
}

int main(){
  SeqList<int> seqobi(10);
  seqobi.ListInsert(1,15);
  seqobi.ListInsert(2,10);
  seqobi.ListInsert(30,8);
  seqobi.ListDelete(1);
  int eval=0;
  seqobi.GetItem(1,eval);
  int findvalue=10;
  seqobi.LocateElem(findvalue);
  seqobi.ListInsert(2,100);
  seqobi.DispList();
  std::cout<<seqobi.ListLength()<<std::endl;
  seqobi.ReverseList();
  seqobi.DispList();
  return 0;
}