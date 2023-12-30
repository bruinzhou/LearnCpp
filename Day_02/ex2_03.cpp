//随机访问二进制文件

#include<fstream>
#include <iostream>

struct BOOK{
    char c[5];
    char n[11];
    int p;
    int q;
};

int main(){
    BOOK a;
    std::ifstream inf("book.dat");
    std::ios_base::openmode m=std::ios_base::in|std::ios_base::out;
    std::fstream iof("out.dat",m|std::ios_base::trunc|std::ios_base::binary);
    if(inf.fail()||iof.fail()) return -1;
    while(!inf.eof()){
        inf>>a.c>>a.n>>a.p>>a.q;
        iof.write((char*)&a,sizeof(BOOK));
    }
    inf.close();
    iof.seekg(0*sizeof(BOOK),std::ios_base::beg);
    std::cout<<a.c<<a.n<<a.p<<a.q;
    iof.read((char*)&a,sizeof(BOOK));
    return 0;
}