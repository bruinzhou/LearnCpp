/*
C++标准库
C1语言支持 C2:输入输出 C3：诊断功能
C4:通用工具 C5:字符串 C6:容器
C7:迭代器 C8:算法 C9:数值操作
C10:本地化 
*/
//C标准库
/*
<cmath>:提供22个不同的数学函数，如abs(),sqrt(),exp()
<cstdlib>
exit():退出程序，清除静态对象
abort():强制退出程序
atexit():将一个函数作为参数并在程序退出时调用
EXIT_SUCCESS:程序已经正常完成
EXIT_FAULURE:程序正常结束
<cassert>
定义了一个函数assert，用来测试一个条件，并在条件为假时强制程序退出。通常用来判断内存分配是否成功。
<cctype>
提供了确定字符类型的功能。判断一个字符类型是否为数字字符，图形字符，小写，大写，空格，并可将字符进行大小写转换
<cerrno>
定义了变量，确定程序发生错误的类型
*/
//C++类库
/*
<string>:支持字符串类型处理的类库]
<complex>:提供了复数的表示和算法
float_complex
double_complex
long double_complex

<ios>：定义了I/O流类的虚基类ios
<iostream>:标准I/O流类库，提供了cin,cout等全局对象类，支持输入输出
<istream>:输入流类库
<fstream>:读写文件的类
*/
//标准模板库STL
/*
在标准库中，容器、迭代器、算法、数值操作合称为标准模板库
STL:13个头文件，<algorithm> <deque> <functional> <iterator>
<vector> <list> <map> <memory> <numeric> <queue> <set>
<stack> <utility>
提供更好的代码重用

<algorithm>:提供了通用的算术算法和STL的一般算法
sort:以升序排列范围内的元素
swap:交换存储在两个对象中的值
max_element:指出序列中的最大的元素
find:对范围内的元素进行查找
copy:复制序列
replace:将范围内的所有old_value用new_value代替

<numeric>:提供给了4类对序列进行数字处理的算法
accumulate():累加
product:內乘
Partial_sum():部分和
adjacent_difference():邻接差值
*/
