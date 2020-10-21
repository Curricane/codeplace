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
### 递归
- Python标准的解释器没有针对尾递归做优化，任何递归函数都存在栈溢出的问题。
### 高级特性
#### 切片
#### 迭代
#### 列表生成式
#### 生成器
#### 迭代器