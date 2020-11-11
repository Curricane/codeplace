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
	- 可以返回多个返回值 return nx, ny，返回的其实是个元组
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
- Iterable对象
	- 一类是集合数据类型，如list、tuple、dict、set、str等
	- 一类是generator，包括生成器和带yield的generator function
- Iterator：可以被next()函数调用并不断返回下一个值的对象称为迭代器：Iterator
### 函数式编程
- 纯粹的函数式编程语言编写的函数`没有变量`，因此，任意一个函数，只要输入是确定的，输出就是确定的，这种纯函数我们称之为没有副作用。而允许使用变量的程序设计语言，由于函数内部的变量状态不确定，同样的输入，可能得到不同的输出，因此，这种函数是有副作用的.
- 允许把函数本身作为参数传入另一个函数，还允许返回一个函数
#### 高阶函数
- map 
	- 将传入的函数依次作用到序列的每个元素，并把结果作为新的Iterator返回
```python3
list(map(lambda x: x*x, [x for x in range(11)]))
out[3]:[0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100]
```
- reduce
	- reduce把结果继续和序列的下一个元素做累积计算
```python3
reduce(f, [x1, x2, x3, x4]) = f(f(f(x1, x2), x3), x4)
f 必须能接收两个参数
```
- sorted
	- 接收一个key函数来实现自定义的排序, key指定的函数将作用于list的每一个元素上，并根据key函数返回的结果进行排序
```python3
sorted([36, 5,-12, 9. -12], key=abs)
```
- filter
	- 内建的filter()函数用于过滤序列
	- filter()把传入的函数依次作用于每个元素，然后根据返回值是True还是False决定保留还是丢弃该元素
#### 匿名函数
- 关键字lambda表示匿名函数，冒号前面的表示函数参数
- 匿名函数有个限制，`只能有一个表达式，不用写return，返回值就是该表达式的结果`
```python3
def build(x, y)
	return lambda: x*x + y*y
```
#### 返回函数
- 不立即返回结果，等调用时再执行
```python3
def calc_sum(*args):
	def sum():
		ax = 0
		for n in args:
			ax = ax + n
		return ax
	return sum 
f = calc_sum(1,2,3,4,5) #此时不执行
f() #这一步再执行
```
- 闭包
	- 返回的函数在其定义内部引用了局部变量args，所以，当一个函数返回了一个函数后，其内部的局部变量还被新函数引用,且使用的是该变量的最后状态
```python3
In [35]: def createCounter(): 
    ...:     count = 1 
    ...:     def counter(): 
    ...:         nonlocal count 
    ...:         count += 1 
    ...:         return count 
    ...:     return counter
```
### 装饰器
- 本质上，decorator就是一个返回函数的高阶函数
- 在函数原有的功能上，外包一个函数，执行新增功能，和原函数
```python3
# 定义一个decorator，参数是函数
def log(func):
  def wrapper(*args, **kw): #外包的函数，增加新功能 并返回参数函数func的调用
    print('call %s()' % func.__name__) #新增的功能
	return func(*args, **kw) #真正的执行语句
  return wrapper #返回函数。目的是等到调用时再执行

# 使用该decorator @+decorator名字+ 放到要装饰的函数上
@log
def now():
  print('2020-10-29')
```
- 如果decorator本身需要传入参数，那就需要编写一个返回decorator的高阶函数，写出来会更复杂
```
def log(text):
    def decorator(func):
        def wrapper(*args, **kw):
            print('%s %s():' % (text, func.__name__))
            return func(*args, **kw)
        return wrapper
    return decorator
```
- 在面向对象（OOP）的设计模式中，decorator被称为装饰模式。OOP的装饰模式需要通过继承和组合来实现，而Python除了能支持OOP的decorator外，直接从语法层次支持decorator。Python的decorator可以用函数实现，也可以用类实现。
### 偏函数
- `functools.partial`，把一个函数的某些参数给固定住（也就是设置默认值），返回一个新的函数，调用这个新函数会更简单。
- 创建偏函数时，实际上可以接收函数对象、*args和**kw这3个参数
```
int2 = functools.partial(int, base=2)
实际上固定了int()函数的关键字参数base，也就是
int2('10010')
相当于：
kw = { 'base': 2 }
int('10010', **kw)
当传入：
max2 = functools.partial(max, 10)
实际上会把10作为*args的一部分自动加到左边，也就是：
max2(5, 6, 7)
相当于：
args = (10, 5, 6, 7)
max(*args)
结果为10。
```
### 模块
#### 使用模块
- `import sys`
	- 导入`sys`模块后，我们就有了变量sys指向该模块
