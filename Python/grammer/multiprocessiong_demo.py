"""
1，在unix系统下，python支持用fork()创建子进程
2，使用multiprocessing模块下的Process
"""

# way 1
"""
import os 
print('process (%s) start ' % os.getpid())
pid = os.fork()
if pid == 0:
    print('I am child process (%s) and my parent is %s' %
    (os.getpid(), os.getppid()))
else:
    print('I (%s) just created a child process (%s).' % (os.getpid(), pid))
"""

# way 2
from multiprocessing import Process
import time
import os 

# 子进程要执行的代码
def run_proc(name):
    for i in range(200):
        print("I am child process，i is %s" % i)
        #time.sleep(0.2)

if __name__=='__main__':
    print('Parent process %s.' % os.getpid())
    p = Process(target=run_proc, args=('test',))
    print('Child process will start.')
    p.start()
    for i in range(200):
        print("I am parent process，i is %s" % i)
        #time.sleep(0.2)
    print('Child process end.')