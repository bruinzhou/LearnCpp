//字符串流
/*
字符串流是以内存中string对象或字符数组为输入输出的对象，
将数据输出到内存中的字符串存储区域，或者从字符串区域读入数据。

字符串流的作用是利用输入输出操作方式将各种类型的数据转换成字符序列，或者相反。
由于计算机物理或逻辑的设备大多数处理的数据是字符序列，因此字符串流的就是程序
数据与设备进行交换重要的桥梁。

c++字符串流：istringstream、ostringstream、stringstream
字符串流的构造函数和常用成员函数
istringstream(openmode which=ios_base::in); 构造字符串输入流对象

构造字符串输入流对象，并初始化str的内容
istringstream(const string& str,openmode which=ios_base::in);

ostringstream(openmode which=ios_base::out); 构造字符串输出流对象

构造字符串输出流对象，并初始化为str的内容
ostringstream(const string& str,openmode which=ios_base::out);

构造字符串输入输出流对象
stringstream(openmode which=ios_base::out|ios_base::in); 构造字符串输入输出流对象，并初始化为str的内容

stringstream(const string & str,openmode which=ios_base::out|ios_base::in);
string str();返回当前字符串流缓冲区关联对象的副本
void str(cosnt string& s);复制字符串s内容到字符串流缓冲区关联的string对象中

ostringstream 格式化输出，将各种类型转换为string类型，支持<<操作符
ostringstream oss;
oss<<1.234;double类型转换为字符串
oss<<" ";字符串常量转化为字符串
oss<<1234;int转换为字符串
oss<<endl;
cout<<oss.str();输出1.234，1234
oss.str("");每次使用前清空
oss<<3.114159;double型转换为字符串
Str2=oss.str();
cout<<Str2<<endl;输出3.14159

istringstream对象用于把一个已定义的字符串中以空格隔开的内容提取出来，只支持>>操作符
int a;
string str1;
string input="abc 123 def 456 ghi d789";
istringstream iss(input);
while(iss>>str1>>a) cout<<str1<<" "<<a<<endl;

stringstream类是istringstream和ostringstream类的综合，支持<<和>>操作符
int a; string str1;
string input="abc 123 def 456 ghi 789";
stringstream ss;
ss<<input;
while(ss>>str1>>a) cout<<str1<<" "<<a<<endl;
*/