- `import numpy as np`
	- 给模块取别名np
- `from xxx import xxx`
- `__author__ = chenmc`，把作者写进去
- `if __name__ == '__main__': test()`
	- Python解释器把一个特殊变量__name__置为__main__，而如果在其他地方导入该hello模块时，if判断将失败，因此，这种if测试可以让一个模块通过命令行运行时执行一些额外的代码，最常见的就是运行测试
- 一个`.py`就是一个模块
#### 作用域
- `__xxx__`前后两个下划线的，是特殊变量，有特殊用途
- 类似`_xxx`和`__xxx`这样的函数或者变量`不应该`被直接引用，是`private`类型
#### 模块搜索路径
- 当我们试图加载一个模块时，Python会在指定的路径下搜索对应的.py文件，如果找不到，就会报错
- 默认情况下，Python解释器会搜索当前目录、所有已安装的内置模块和第三方模块，搜索路径存放在sys模块的path变量`sys.path`
- 添加自己的搜索目录
	> 直接修改sys.path`sys.path.append('path')
	> 设置环境变量`PYTHONPATH`
### 面向对象编程
- 类（Class），抽象的模板
- 实例（Instance），具体的“对象”
- 属性（Property）
- 数据封装、继承、多态是面对对象的三大特征
#### 访问限制
- `__init__`类似构造函数，第一个参数是`self`类似this，创建时则不用加入self参数
- `__`开头的变量是私有变量，只有内部可以访问，不能访问的原因是，解释器会吧`__xx`变量改为`_classname__xxx`
#### 继承和多态
- class Dog(Animal): 继承
#### 获取对象信息
- type() 判断对象类型
- 判断基本数据类型可以直接写int，str等
- 判断一个对象是否是函数 import types
```python
>>> import types
>>> def fn():
...     pass
...
>>> type(fn)==types.FunctionType
True
>>> type(abs)==types.BuiltinFunctionType
True
>>> type(lambda x: x)==types.LambdaType
True
>>> type((x for x in range(10)))==types.GeneratorType
True
```
- `isinstance()`一个对象是否是某种类型(它的子类)
- 使用dir()获得一个对象的所有属性和方法`dir(Student)`
- getattr() setattr() hasattr()
```python
>>> hasattr(obj, 'x') # 有属性'x'吗？
True
>>> obj.x
9
>>> hasattr(obj, 'y') # 有属性'y'吗？
False
>>> setattr(obj, 'y', 19) # 设置一个属性'y'
>>> hasattr(obj, 'y') # 有属性'y'吗？
True
>>> getattr(obj, 'y') # 获取属性'y'
19
>>> obj.y # 获取属性'y'
19
```
- `__len__` 长度
- Python是动态语言，根据类创建的实例可以任意绑定属性
```python
class Student(object):
    def __init__(self, name):
        self.name = name

s = Student('Bob')
s.score = 90 #实例动态增加属性
del s.score #删除实例的name属性
```
#### 使用类的全局属性
- 实例属性属于各个实例所有，互不干扰
- 类属性属于类所有，所有实例共享一个属性
- 不要对实例属性和类属性使用相同的名字，否则将产生难以发现的错误
	- 相同名称的实例属性将屏蔽掉类属性，但是当你删除实例属性后，再使用相同的名称，访问到的将是类属性
```python
class Student(object):
    count = 0

    def __init__(self, name):
        self.name = name
        Student.count += 1 #使用类的全局属性
```
### 面向对象高级编程
- 给class绑定方法
	> 类名.func = func
- 在类中，限制实例的的属性 `__slots__`
```python
class Student(object):
	__slots__ = ('name', 'age') # 用tuple定义允许绑定的属性名称
```
- `@property`内置装饰器，负责把一个方法变成属性调用
```python
class Student(object):
    @property
    def birth(self):
        return self._birth
    @birth.setter
    def birth(self, value):
        self._birth = value
    @property
    def age(self):
        return 2015 - self._birth
