#include<iostream>
#include<fstream>

void test1()
{
    char txtbuff[1024 * 32];
    std::ofstream output("./test.txt", std::ios::app);
    output << "\n你叫什么名字呢？\n" ;
    output.put('\n');
    char s[] = "这是什么啊";
    for (int i = 0; i < strlen(s); ++i)
    {
        output.put(s[i]);
    }
    output.close();

    std::ifstream input("./test.txt");

    // 测试 input >> txtbuff
    input >> txtbuff; //只获取到一个字符
    std::cout << "txtbuff len: " << strlen(txtbuff) <<  " txtbuff: " << txtbuff << std::endl;

    // 测试input.get(char c);
    input.get(txtbuff[1]);
    std::cout << "txtbuff len: " << strlen(txtbuff) <<  " txtbuff: " << txtbuff << std::endl;

    // 测试input.getline(char* s, int len);
    input.getline(txtbuff+2, 1024); // 不会读取\n进去
    std::cout << "txtbuff len: " << strlen(txtbuff) <<  " txtbuff: " << txtbuff << std::endl;
    input.putback('\n'); //getline 看到是\n说明这行没数据，因此没加数据到txtbuf中
    input.getline(txtbuff+strlen(txtbuff), 1024);
    std::cout << "txtbuff len: " << strlen(txtbuff) <<  " txtbuff: " << txtbuff << std::endl;

    int len = strlen(txtbuff);
    txtbuff[len] = '\n';
    len++;
    input.getline(txtbuff+len, 1024);
    std::cout << "txtbuff len: " << strlen(txtbuff) <<  " txtbuff: " << txtbuff << std::endl;

    input.close();
}


int main()
{
    test1();
}