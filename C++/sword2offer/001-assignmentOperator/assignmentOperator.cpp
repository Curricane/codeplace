/**
 * 面试题1：赋值运算符函数
 * 题目：如下为类型CMyString的声明，请为该类型添加赋值运算符函数。
*/

#include <cstring>
#include <cstdio>


class CMyString
{
public:
    CMyString();
    CMyString(char* pData);
    CMyString(const CMyString& str);
    ~CMyString(void);

    CMyString& operator = (const CMyString& str);

    void Print();

private:
    char *m_pData;
};

CMyString::CMyString()
{
    
    m_pData = new char[1];
    m_pData[0] = '\0';
    
}

CMyString::CMyString(char *pData)
{
    if (pData == nullptr)
    {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else
    {
        int length = strlen(pData);
        m_pData = new char[length + 1];
        strncpy(m_pData, pData, length + 1);
    } 
}

CMyString::CMyString(const CMyString &str)
{
    int length = strlen(str.m_pData);
    m_pData = new char[length + 1];
    strncpy(m_pData, str.m_pData, length + 1);
}

CMyString::~CMyString()
{
    delete[] m_pData;
}

CMyString& CMyString::operator=(const CMyString& str)
{

    if (this == &str)
        return *this;
    
    //delete first and new
    delete []m_pData;
    m_pData = nullptr;
    int length = strlen(str.m_pData);
    m_pData = new char[length + 1];
    strncpy(m_pData, str.m_pData, length + 1);

    return *this;
}

void CMyString::Print()
{
    printf("%s\n", m_pData);
}

//===================test code============

void Test1()
{
    printf("Test1 begins:\n");

    char* text = "Hello world";

    CMyString str1(text);
    CMyString str2;
    str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");
}


void Test2()
{
    printf("Test2 begins:\n");

    char* text = "Hello world";

    CMyString str1(text);
    str1 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str1.Print();
    printf(".\n");
}


// continuous assignment
void Test3()
{
    printf("Test3 begins:\n");

    char* text = "Hello world";

    CMyString str1(text);
    CMyString str2, str3;
    str3 = str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str3.Print();
    printf(".\n");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}