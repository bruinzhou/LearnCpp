 /*
 静态分配旨在编译过程中的数据对象分配相应的存储空间
 动态分配灵活分配
 new 
 new []
 delete
 delete []
 int *p1,*p2;
 char *pz1,*pz2;
 p1=new int;分配整形空间
 p2=new int(10);分配整型空间，赋初值10
 pz1=new char[80];
 pz2=new char[5][80];
 delete p1;
 delete [] pz1;

 new 运算符是指向分配得到内存空间的指针，如果没有足够的内存空间分配，其运算结果是0指针

 销毁对象后，指针p1变的没有定义，依然存放先前所指向的指针，为迷途指针，通常在运算之后将指针重设为0值
 
 new使用完之后，必须delete
 
 delete只能删除new创建的动态对象
 */