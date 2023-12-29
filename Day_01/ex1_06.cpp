#include<iostream>
#include<sstream>

int main(){
    std::string s1,s2;
    std::ostringstream oss;
    std::istringstream iss;
    char c1='+',c2;
    double val,sum=0.0;
    std::cin>>s2;//1000+200-3-+4+0.4
    iss.str(s2);//复制s2内容到字符串输入流
    while(c1!=' '){
        iss>>val>>c2;//读取一个值和运算符+/-
        if(c1=='+') sum=sum+val;
        else if(c1=='-')sum=sum-val;
        c1=c2,c2=' ';
    }
    oss<<sum; s1=oss.str();//运算结果输出到字符串流中，s1是其副本
    std::cout<<s1<<std::endl;
    return 0;
}