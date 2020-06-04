#include <iostream>
#include <iomanip>

// 1 编程实现以下数据输入/输出：
//     (1)以左对齐方式输出整数,域宽为12。
//     (2)以八进制、十进制、十六进制输入/输出整数。
//     (3)实现浮点数的指数格式和定点格式的输入/输出,并指定精度。
//     (4)把字符串读入字符型数组变量中,从键盘输入,要求输入串的空格也全部读入,以回车符结束。
//     (5)将以上要求用流成员函数和操作符各做一遍。
// 2编写一程序，将两个文件合并成一个文件。
// 3编写一程序，统计一篇英文文章中单词的个数与行数。
// 4编写一程序，将C++源程序每行前加上行号与一个空格。
// 4.5编写一程序，输出 ASCII码值从20到127的ASCII码字符表，格式为每行10个。

//以左对齐方式输出整数,域宽为12。
void printLeftIn12Width(int a)
{
    std::cout << "以左对齐方式输出整数,域宽为12:" ;
    std::cout << std::setw(12) 
              << std::setiosflags(std::ios::left) 
              << std::setfill('*') 
              << a << std::endl;
}

// 以八进制、十进制、十六进制输入/输出整数。
void getAndPrintIn8_10_16()
{
    int octNum;
    int decNum;
    int hexNum;
    std::cout << "以八进制输入一个数:" << std::endl;
    std::cin >> std::oct >> octNum;
    std::cout << "以八进制输出：" << std::oct << octNum;
    std::cout << " 以十进制输出：" << std::dec << octNum;
    std::cout << " 以十六进制输出：" << std::hex << octNum << std::endl;

    std::cout << "以十进制输入一个数:" << std::endl;
    std::cin >> std::dec >> decNum;
    std::cout << "以八进制输出：" << std::oct << decNum;
    std::cout << " 以十进制输出：" << std::dec << decNum;
    std::cout << " 以十六进制输出：" << std::hex << decNum << std::endl;

    std::cout << "以十六进制输入一个数:" << std::endl;
    std::cin >> std::hex >> hexNum;
    std::cout << "以八进制输出：" << std::oct << hexNum;
    std::cout << " 以十进制输出：" << std::dec << hexNum;
    std::cout << " 以十六进制输出：" << std::hex << hexNum << std::endl;
}

// 实现浮点数的指数格式和定点格式的输入/输出,并指定精度。
void getAndPrintFolatIn6Precision()
{
    float f6pNum;
    std::cout << "浮点数的指数格式输入一个数：" << std::endl;
    std::cin.setf(std::ios::scientific);
    std::cin >> std::setprecision(6) >> f6pNum;
    std::cout << f6pNum << std::endl;
}
int main()
{
    // printLeftIn12Width(12);
    // getAndPrintIn8_10_16();
    getAndPrintFolatIn6Precision();
}