```
#### 多重继承
- 通过多重继承，一个子类就可以同时获得多个父类的所有功能。
```python
class Bat(Mammal, Flyable):pass
```
- MixIn 
	- MixIn的目的就是给一个类增加多个功能，这样，在设计类的时候，我们优先考虑通过多重继承来组合多个MixIn的功能，而不是设计多层次的复杂的继承关系
```
在设计类的继承关系时，通常，主线都是单一继承下来的，例如，Ostrich继承自Bird。但是，如果需要“混入”额外的功能，通过多重继承就可以实现，比如，让Ostrich除了继承自Bird外，再同时继承Runnable。这种设计通常称之为MixIn
```
#### 定制类
- `__slots__`
- `__str__` print会调用它 返回用户看到的字符串
	- `__repr__` 返回程序开发者看到的字符串，一般他们一样
```python
class Student(object):
    def __init__(self, name):
        self.name = name
    def __str__(self):
        return 'Student object (name=%s)' % self.name
    __repr__ = __str__
```
- `__iter__` 
	- 如果一个类想被用于for ... in循环，类似list或tuple那样，就必须实现一个__iter__()方法，该方法返回一个迭代对象，然后，Python的for循环就会不断调用该迭代对象的__next__()方法拿到循环的下一个值，直到遇到StopIteration错误时退出循环。

```python
class Fib(object):
    def __init__(self):
        self.a, self.b = 0, 1 # 初始化两个计数器a，b

    def __iter__(self):
        return self # 实例本身就是迭代对象，故返回自己

    def __next__(self):
        self.a, self.b = self.b, self.a + self.b # 计算下一个值
        if self.a > 100000: # 退出循环的条件
            raise StopIteration()
        return self.a # 返回下一个值
```
- `__getitem__` 把它当成list来使用还是不行
```python
class Fib(object):
    def __getitem__(self, n):
        if isinstance(n, int): # n是索引
            a, b = 1, 1
            for x in range(n):
                a, b = b, a + b
            return a
        if isinstance(n, slice): # n是切片
            start = n.start
            stop = n.stop
            if start is None:
                start = 0
            a, b = 1, 1
            L = []
            for x in range(stop):
                if x >= start:
                    L.append(a)
                a, b = b, a + b
            return L
```
- `__getattr__` 当调用不存在的属性时，动态返回一个属性，默认返回None，如果要只响应几个属性，可以抛出`AttributeError`的错误
```python
class Student(object):
	def __getattr__(self, attr):
		if attr == 'age':
			return lambda: 25
		raise AttributeError('\'Student\' object has no attribute \'%s\'' % attr)
```
> 利用完全动态的__getattr__，我们可以写出一个链式调用
```python
class Chain(object):
	def __init__(self, path=''):
		self._path = path
	def __getattr__(self, path):
		return Chain('%s/%s' % (self._path, path))
	def __str__(self):
		return self._path
	__repr__ = __str__
```
- `__call__` 直接对实例进行调用
```python
class Student(object):
	def __init__(self, name):
		self.name = name
	def __call__(self):
		print('My name is %s.' % self.name)
s = Student('cmc')
s() # My name is cmc
```
#### 使用枚举类
- 方式一 `from enum import Enum` instance = Enum(Name, (names,))
	- value属性则是自动赋给成员的int常量，默认从1开始计数
```python
from enum import Enum
l = Enum('L', ('l1', 'l2', 'l3', 'l4'))
for name, member in l.__members__.items():
	print(name, '=>', member, ',', member.value)
l1 => L.l1 , 1
l2 => L.l2 , 2
l3 => L.l3 , 3
l4 => L.l4 , 4
```
- 方式二 从Enum派生出自定义类
```python
@unique #@unique装饰器可以帮助我们检查保证没有重复值
class Weekday(Enum):
	# 写在所有函数外头
    Sun = 0 # Sun的value被设定为0
    Mon = 1
    Tue = 2
    Wed = 3
    Thu = 4
    Fri = 5
    Sat = 6

>>> day1 = Weekday.Mon
>>> print(day1)
Weekday.Mon
>>> print(Weekday.Tue)
Weekday.Tue
>>> print(Weekday['Tue'])
Weekday.Tue
>>> print(Weekday.Tue.value)
2
>>> print(day1 == Weekday.Mon)
True

