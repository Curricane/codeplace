# 适配器模式
## 定义
**适配器模式(Adapter Pattern)**:将一个接口转换成客户希望的另一个接口，使接口不兼容的那些类可以一起工作，别名**包装器(Wrapper)**。适配器模式既可以作为**类结构型模式**，也可以作为**对象结构型模式**。
## 分类
- 对象适配器模式
> 适配器与适配者之间是关联关系。
![对象适配器模式](https://github.com/Curricane/codeplace/blob/master/DesignPattern/Adapter/%E5%AF%B9%E8%B1%A1%E9%80%82%E9%85%8D%E5%99%A8%E6%A8%A1%E5%BC%8F%E7%BB%93%E6%9E%84%E5%9B%BE.png)
```C++
class Adapter: public Target
{
public:
    Adapter(args):adaptee(args1){}
    void request()
    {
        adaptee.specificRequest();  // 转发调用
    }
private:
    Adaptee adaptee;
}
```
- 类适配器模式
> 适配器与适配者之间是继承（或实现）关系。