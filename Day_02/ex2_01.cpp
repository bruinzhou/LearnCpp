//对ASCII文件操作
/*
流插入<< 流提取>>运算符输入输出标准类型的数据
用流对象成员函数get getline put进行字符的输入输出
*/

#include<fstream>
#include<iomanip>

int main(){
    char s1[500];int cnt=0;
    std::ifstream inf("a.cpp");
    if(!inf.fail()){
        std::ofstream outf("b.cpp");
        while(!inf.eof()){
            inf.getline(s1,sizeof(s1)-1);
            outf<<std::setfill('0')<<std::setw(4)<<++cnt<<" "<<s1<<std::endl;
        }
        outf.close();
        inf.close();
    }
    return 0;
}