```
#### 使用元类
- type()函数不仅可以查看类型，还可以创建类
	- class的定义是运行时动态创建的，而创建class的方法就是使用type()函数
	```python
	def fn(self, name='world'):
		print('Hello, %s.' % name)
	Hello = type('Hello', (object,), dict(hello=fn)) #创建Hello class
	```
	- type()函数依次传入3个参数：
		> class的名称
		> 继承的父类集合，注意Python支持多重继承，如果只有一个父类，别忘了tuple的单元素写法
		> class的方法名称与函数绑定，这里我们把函数fn绑定到方法名hello上
- metaclass
	- 待学习
### 错误、调试和测试
#### 异常
- 与java异常使用类似
```python
try:
    print('try...')
    r = 10 / int('a')
    print('result:', r)
except ValueError as e:
    print('ValueError:', e)
except ZeroDivisionError as e:
    print('ZeroDivisionError:', e)
finally:
    print('finally...')
print('END')
```
- 多了没有异常时，可以有`else`语句，如果有finally语句，最后也会执行
```python
try:
    print('try...')
    r = 10 / int('2')
    print('result:', r)
except ValueError as e:
    print('ValueError:', e)
except ZeroDivisionError as e:
    print('ZeroDivisionError:', e)
else:
    print('no error!')
finally:
    print('finally...')
print('END')
'''
try...
result: 5.0
no error!
finally...
END
'''
```
- 抛出异常 	`raise`
	> 错误并不是凭空产生的，而是有意创建并抛出的
	> 如果要抛出错误，首先根据需要，可以定义一个错误的class，选择好继承关系，然后，用raise语句抛出
	```python
	class FooError(ValueError):
    	pass

	def foo(s):
		n = int(s)
		if n==0:
			raise FooError('invalid value: %s' % s)
		return 10 / n

	foo('0')
	```
- 使用异常的好处
	> 可以跨越多层调用，比如函数main()调用bar()，bar()调用foo()，结果foo()出错了，这时，只要main()捕获到了
- 调用栈
	> 如果错误没有被捕获，它就会一直往上抛，最后被Python解释器捕获，打印一个错误信息
- 接受异常并抛出
	- 捕获错误目的只是记录一下，便于后续追踪。但是，由于当前函数不知道应该怎么处理该错误，所以，最恰当的方式是继续往上抛，让顶层调用者去处理
	```python
	def foo(s):
    n = int(s)
    if n==0:
        raise ValueError('invalid value: %s' % s)
    return 10 / n

	def bar():
		try:
			foo('0')
		except ValueError as e:
			print('ValueError!')
			raise

	bar()
	```
#### 调试
- 日志
	- import logging
	```python
	logging.basicConfig(level=logging.INFO) # debug，info，warning，error
	logging.info('n = %d' % n)
	```
- 断言
	- assert 如 `assert n != 0, 'n is zero!'`
	- 断言的开关“-O”是英文大写字母O，不是数字0 `$ python -O err.py`
- pdb 调试器类似 gdb
	> python3 -m pdb multiprocessiong_demo.py
	> 代码中设置断点 pdb.set_trace()
	```python
	import pdb
	s = '0'
	n = int(s)
	pdb.set_trace() # 运行到这里会自动暂停
	print(10 / n)
	```
#### 单元测试 unittest
- 为了编写单元测试，我们需要引入Python自带的unittest模块`import unittest`
- 自己编写一个继承`unittest.TestCase`的类
	> 类中以`test`开头的方法才会被测试`def test_hello():`
	> `setUp`与`tearDown`方法会分别在每调用一个测试方法的前后分别被执行，如数据库的连接、关闭
	> `unittest.TestCase`提供了很多内置的条件判断，可以帮助判断输出是否满足
		> `assertEqual()` 断言输出是否是我们所期望的
		> `with self.assertRaises(KeyError):value = d['empty']` 期待抛出指定类型的Error
#### 文档测试
- `Python内置的`“文档测试”（doctest）模块可以直接提取注释中的代码并执行测试
- `doctest严格`按照Python交互式命令行的输入和输出来判断测试结果是否正确.只有测试异常的时候，可以用`...`表示中间一大段烦人的输出。
```python
# mydict2.py
class Dict(dict):
    '''
    Simple dict but also support access as x.y style.

    >>> d1 = Dict()
    >>> d1['x'] = 100
    >>> d1.x
    100
    >>> d1.y = 200
    >>> d1['y']
    200
    >>> d2 = Dict(a=1, b=2, c='3')
    >>> d2.c
    '3'
    >>> d2['empty']
    Traceback (most recent call last):
        ...
    KeyError: 'empty'
    >>> d2.empty
    Traceback (most recent call last):
        ...
    AttributeError: 'Dict' object has no attribute 'empty'
    '''
    def __init__(self, **kw):
        super(Dict, self).__init__(**kw)

    def __getattr__(self, key):
        try:
            return self[key]
        except KeyError:
            raise AttributeError(r"'Dict' object has no attribute '%s'" % key)

    def __setattr__(self, key, value):
        self[key] = value

