#include "teacher.h"
#include "MyVector.h"

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    
    MyVector<teacher> v1(5);

    teacher t1("陈老师", 25);
    teacher t2(t1);
    teacher t3 = t2;
    
    v1[0] = t1;
    v1[1] = t2;
    v1[2] = t3;

    cout << "v1: " << v1 << endl;

    MyVector<teacher> v2(v1);
    teacher t4("何老师", 18);
    v2[3] = t4;

    cout << "v2: " << v2 << endl;

}

