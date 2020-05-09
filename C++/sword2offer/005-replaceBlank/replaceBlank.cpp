/**
 * 面试题5：替换空格
 * 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
 * 则输出“We%20are%20happy.”。
*/

#include <mutex>
#include <cstring>
#include <cstdio>
#include <iostream>

class Replace
{
public:  
    //'static' can only be specified inside the class definition
    static Replace* GetInstance()
    {
        if (nullptr == m_Instace)
        {
            std::unique_lock<std::mutex> lock(m_Mutex);
            if (nullptr == m_Instace)
            {
                m_Instace = new Replace();
            }
        }
        return m_Instace;
    }

    static int Destroy()
    {
        if (m_Instace != nullptr)
        {
            std::unique_lock<std::mutex> lock(m_Mutex);
            if (m_Instace != nullptr)
                delete m_Instace;
                m_Instace = nullptr;
                return 0;
        }
        return 0;
    }

    void ReplaceBlank(char s[], int length)
    {
        if (nullptr == s || length <= 0)
            return;
        
        int origlen = 0;
        int numOfBlanls = 0;
        
        while(s[origlen] != '\0')
        {
            
            if (s[origlen] == ' ')
                ++numOfBlanls;
            ++origlen;
        }
        ++origlen;

        int newlen = origlen + 2 * numOfBlanls;
        if (newlen > length)
            return;

        while (origlen >= 0 && newlen >= 0 && origlen <= newlen)
        {
            if (s[origlen] == ' ')
            {
                s[newlen] = '0';
                s[--newlen] = '2';
                s[--newlen] = '%';
            }
            else 
            {
                s[newlen] = s[origlen];
            }
            --origlen;
            --newlen;
        }

        printf("%s \n", s);
    }

private:  
    Replace();
    ~Replace();
    static std::mutex m_Mutex;
    static Replace* m_Instace;
};

std::mutex Replace::m_Mutex;
Replace *Replace::m_Instace = nullptr;

Replace::Replace()
{
    std::cout << "non argument constructor" << std::endl;
}

Replace::~Replace()
{
    std::cout << "bye bye, see you next time, oh you will never call me -- ~Replace" << std::endl;
}



void Test(char* testName, char str[], int length, char expected[])
{
    if(testName != nullptr)
        printf("begins: %s expected: %s\n", testName, expected);
    
    Replace* r = Replace::GetInstance();
    r->ReplaceBlank(str, length);

    if(expected == nullptr && str == nullptr)
        printf("passed.\n");
    else if(expected == nullptr && str != nullptr)
        printf("failed.\n");
    else if(strcmp(str, expected) == 0)
        printf("passed.\n");
    else
        printf("failed.\n");
}

// blanks in middle of sentence
void Test1()
{
    const int length = 100;
    char str[length] = "hello world";
    Test("Test1", str, length, "hello%20world");
}

// 空格在句子开头
void Test2()
{
    const int length = 100;

    char str[length] = " helloworld";
    Test("Test2", str, length, "%20helloworld");
}

// 空格在句子末尾
void Test3()
{
    const int length = 100;

    char str[length] = "helloworld ";
    Test("Test3", str, length, "helloworld%20");
}

// 连续有两个空格
void Test4()
{
    const int length = 100;

    char str[length] = "hello  world";
    Test("Test4", str, length, "hello%20%20world");
}

// 传入nullptr
void Test5()
{
    Test("Test5", nullptr, 0, nullptr);
}

// 传入内容为空的字符串
void Test6()
{
    const int length = 100;

    char str[length] = "";
    Test("Test6", str, length, "");
}

//传入内容为一个空格的字符串
void Test7()
{
    const int length = 100;

    char str[length] = " ";
    Test("Test7", str, length, "%20");
}

// 传入的字符串没有空格
void Test8()
{
    const int length = 100;

    char str[length] = "helloworld";
    Test("Test8", str, length, "helloworld");
}

// 传入的字符串全是空格
void Test9()
{
    const int length = 100;

    char str[length] = "   ";
    Test("Test9", str, length, "%20%20%20");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();

    return 0;
}