//二进制文件操作
//复制源文件到目的文件
#include<iostream>
#include<fstream>

int main(){
    char src[260],dest[260],buff[16384];
    std::ifstream inf("book.dat",std::ios_base::in|std::ios_base::binary);

    if(!inf.fail()){
        std::ofstream outf("out.dat",std::ios_base::out|std::ios_base::binary);
        while(!inf.eof()){
            inf.read(buff,sizeof(buff));
            outf.write(buff,inf.gcount());
            
            std::cout<<buff<<std::endl;
        }
        outf.close();
        inf.close();
    }
    return 0;
}