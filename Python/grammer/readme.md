# Python3语法
一个已入门其他语言的程序员，系统学习python语法的笔记，主要记录下python特别的地方。
## Python基础
### 数据类型和变量
- 整数
	- Python可以处理*任意大小的整数*，当然包括负整数，在程序中的表示方法和数学上的写法一模一样，例如：1，100，-8080，0，等等
- 浮点数
	- 浮点数可以用数学写法，如1.23，3.14，-9.01，等等。但是对于很大或很小的浮点数，就必须用科学计数法表示，把10用e替代，1.23x109就是1.23e9，或者12.3e8，0.000012可以写成1.2e-5，等等
- 字符串
	- 字符串是以单引号'或双引号"括起来的任意文本，类型是`str`
	- Python还允许用r''表示''内部的字符串默认不转义
	- Python3版本中，字符串是以Unicode编码的
	- bytes类型，数据用带b前缀的单引号或双引号表示`x = b'ABC'`.
	- Python提供了ord()函数获取字符的整数表示，chr()函数把编码转换为对应的字符.
	- 内置函数`len()`计算字符串的字符个数，计算bytes类型，是计算字节数
	- 
- 布尔值
	- True False
	- 布尔值可以用and、or和not运算，而不是 && || !
- 空值
	- 空值是Python里一个特殊的值，用None表示。None不能理解为0，因为0是有意义的，而None是一个特殊的空值
- 其他数据类型
	- tuple () 元祖 不可变数组
		- 单元素写法 `(a,)`括号里有`,`号
	- list [] 列表 可变数组
	- dict {} 字典 k:v键值对，k要求是不可变对象，v任意值
	- set set() 无序和无重复元素的集合，两个set可以做数学意义上的交集、并集等操作
		- s1 & s2
		- s1 | s2
- 变量
	- 无需声明数据类型，赋值即可定义变量
### 格式化
- % 
	- `'Age: %s. Gender: %s' % (25, True)`
- format
	- `'Hello, {0}, 成绩提升了 {1:.1f}%'.format('小明', 17.125)`
- f-string
	- 字符串如果包含{xxx}，就会以对应的变量替换
### 条件判断
- if - elif -else
```python3 
if age >= 18:
    print('adult')
elif age >= 6:
    print('teenager')
else:
    print('kid')
```
### 循环
- for  in
	- for name in names:
- while
	- while n > 0:
- break 和 continue与c语言类似
### 代码格式
- 可以看到`: + 代码缩进`开始时代码块类似代码块开始{}
- 判断 循环 不需要`()`
- 严格缩进
### 函数
- 函数定义
	- def funcname(args):
	- 空函数 def nop: pass
- 函数调用
	- funcname(args)
	- 参数不对时，会报TypeError
- 返回值
	- 可以返回多个返回值 return nx, ny
	- 没有return时，默认返回None
- 函数参数
	- 链接：https://www.liaoxuefeng.com/wiki/1016959663602400/1017261630425888
	- 位置参数 power(x)
	- 默认参数 power(x, n = 2)
		- 默认参数，放在位置参数之后
		- 有多个默认参数时，调用的时候，可以按顺序提供默认参数；当不按顺序提供部分默认参数时，需要把参数名写上。比如调用enroll('Adam', 'M', city='Tianjin')
		- 默认参数必须指向不变对象
	- 可变参数
		- 变量名前加*: def calc(*numbers):,在函数内部，number是个tuple
	- 关键字参数 
		- **kwg 
		```python3
		def person(name, age, **kw):
			print('name:', name, 'age:', age, 'other:', kw)
		#使用时
		person('cmc', 18, city='wuhan', home='qnj')
		```
	- 命名关键字参数
		- def person(name, age, *, city, job):
		- 作用：限制关键字参数的名字
		- 如果函数定义中已经有了一个可变参数，后面跟着的命名关键字参数就不再需要一个特殊分隔符*
		```python3
		def person(name, age, *args, city, job):
			print(name, age, args, city, job)
		```
	- 参数组合
		- 在Python中定义函数，可以用必选参数、默认参数、可变参数、关键字参数和命名关键字参数，这5种参数都可以组合使用。但是请注意，`参数定义的顺序必须是：必选参数、默认参数、可变参数、命名关键字参数和关键字参数`。
		```python3
		def f2(a, b, c=0, *, d, **kw):
			print('a =', a, 'b =', b, 'c =', c, 'd =', d, 'kw =', kw)
		```
#### 函数参数传递
	- 对于不可变对象作为函数参数，相当于C系语言的值传递；
	- 对于可变对象作为函数参数，且参数不指向其他对象时，相当于C系语言的引用传递。
	- 对于可变对象作为函数参数，参数指向其他对象，对参数变量的操作不影响原变量的值
	- 可变对象：当有需要改变对象内部的值的时候，这个对象的id不发生变化
	- 不可变对象：当有需要改变对象内部的值的时候，这个对象的id会发生变化。
	- 不可变对象有：数值类型 字符串str 元组tuple
	- 可变对象：列表list、字典dict、集合set
	- list + list操作，会重新生成一个list
	- int 值比较小时，同一数值，id相同（应该是有缓存机制），其他不可变类型，值相同，id不同
### 递归
- Python标准的解释器没有针对尾递归做优化，任何递归函数都存在栈溢出的问题。
### 高级特性
#### 切片
- l[l:r] 左闭右开，l[r]不在截取范围，截取长度为：r - l，l为空则从0开始，r为空则到末尾，r可以为负数，-1表示len-1
- l[:] 截取整个list，相当于复制了一份
- l[l:r:step] step表示步长，如l[::2]意味每第两截取
#### 迭代
- 可迭代对象通过collections模块的Iterable类型判断
```pyhton3
from collections import Iterable
isinstance('abc', Iterable)
# True
- Python内置的enumerate函数可以把一个list变成索引-元素对
```
#### 列表生成式
- 常规 [x * x for x in range(1, 11)]
```python
[1, 4, 9, 16, 25, 36, 49, 64, 81, 100]
```
- 有if [x for x in range(1, 11) if x % 2 == 0]
```python
[2, 4, 6, 8, 10]
```
- 有if else，if else写在for前头[x if x % 2 == 0 else -x for x in range(1, 11)]
```python
[-1, 2, -3, 4, -5, 6, -7, 8, -9, 10]
```
- for 循环嵌套 ->全排列 [x + y for x in 'ab' for y in 'cd']
```python
['ac', 'ad', 'bc', 'bd']
```
#### 生成器
- 列表生成式的[]换成()就是生成器
- 含有yield的函数
- 可以通过next()函数获得generator的下一个返回值，没有更多的元素时，抛出StopIteration的错误
```
>>> def odd():
...   print('step 1')
...   yield 1
...   print('step 2')
...   yield 2
...   print('step 3')
...   yield 3
>>> o = odd()
>>> next(o)
step 1
1
>>> next(o)
step 2
2
>>> next(o)
step 3
3
>>> next(o)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
StopIteration
>>> 
```
#### 迭代器