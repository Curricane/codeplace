"""
定制类
用于链式的处理把字符处理成想要的uri
"""
class Chain(object):
    def __init__(self, path=''):
        self._path = path
    def __getattr__(self, path):
        return Chain('%s/%s' % (self._path, path))
    def __str__(self):
        return self._path
    __repr__ = __str__
    def users(self, name):
        return Chain('%s/:%s' % (self._path, name))

ret = Chain().status.users("chenmc")
print(ret)