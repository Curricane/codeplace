#pragma once

#include <iostream>
using namespace std;

template <typename T>
class MyVector
{

    // 时代变了，operator<< <T> 在类中申明，类外实现的方式似乎不行了，因此老老实实的写在一起吧
    friend ostream & operator<<  (ostream &out,  const MyVector<T> &obj)
    {
        cout << "MyVector 重载<< " << endl;
        for (int i = 0; i < obj.m_len; ++i)
        {
            out << obj.m_pSpace[i] << ", ";
        }
        return out;
    }
//friend ostream & operator<< <T> (ostream &out,  const MyVector &obj);
public:
	MyVector(int size = 0);  //构造函数
	MyVector(const MyVector &obj); // 拷贝构造函数
	~MyVector(); //析构函数

public:

	T& operator[] (int index);
	// a3 = a2 = a1;
	MyVector &operator=(const MyVector &obj);

	

public:
	int getLen()
	{
		return m_len;
	}

	T *m_pSpace;
	int m_len;
};

template <typename T>
MyVector<T>::MyVector(int size)
{
    cout << "MyVector: 带参构造函数" << endl;
    m_pSpace = new T[size];
    m_len = size;
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T> &obj)
{
    cout << "MyVector: 赋值构造函数" << endl;
    m_pSpace = new T[obj.m_len];
    for (int i = 0; i < obj.m_len; ++i)
    {
        m_pSpace[i] = obj.m_pSpace[i];
    }
    m_len = obj.m_len;
}

template <typename T>
MyVector<T>::~MyVector()
{
    cout << "MyVector: 析构函数" << endl;
    if (m_pSpace != nullptr)
    {
        delete [] m_pSpace;
        m_pSpace = nullptr;
        m_len = 0;
    }
}

template <typename T>
T& MyVector<T>::operator[] (int index)
{
    return m_pSpace[index];
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T> &obj)
{
    cout << "MyVector: 重载=号函数" << endl;
    if (m_pSpace != nullptr)
    {
        delete [] m_pSpace;
        m_pSpace = nullptr;
        m_len = 0;
    }

    m_pSpace = new T[obj.m_len];
    for (int i = 0; i < obj.m_len; ++i)
    {
        m_pSpace[i] = obj.m_pSpace[i];
    }
    m_len = obj.m_len;
    return *this;
}

// template <typename T>
// ostream & operator<< (ostream &out,  const MyVector<T> &obj)
// {
//     cout << "MyVector 重载<< " << endl;
//     for (int i = 0; i < obj.m_len; ++i)
//     {
//         out << obj.m_pSpace[i] << " ";
//     }
//     return out;
// }






