
def findLostNum(num):
    nlen = len(num)
    i = 1
    while i < nlen:
        nowN = num[i]
        if(i == nowN):
            i += 1
            continue
        elif nowN < nlen:
            