if __name__=='__main__':
    import doctest
    doctest.testmod()
```
### IO编程
#### 文件读写
- 读文件
	> 打开文件`f = open('/Users/michael/test.txt', 'r')`
	> 打开二进制文件`f = open('/Users/michael/test.txt', 'rb')`
	> 打开特定字符文件`f = open('/Users/michael/gbk.txt', 'r', encoding='gbk')`
		> 读文件全部内容`f.read()`
		> f.read(size) 每次最多读取size个字节的内容
		> f.readline() 每次读取一行内容
		> f.readlines() 次读取所有内容并按行返回list
	> 一旦出错，后面的f.close()就不会调用,使用try ... finally来解决这个问题，或者with语句自动帮我们调用close()方法
	```python
	try:
    	f = open('/path/to/file', 'r')
    	print(f.read())
	finally:
		if f:
			f.close()
	
	#with 语句
	with open('/path/to/file', 'r') as f:
    print(f.read())
	```
	> `IOError`
	> file-like Object
		> 像open()函数返回的这种有个read()方法的对象，在Python中统称为file-like Object
- 写文件
	> 写文件和读文件是一样的，唯一区别是调用open()函数时，传入标识符'w'或者'wb'表示写文本文件或写二进制文件，以及encoding参数
	- 可以配合with语句
#### StringIO和BytesIO
- `from io import StringIO`
	- f = StringIO()
	- f.write('hello')
	- f.getvalue() getvalue()方法用于获得写入后的str。
- 要读取StringIO，可以用一个str初始化StringIO，然后，像读文件一样读取，无需open
```python
f = StringIO('Hello!\nHi!\nGoodbye!')
while True:
	s = f.readline()
	if s == '':
		break
```
- BytesIO 操作二进制数据，就需要使用BytesIO
	> BytesIO实现了在内存中读写bytes，我们创建一个BytesIO，然后写入一些bytes
	> StringIO类似，可以用一个bytes初始化BytesIO，然后，像读文件一样读取
#### 操作文件和目录
- os模块的某些函数是跟操作系统相关
	> uname()函数在Windows上不提供
- `os.environ`在操作系统中定义的环境变量
- `os.path`操作文件和目录的函数
	> 查看当前目录的绝对路径`os.path.abspath('.')`
	> 在某个目录下创建一个新目录
	```python
	os.path.join('/Users/michael', 'testdir') #可以正确处理不同操作系统的路径分隔符
	os.mkdir('/Users/michael/testdir') #创建一个目录
	os.rmdir('/Users/michael/testdir') #删掉一个目录
	```
- `os.rename('test.txt', 'test.py')`
- `os.remove('test.py')`
- `shutil模块`提供了`copyfile()`的函数，它们可以看做是os模块的补充。
#### 序列化
- `pickle`
	> pickle.dumps()方法把任意对象序列化成一个bytes，然后，就可以把这个bytes写入文件。
	> pickle.dump()直接把对象序列化后写入一个file-like Object
	```python
	import pickle
	d = dict(name='Bob', age=20, score=88)
	pickle.dumps(d)

	with open('dump.txt', 'wb') as f:
	pickle.dump(d, f)
	``` 
	> pickle.loads()方法反序列化出对象
	> pickle.load()方法从一个file-like Object中直接反序列化出对象
- JSON
	> import json
	> json.dumps(d) #d字典
	> json.loads(json_str)
	> json.dumps(s, default=student2dict) #把特定的对象序列化
### 进程和线程
#### 多进程
- Unix/Linux操作系统提供了一个`fork()`系统调用
	> 普通的函数调用，调用一次，返回一次，但是fork()调用一次，返回两次，因为操作系统自动把当前进程（称为父进程）复制了一份（称为子进程），然后，分别在父进程和子进程内返回
	> 子进程永远返回0，而父进程返回子进程的ID
	> 子进程只需要调用getppid()就可以拿到父进程的ID
- Python的os模块封装了常见的系统调用，其中就包括fork
```python
import os

