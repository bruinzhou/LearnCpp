//文件操作
/*
ifstream();文件输入流构造函数
//文件输入流构造函数，用指定的mode方式打开filename文件
ifstream(const char* filename,ios_base::openmode mode=ios_base::in);

ofstream();文件输出流构造函数
文件输出流构造函数，用指定的mode方式打开filename文件
ofstream(const char* filename,ios_base::openmode mode=ios_base::out);

fstream();文件输入输出流构造函数
fstream(const char* filename,ios_base::openmode mode=ios_base::in|ios_base::out);

用指定的mode方式打开filename文件
void open(const char* filename,ios_base::openmode mode=ios_base::in);
bool operator!();检测流对象是否为空
bool is_open();检测文件是否打开

输入：读操作，将文件中的内容读到内存中
输出：写操作，将内存中的数据写到文件中

ios_base::in 以输入方式打开文件
ios_base::out 以输出方式打开文件，若已存在文件，内容全部清空
ios_base::app 以输出方式打开文件，写入数据添加到文件末尾
ios_base::ate 打开已有文件，文件指针指针指向末尾
ios_base::binary 二进制文件，默认为ASCLL文件
ios_base::trunc 打开文件，若文件已存在，内容全部清空，文件不存在，建立新文件。

文件关闭
void close();

文件状态
bool eof();文件是否到末尾
bool bad();读写文件过程中出错
bool fail();不是为了写状态打开的文件进行写入，或者写入的设备没有剩余空间
bool good();

文件基本形式
定义文件流对象
通过构造函数或者成员函数open打开文件
打开文件失败中断文件处理
对文件进行各种操作
文件处理结束时关闭文件

ifstream infile(文件名，openmode);
if(!infile){
    ...
    infile.close();
}

ifstream infile;
infile.open("文件名"，openmode);
if(!infile.fail()){
    ...
    infile.close();
}


文件需要用到的函数
istream& read(char* s,streamsize n);从文件中读n个字节到s
streampos tellg();返回文件指针的位置
istream& seekg(streampos pos);移动文件指针到pos位置
istream& seekg(streamoff off,ios_base::seekdir dir);以dir参照off偏移移动文件指针

ostream& write(const char* s,streamsize n);输出s的n个字节到文件
streampos tellp();返回文件指针的位置
ostream& seekp(streampos pos);移动文件指针到pos位置
ostream& seekp(streamoff oss,ios_base::seekdir dir);以dir参照off偏移移动文件指针
flush();文件输出流刷新
*/