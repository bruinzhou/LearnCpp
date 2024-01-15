#include<iostream>

//单链表
//结点定义
template <typename T>
struct Node{
  T data;
  Node<T>* next;
};
//单链表定义
template <typename T>
class LinkList{
public:
  LinkList();//构造函数
  ~LinkList(){};//析构函数
public:
  bool ListInsert(int i,const T& e);//第i个位置，插入元素e
  bool ListDelte(int i);//删除第i个元素的位置
  bool GetElem(int i,T& e);//获取第i个位置的元素e
  int LocateElem(const T& e);//按元素查找单链表中第一次出现的位置
  void DispList();//输出单链表中的所有元素
  int ListLength();//获取单链表的长度
  bool Empty();//判断单链表是否为空
  void ReverseList();//翻转单链表
private:
  Node<T>* m_head;//指向链表的第一个节点的指针，如果链表有头结点，则指向头结点
  int m_length;
};
//构造函数对链表进行初始化
template <typename T>
LinkList<T>::LinkList(){
  m_head=new Node<T>;//先创建一个头结点
  m_head->next=nullptr;//
  m_length=0;
}
//在第i个位置插入元素e
template <typename T>
bool LinkList<T>::ListInsert(int i,const T& e){
//判断i的值是否合法，i的值是1到length+1之间
  if(i<1||i>(m_length+1)){
    std::cout<<"元素"<<e<<"插入的位置"<<i<<"不合法，合法的位置是1到"<<m_length+1<<std::endl;
    return false;
  }
  Node<T>* p_curr=m_head;
  for(int j=0;j<(i-1);++j){//从0开始代表，从头结点开始
    p_curr=p_curr->next;
  }
  Node<T>* node=new Node<T>;
  node->data=e;
  node->next=p_curr->next;// 新结点链上后续列表，P_curr->next指向后续的链表结点
  p_curr->next=node;
  std::cout<<"成功在位置为"<<i<<"处插入元素"<<e<<"!"<<std::endl;
  m_length++;
  return true;
}
//单链表元素的删除操作
template <typename T>
bool LinkList<T>::ListDelte(int i){
  if(m_length<1){
    std::cout<<"当前单链表为空，不能删除任何数据！"<<std::endl;
    return false;
  }
  if(i<1||i>m_length){
    std::cout<<"删除的位置"<<i<<"不合法，合法的位置是1到"<<m_length<<"之间!"<<std::endl;
    return false;
  }
  Node<T>* p_curr=m_head;
  //从头结点开始，p_curr指向第0个结点(头结点)
  for(int j=0;j<(i-1);++j){
    //p_curr指向待删除结点的前一个位置的结点
    p_curr=p_curr->next;
  }
  //p_willdel指向待删除的结点
  Node<T>* p_willdel=p_curr->next;
  //第i-1个结点的next指针指向i+1个结点
  p_curr->next=p_willdel->next;
  std::cout<<"成功删除位置为"<<i<<"的元素，该元素的值为"<<p_willdel->data<<"!"<<std::endl;
  m_length--;
  delete p_willdel;
  return true;
}
//按位置获取单链表中的元素值
template <typename T>
bool LinkList<T>::GetElem(int i,T& e){
  if(m_length<1){
    std::cout<<"当前单链表为空，不能获取任何数据！"<<std::endl;
    return false;
  }
  if(i<1||i>m_length){
    std::cout<<"获取的元素"<<i<<"不合法,合法的位置是1到"<<m_length<<"之间"<<std::endl;
    return false;
  }
  Node<T>* p_curr=m_head;
  for(int j=0;j<i;++j){
    p_curr=p_curr->next;
  }
  e=p_curr->data;
  std::cout<<"获取的位置为"<<i<<"的元素，该元素的值为"<<e<<"!"<<std::endl;
  return true;
}
//按元素值查找其在单链表中第一次出现的位置
template <typename T>
int LinkList<T>::LocateElem(const T& e){
  Node<T>* p_curr=m_head;
  for(int i=1;i<m_length;++i){
    if(p_curr->next->data==e){
      std::cout<<"值为"<<e<<"的元素在单链表中第一次出现的位置为"<<i<<"!"<<std::endl;
      return i;
    }
    p_curr=p_curr->next;
  }
  std::cout<<"值为"<<e<<"的元素在单链表中没找到！"<<std::endl;
  return -1;
}
//输出单链表
template <typename T>
void LinkList<T>::DispList(){
  Node<T>* p=m_head->next;
  while(p!=nullptr){
    std::cout<<p->data<<" ";
    p=p->next;
  }
  std::cout<<std::endl;
}
//获取单链表长度
template <typename T>
int LinkList<T>::ListLength(){
  return m_length;
}
//判断头结点是否为空
template <typename T>
bool LinkList<T>::Empty(){
  if(m_head->next==nullptr){
    return true;
  }
  return false;
}
//翻转单链表
template <typename T>
void LinkList<T>::ReverseList(){
  if(m_length<1){
    return;
  }
  //指向第二个结点开始的后续结点,指向第三个结点的指针
  Node<T>* pothersjd=m_head->next->next;
  //第一个结点的指针域为空，第一个结点和第二个结点的之间断开
  m_head->next->next=nullptr;
  Node<T>* ptmp;
  while(pothersjd!=nullptr){
    //ptmp代表a2
    ptmp=pothersjd;
    //pothersjd代表a3
    pothersjd=pothersjd->next;
    //a2指向a1
    ptmp->next=m_head->next;
    //头结点指向a2
    m_head->next=ptmp;
  }
}
//通过析构函数对单链表进行资源释放
template <typename T>
LinkList<T>::~LinkList(){
  Node<T>* pnode=m_head->next;
  Node<T>* ptmp;
  //循环释放数据结点
  while(pnode!=nullptr){
    ptmp=pnode;
    pnode=pnode->next;
    delete ptmp; 
  }
  delete m_head;
  m_head=nullptr;
  m_length=0;
}
int main(){
  LinkList<int> slinkobj;
  slinkobj.ListInsert(1,12);
  slinkobj.ListInsert(1,24);
  slinkobj.ListInsert(3,48);
  slinkobj.ListInsert(2,100);
  slinkobj.ListDelte(4);
  int eval=0;
  slinkobj.GetElem(3,eval);
  int findvalue=100;
  slinkobj.LocateElem(findvalue);
  slinkobj.DispList();
  slinkobj.ReverseList();
  slinkobj.DispList();
  return 0;
}