print('Process (%s) start...' % os.getpid())
# Only works on Unix/Linux/Mac:
pid = os.fork()
if pid == 0:
    print('I am child process (%s) and my parent is %s.' % (os.getpid(), os.getppid()))
else:
    print('I (%s) just created a child process (%s).' % (os.getpid(), pid))
```
- `multiprocessing`模块，跨平台的多进程支持
```python
from multiprocessing import Process
import os

# 子进程要执行的代码
def run_proc(name):
    print('Run child process %s (%s)...' % (name, os.getpid()))

if __name__=='__main__':
    print('Parent process %s.' % os.getpid())
    p = Process(target=run_proc, args=('test',))
    print('Child process will start.')
    p.start()
    p.join()
    print('Child process end.')
```
##### Pool进程池
- 如果要启动大量的子进程，可以用进程池的方式批量创建子进程
```python
from multiprocessing import Pool
import os, time, random

def long_time_task(name):
    print('Run task %s (%s)...' % (name, os.getpid()))
    start = time.time()
    time.sleep(random.random() * 3)
    end = time.time()
    print('Task %s runs %0.2f seconds.' % (name, (end - start)))

if __name__=='__main__':
    print('Parent process %s.' % os.getpid())
    p = Pool(4)
    for i in range(5):
        p.apply_async(long_time_task, args=(i,))
    print('Waiting for all subprocesses done...')
    p.close()
    p.join()
    print('All subprocesses done.')
```
##### 子进程
- 很多时候，子进程并不是自身，而是一个外部进程
- `import subprocess`
```python
print('$ nslookup www.python.org')
r = subprocess.call(['nslookup', 'www.python.org'])
print('Exit code:', r)
```
##### 进程间通信
- multiprocessing模块包装了底层的机制，提供了Queue、Pipes等多种方式来交换数据
```python
if __name__=='__main__':
    # 父进程创建Queue，并传给各个子进程：
    q = Queue()
    pw = Process(target=write, args=(q,))
    pr = Process(target=read, args=(q,))
    # 启动子进程pw，写入:
    pw.start()
    # 启动子进程pr，读取:
    pr.start()
    # 等待pw结束:
    pw.join()
    # pr进程里是死循环，无法等待其结束，只能强行终止:
    pr.terminate()
```
#### 多线程
- `import threading`
- `t = threading.Thread(target=loop, name='LoopThread')`
- `t.start()` `t.join()`
##### Lock 
- lock = threading.Lock()
- lock.acquire()
- lock.release()
- Python解释器由于设计时有GIL全局锁，导致了多线程无法利用多核。多线程的并发在Python中就是一个美丽的梦。
##### ThreadLocal
- 根据线程找到对应的数据
```python
import threading
    
# 创建全局ThreadLocal对象:
local_school = threading.local()

def process_student():
    # 获取当前线程关联的student:
    std = local_school.student
    print('Hello, %s (in %s)' % (std, threading.current_thread().name))

def process_thread(name):
    # 绑定ThreadLocal的student:
    local_school.student = name
    process_student()

