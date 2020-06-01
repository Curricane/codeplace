#pragma once

#include <stack>

template <typename T>
class StackWithMin
{
public:
    StackWithMin()
    {
        printf("StackWithMin created\n");
    }
    ~StackWithMin()
    {
        printf("bye StackWithMin");
    }
    T& top();
    const T& top() const;

    void push(const T& value);
    void pop();
    const T& min() const;
    bool empty() const;
    size_t size() const;
private:
    std::stack<T> mAStack;
    std::stack<T> mMinStack;
};

template<typename T>
T& StackWithMin<T>::top()
{
    assert(!empty());
    return mAStack.top();
}

template<typename T>
const T& StackWithMin<T>::top() const
{
    assert(!empty());
    return mAStack.top();
}

template<typename T>
void StackWithMin<T>::push(const T& value)
{
    mAStack.push(value);

    // 得考虑到第一次插入辅助栈的情况
    if (mMinStack.size() == 0 || value <= mMinStack.top())
    {
        mMinStack.push(value);
    }
}

template<typename T>
void StackWithMin<T>::pop()
{
    if(empty())
        return;
    T t = mAStack.top();
    mAStack.pop();
    T min = mMinStack.top();
    if (t <= min)
    {
        mMinStack.pop();
    } 
}

template <typename T>
const T& StackWithMin<T>::min() const
{
    assert(!mMinStack.empty());
    return mMinStack.top();
}

template <typename T>
bool StackWithMin<T>::empty() const
{
    return mAStack.empty();
}

template <typename T>
size_t StackWithMin<T>::size() const
{
    return mAStack.size();
}
