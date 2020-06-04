# Java基础
## JVM
Java 虚拟机（JVM）是运行 Java 字节码的虚拟机。JVM 有针对不同系统的特定实现（Windows，Linux，macOS），目的是使用相同的字节码，它们都会给出相同的结果。
### 字节码
即扩展名为 `.class`的文件，它不面向任何特定的处理器，只面向虚拟机，**在一定程度上解决了传统解释型语言执行效率低的问题，同时又保留了解释型语言可移植的特点**。
### 源码到执行
- `.java`文件(源代码)—>JDK中的`javac`的**编译**->`.class`文件(JVM可理解的Java字节)->JVM上变成可执行的**二进制机器码**。
- 我们需要格外注意的是 .class->机器码 这一步，这一步 JVM 类加载器首先加载字节码文件，**然后通过解释器逐行解释执行**，这种方式的执行速度会相对比较慢。
- Java 是编译与解释共存的语言。
### JDK与JRE
- JDK 是 Java Development Kit，它是功能齐全的 Java SDK。**运行+开发**
- JRE 是 Java 运行时环境。**运行 不能开发**。
### Oracle JDK 和 OpenJDK 的对比
- Oracle JDK 更稳定，并不完全开源，可以认为是OpenJDK的补丁版，大概6月一更新
- OpenJDK 是一个参考模型并且是完全开源的。
### JAVA和C++的区别
- 都是面向对象的语言，都支持封装、继承和多态
- Java **不提供指针**来直接访问内存，程序内存更加安全
- Java 的类是**单继承**的，C++ 支持多重继承；虽然 Java 的类不可以多继承，但是**接口可以多继承**。
- Java 有**自动内存管理机制**，不需要程序员手动释放无用内存
- 在 C 语言中，字符串或字符数组最后都会有一个额外的字符‘\0’来表示结束。但是，Java 语言中没有结束符这一概念。
### import java 和 javax 有什么区别？
以前javax是java的拓展，但渐渐的javax逐渐扩展为java API的一部分，现在java和javax没有区别，这都是一个名字。
## 基本的语法
### 基础类型及其存储空间大小
![java基本类型](./picture/java基本类型.png)
- **char在java中占2个字节**
### 关键字
- 基本与C++差不多
- abstract 用于抽象类和函数
- extends 用于集成
- final 不可变
- implements 实现（继承）接口
- interface 声明接口
- synchronized 用户类 或 类中函数的同步
- volatile 保证被修饰的变量的修改对其他线程是立即可见的。
- transient 决绝序列化(串行化),该对象的某个变量是transient，那么这个变量不会被串行化进去.
- import 与python和golang的import一样，导入包，类似于c++的include
- package 与golang的package类似，申明当前文件属于哪个包的。
- null 空
- strictfp (不常用)可应用于类、接口或方法。使用 strictfp 关键字声明一个方法时，该方法中所有的float和double表达式都严格遵守FP-strict的限制,符合IEEE-754规范
### 流程控制语句 
- if else while for break continue return 与c++一致
### 泛型
- Java 泛型（generics）提供了**编译时类型安全检测机制**，该机制允许程序员在编译时检测到非法的类型。
- 泛型的本质是**参数化类型**，也就是说所操作的数据类型被指定为一个参数。
- 使用的时候类似乎c++模板参数列表的使用`<>`.
- **泛型的类型参数只能是类类型，不能是简单类型.**
#### 泛型擦除
- Java的泛型是伪泛型，这是因为Java在编译期间，所有的泛型信息都会被擦掉，这也就是通常所说类型擦除
#### 泛型类
```java
public class Generic<T>
{
    private T key;
    public Generic(T key)
    {
        this.key = key
    }
    public T getKey()
    {
        return key;
    }
}
```
使用实例化泛型类：
`Generic<Integer> genericInteger = new Generic<Integer>(123456);`
- **定义的泛型类，就一定要传入泛型类型实参么？**
> 并不是这样，在使用泛型的时候如果传入泛型实参，则会根据传入的泛型实参做相应的限制，此时泛型才会起到本应起到的限制作用。如果不传入泛型类型实参的话，在泛型类中使用泛型的方法或成员变量定义的类型可以为任何的类型。
```java
Generic generic = new Generic("111111");
Generic generic1 = new Generic(4444);
Generic generic2 = new Generic(55.55);
Generic generic3 = new Generic(false);

Log.d("泛型测试","key is " + generic.getKey()); //泛型测试: key is 111111
Log.d("泛型测试","key is " + generic1.getKey()); // 泛型测试: key is 4444
Log.d("泛型测试","key is " + generic2.getKey()); // 泛型测试: key is 4444
Log.d("泛型测试","key is " + generic3.getKey()); // 泛型测试: key is false
```
#### 泛型接口
```java
public interface Generator<T>
{
    public T method();
}
```
**实现泛型接口，不指定类型**：
```java
// 在声明类的时候，需将泛型的声明也一起加到类中, GeneratorImpl<T>的,<T>不可少
class GeneratorImpl<T> implements Generator<T>
{
    @override
    public T method()
    {
        return null;
    }
}
```
**实现泛型接口，指定类型** `class GeneratorImpl<T> implements Generator<String>` 或者 `class GeneratorImpl implements Generator<String>`
#### 泛型方法
```java
public static <E> void printArray( E[] intputArray)
{
    for (E element : intputArray)
        System.out.printf("%s ", element);
}
```
使用
```java
// 创建不同类型数组： Integer, Double 和 Character
Integer[] intArray = { 1, 2, 3 };
String[] stringArray = { "Hello", "World" };
printArray( intArray  ); 
printArray( stringArray  );
```
#### 常用的通配符为： T，E，K，V，？
- ？ 表示不确定的 java 类型
- T (type) 表示具体的一个java类型
- K V (key value) 分别代表java键值中的Key Value
- E (element) 代表Element



