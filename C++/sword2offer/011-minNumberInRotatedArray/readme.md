# 二分思想
## 二分查找
二分查找针对的是有序的数据集合，每次都通过区间的中间元素对比，将待查找的区间缩小为之前的一半，知道找到要查找的的元素，或者区间被缩小为0.
看一下正常的二分查找的代码:
(```)
int bsearch(int a[], int n, int value)
{
    int low = 0;
    int hight = n-1;

    while( low <= hight)
    {
        int mid = low + ((hight - low) >> 1);
        if (a[mid] == value)
            return mid;
        else if (a[mid] < value)
            low = mid + 1;
        else
        {
            hight = mid - 1;
        } 
    }
    return -1;
}
(```)
## 这道题的变化
这道题是两个有序的部分，但还是可以使用了二分的思想，只是查找的target发生了变化，相应的它的约束条件发生了变化.
(```)
int Min_v1(int* numbers, int length)
{
    if (nullptr == numbers || length <= 0)
    {
        throw -1;
    }
 
    int l = 0;
    int r = length - 1;
    int mid = l;
    
    while( numbers[l] >= numbers[r] )
    {
        if(r - l <= 1)
        {
            mid = r;
            break;
        }
        mid = l + ((r - l) >> 1);
        if (numbers[mid] == numbers[r] && numbers[mid] == numbers[l])
        {
            --r; //dont know minest one in which side,find it one by one from right to lefr
        }
        else if (numbers[mid] <= numbers[r])
        {
            r = mid;
        } 
        else 
        {
            l = mid;
        }
    }

    return numbers[mid];
}
(```)
可以看到循环条件不同，两个边界条件也发生了变化，由`l = mid+1`变成了`l = mid`,这是因为如果+1，可
能会造成错过目标值，因为我们的目标是不确定的，不能在while中通过=号判断的，为了防止无限循环，相应的
需要增加其他的退出条件`numbers[l] >= numbers[r]`以及while中的`if(r - l <= 1)`，不用`l <= r`，是因为他们这样写，他们是不可能会超过对方，而不写`l < r`也是因为存在他们不相等相邻的情况。

# 总结
对于不确定target的二分法，不要用`l = mid + 1; r = mid - 1`的写法，从而错过目标，同时二分法的变体问题需要具体分析，发现问题的规律。