t1 = threading.Thread(target= process_thread, args=('Alice',), name='Thread-A')
t2 = threading.Thread(target= process_thread, args=('Bob',), name='Thread-B')
t1.start()
t2.start()
t1.join()
t2.join()
```
- ThreadLocal最常用的地方就是为每个线程绑定一个数据库连接，HTTP请求，用户身份信息等
#### 进程vs线程
- 多进程模式最大的优点就是稳定性高，因为一个子进程崩溃了，不会影响主进程和其他子进程
- 多进程模式的缺点是创建进程的代价大，在Unix/Linux系统下，用fork调用还行，在Windows下创建进程开销巨大。另外，操作系统能同时运行的进程数也是有限的，在内存和CPU的限制下，如果有几千个进程同时运行，操作系统连调度都会成问题。
- 多线程模式通常比多进程快一点
- 多线程模式致命的缺点就是任何一个线程挂掉都可能直接造成整个进程崩溃，因为所有线程共享进程的内存
- 用异步IO编程模型来实现多任务是一个主要的趋势，可以用单进程单线程模型来执行多任务，这种全新的模型称为事件驱动模型。
#### 分布式进程
- 在Thread和Process中，应当优选Process，因为Process更稳定，而且，Process可以分布到多台机器上，而Thread最多只能分布到同一台机器的多个CPU上。
- https://www.liaoxuefeng.com/wiki/1016959663602400/1017631559645600
### 常见模块
#### datetime
- datetime是模块，datetime模块还包含一个datetime类，通过from datetime import datetime导入的才是datetime这个类
- print(datetime.now()) # 获取当前datetime
```python
2020-11-10 17:11:53.944677
```
- timestamp
	> Python的timestamp是一个浮点数，整数位表示秒
	```python
	now = datetime.now()
	timestamp1 = now.timestamp()
	```
- timestamp转换为datetime
	> datetime.fromtimestamp(t)
- str转换为datetime
```python
cday = datetime.strptime('2015-6-1 18:19:59', '%Y-%m-%d %H:%M:%S')
```
- datetime转换为str
	> print(now.strftime('%a, %b %d %H:%M'))
- datetime加减
```python
from datetime import datetime, timedelta
now = datetime.now()
print(now)
print(now - timedelta(hours=1))
2020-11-11 09:24:41.983794
2020-11-11 08:24:41.983794
```
- 时区转换 datetime.replace(tzinfo=int(xxx))
```python 
def to_timestamp(dt_str, tz_str):
    #获取时区信息
    m = re.match(r'UTC([+|-]\d+):(\d+)', tz_str)
    hour = int(m.group(1))
    minu = int(m.group(2))
    #生成当前时间，并设置时区
    now = datetime.strptime(dt_str, '%Y-%m-%d %H:%M:%S')
    tz_info = timezone(timedelta(hours=hour, minutes=minu))
    x = now.replace(tzinfo=tz_info)
    return x.timestamp()
t1 = to_timestamp('2015-6-1 08:10:30', 'UTC+7:00')
assert t1 == 1433121030.0, t1

t2 = to_timestamp('2015-5-31 16:10:30', 'UTC-09:00')
assert t2 == 1433121030.0, t2
```
#### collection
- namedtuple
	> namedtuple是一个函数，它用来创建一个`自定义`的tuple对象，并且`规定了tuple元素的个数`，`并可以用属性而不是索引来引用tuple的某个元素`.
	```python
	from collections import namedtuple
	Point = namedtuple('Point', ['x', 'y']) #x,y是属性名，共两个
	p = Point(1, 2)
	p.x #1
	p.y #2
	```
- deque
	> deque是为了高效实现插入和删除操作的双向列表，适合用于队列和栈
	```python
	from collections import deque
	q = deque([1, 2, 3])
	print(q) #deque([1, 2, 3])
	q.append(4)
	print(q)#deque([1, 2, 3, 4])
	q.appendleft(0)
	print(q)#deque([0, 1, 2, 3, 4])
	```
- defaultdict
	> 使用dict时，如果引用的Key不存在，就会抛出KeyError.
	> 希望key不存在时，返回一个默认值，就可以用defaultdict
	```python
	from collections import defaultdict
	dd = defaultdict(lambda : 'N/A')
	dd['key1'] = 'abc'
	print(dd['key1']) #abc
	print(dd['key2']) #N/A
	```
- OrderedDict
	> 按插入顺序排列的字典
- ChainMap
	> ChainMap可以把一组dict串起来并组成一个逻辑上的dict。ChainMap本身也是一个dict，但是查找的时候，会按照顺序在内部的dict依次查找
	> 有优先级时，可以按顺序查找
- Counter
	> Counter是一个简单的计数器
	```python
	from collections import Counter
	c = Counter()
	for ch in 'programming':
		c[ch] = c[ch] + 1
	c.update('hello')
	```
